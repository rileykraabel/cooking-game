#include <box2d/box2d.h>
#include <QApplication>
#include <QWidget>
#include <QTimer>
#include <QPainter>
#include <QMouseEvent>
#include <QDebug>
#include <box2dwidget.h>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <mouseintersectcallback.h>
#include "collisioncallback.h"
#include "GameObject.h"
#include <model.h>

Box2DWidget::Box2DWidget(QWidget* parent, Model* model) : QGraphicsView(parent), grabbedBody(nullptr), model(model)
{
    // Initialize the Box2D world with a gravity
    b2Vec2 gravity(0.0f, 10.0f);
    world = new b2World(gravity);

    background.load(QString(":/images/dormRoom.jpeg"));

    // Set the collision callback to listen for collisions between items and have custom functions run via model.cpp
    callback = new collisionCallback(model);
    world->SetContactListener(callback);

    // Set the scene for the QGraphicsWidget
    scene = new QGraphicsScene(this);
    setScene(scene);

    setupWorld();
    startSimulation();
}

void Box2DWidget::setModel(Model* model)
{
    this->model     = model;
    callback->model = model;
}

void Box2DWidget::startSimulation()
{
    // Setup the simulation loop
    QTimer* timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Box2DWidget::simulate);
    timer->start(16); // approx 60 fps
}

void Box2DWidget::setupWorld()
{
    // Load the background image
    QGraphicsPixmapItem* pixmapItem = new QGraphicsPixmapItem(background);
    this->setSceneRect(0, 0, background.width(), background.height());
    scene->addItem(pixmapItem);

    // Create ground
    b2BodyDef groundBodyDef;
    groundBodyDef.position.Set(0.0f, background.height() / scaleFactor);
    b2Body* groundBody = world->CreateBody(&groundBodyDef);

    // Create ground hitbox
    b2PolygonShape groundBox;
    groundBox.SetAsBox(background.width() / scaleFactor, 0.1f); //half-width, half-height
    groundBody->CreateFixture(&groundBox, 0.0f); //assign hitbox to the ground

    // Create desk
    b2BodyDef deskBodyDef;
    deskBodyDef.position.Set(10.0f, (background.height() / scaleFactor) - 14.0f);
    b2Body* deskBody = world->CreateBody(&deskBodyDef);

    // Create desk hitbox
    b2PolygonShape deskBox;
    deskBox.SetAsBox(20.3f, 0.1f); //half-width, half-height
    deskBody->CreateFixture(&deskBox, 0.0f); //assign hitbox to the ground

    // Create wall hitbox
    b2PolygonShape WallBodyShape;
    WallBodyShape.SetAsBox(0.1f, background.height() / scaleFactor); //half-width, half-height

    // Create left wall
    b2BodyDef leftWallBodyDef;
    leftWallBodyDef.position.Set(0.0f, background.height() / scaleFactor);
    b2Body* leftWallBody = world->CreateBody(&groundBodyDef);
    leftWallBody->CreateFixture(&WallBodyShape, 0.0f);

    // Create right wall
    b2BodyDef rightWallBodyDef;
    rightWallBodyDef.position.Set(background.width() / scaleFactor, background.height() / scaleFactor);
    b2Body* rightWallBody = world->CreateBody(&rightWallBodyDef);
    rightWallBody->CreateFixture(&WallBodyShape, 0.0f);

    // Create desk wall hitbox
    b2PolygonShape DeskBodyShape;
    DeskBodyShape.SetAsBox(30.3f, (background.height() / scaleFactor) - 20.8f);

    // Create desk wall
    b2BodyDef deskWallBodyDef;
    deskWallBodyDef.position.Set(0.0f, background.height() / scaleFactor);
    b2Body* deskWallBody = world->CreateBody(&deskWallBodyDef);
    deskWallBody->CreateFixture(&DeskBodyShape, 0.0f);

    // Create plant
    GameObject* plantObject = Model::createObject(ObjectName::plant, QString(":/images/plant.png"));
    b2Body* plantBody = addBody(plantObject, QPoint(background.width() - (background.width() / 3.9), background.height() - (plantObject->picture->pixmap().height() / 2)));
    plantBody->SetType(b2_staticBody);

    // Create plant
    GameObject* microwaveObject = Model::createObject(ObjectName::microwave, QString(":/images/microwave.png"));
    b2Body* microwaveBody = addBody(microwaveObject, QPoint(microwaveObject->picture->pixmap().width() / 2, background.height() / 2));
    microwaveBody->SetType(b2_staticBody);
}

Box2DWidget::~Box2DWidget()
{
    delete scene;
    delete world;
    delete callback;
}

b2Body* Box2DWidget::addBody(GameObject* object, QPoint spawnPosition)
{
    QPixmap image = object->picture->pixmap(); // Get the Pixmap from the QGraphicsPixmapItem so we can get sizes from it
    object->picture->setOffset(-image.width() / 2.0f, -image.height() / 2.0f);

    scene->addItem(object->picture);
    // Create body and set the position to the origin
    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    QPointF scaledSpawnPosition = mapToScene(spawnPosition);
    b2Vec2 spawnPositionVec(scaledSpawnPosition .x() / scaleFactor, scaledSpawnPosition .y() / scaleFactor);
    bodyDef.position.Set(background.width() / 2 / scaleFactor, -5.0f);
    b2Body* body = world->CreateBody(&bodyDef);

    // Set the hitbox of the body to be the shape of the the picture.
    b2PolygonShape dynamicBox;
    dynamicBox.SetAsBox((image.width() / 2.0f) / scaleFactor, (image.height() / 2.0f) / scaleFactor); // Scale factor -> 20 pixels is 1 meter
    b2FixtureDef fixtureDef; // the actual hitbox, shape comes from dynamic box
    fixtureDef.shape = &dynamicBox;
    fixtureDef.density = 1.0f;
    fixtureDef.friction = 0.3f;
    body->CreateFixture(&fixtureDef); // Assign the hitbox to the body
    body->SetUserData(object);

    body->SetTransform(spawnPositionVec, body->GetAngle());
    mousePosition = spawnPosition;
    grabbedBody = body;

    return body;
}

void Box2DWidget::simulate()
{
    float32 timeStep = 1.0f / 60.0f;
    int32 velocityIterations = 6;
    int32 positionIterations = 2;


    if (grabbedBody && QApplication::mouseButtons())
        dragBody(grabbedBody);
    else if (grabbedBody)
    {
        grabbedBody->SetLinearDamping(0.0f);
        grabbedBody = nullptr;
    }
    render();
    updateScene();
    removeObjects(callback->bodiesMarkedForDeletion);
    addBodies();
    world->Step(timeStep, velocityIterations, positionIterations);
}

void Box2DWidget::addBodies()
{
    for (const auto& body : callback->bodiesToAdd)
    {
        addBody(body.first, body.second);
    }
    callback->bodiesToAdd.clear();
}

void Box2DWidget::dragBody(b2Body* body)
{
    QPointF mouseScaled  = mapToScene(mapFromGlobal(QCursor::pos()));
    b2Vec2 mousePosition(mouseScaled.x() / scaleFactor, mouseScaled.y() / scaleFactor); // Scale factor converts Qt to box2D sizes
    b2Vec2 bodyPosition  = body->GetWorldCenter(); // The position of the center of the body in the world
    b2Vec2 directionVector = mousePosition - bodyPosition; // The direction the body will be moved in

    if (directionVector.LengthSquared() > 0.1f)
    {
        body->SetLinearDamping(10.0f);
        directionVector.x *= 100.0f;
        directionVector.y *= 100.0f;
        body->ApplyLinearImpulse(directionVector, mousePosition, true);
    }
    else
    {
        body->SetLinearVelocity(b2Vec2(0.0f, 0.0f));
        body->ApplyForce(body->GetMass() * -world->GetGravity(), body->GetWorldCenter(), true);
    }
}

void Box2DWidget::removeObjects(std::vector<b2Body*> bodies)
{
    for (auto& body : bodies)
    {
        GameObject* item = static_cast<GameObject*>(body->GetUserData());
        if (item)
        {
            scene->removeItem(item->picture);
            world->DestroyBody(body);
        }
    }
    callback->bodiesMarkedForDeletion.clear();
}

void Box2DWidget::resetWorld()
{
    for (b2Body* b = world->GetBodyList(); b; b = b->GetNext())
    {
        if (b->GetType() == b2_dynamicBody)
        {
            GameObject* object = static_cast<GameObject*>(b->GetUserData());
            if (object)
                scene->removeItem(object->picture);
            world->DestroyBody(b);
        }
    }
}

void Box2DWidget::updateScene()
{
    for (auto& item : callback->bodiesMarkedToChange)
    {
        GameObject* oldUserData = static_cast<GameObject*>(item.first->GetUserData());
        GameObject* newUserData = item.second;
        b2Body* oldBody = item.first;
        b2Body* newBody = addBody(newUserData);
        b2Vec2 currentPosition = item.first->GetPosition();

        if (oldUserData)
            scene->removeItem(oldUserData->picture);

        if (grabbedBody == oldBody)
            grabbedBody = newBody;

        world->DestroyBody(oldBody);
        newBody->SetTransform(currentPosition, newBody->GetAngle());
    }
    callback->bodiesMarkedToChange.clear();
}

void Box2DWidget::render()
{
    for (b2Body* b = world->GetBodyList(); b; b = b->GetNext())
    {
        GameObject* item = static_cast<GameObject*>(b->GetUserData());
        if (item)
        {
            QPoint bodyPosition(b->GetPosition().x * scaleFactor, b->GetPosition().y * scaleFactor);
            item->picture->setPos(bodyPosition);
            item->picture->setRotation((b->GetAngle() * 180.0 / b2_pi));
        }
    }
}

void Box2DWidget::mousePressEvent(QMouseEvent *event)
{
    mousePosition = event->pos();
    QPointF mousePosition = mapToScene(event->pos());
    b2Vec2 mouse(mousePosition.x() / scaleFactor, mousePosition.y() / scaleFactor);

    b2AABB aabb;
    aabb.lowerBound = mouse;
    aabb.upperBound = mouse;

    mouseIntersectCallback* callback = new mouseIntersectCallback(mouse);
    world->QueryAABB(callback, aabb);

    grabbedBody = callback->body;
}
