#include "collisioncallback.h"
#include <QDebug>
#include "GameObject.h"
#include "model.h"
#include <iostream>
#include "QTimer"

using std::string;

collisionCallback::collisionCallback(Model* model) : model(model) {}

void collisionCallback::BeginContact(b2Contact* contact)
{
    void* bodyUserDataA = contact->GetFixtureA()->GetBody()->GetUserData();
    void* bodyUserDataB = contact->GetFixtureB()->GetBody()->GetUserData();

    if (bodyUserDataA == nullptr || bodyUserDataB == nullptr)
        return;

    ObjectName dataA = static_cast<GameObject*>(bodyUserDataA)->name;
    ObjectName dataB = static_cast<GameObject*>(bodyUserDataB)->name;
    GameObject* object = nullptr;

    if (model->selected == RecipeName::alfredo)
        object = this->handleAlfredoRecipe(dataA, dataB, contact);

    else if (model->selected==RecipeName::ramen)
        object = this->handleRamenRecipe(dataA, dataB, contact);

    else if (model->selected==RecipeName::quesadilla)
        object = this->handleQuesadilla(dataA, dataB, contact);

    else if (model->selected==RecipeName::bakedPotato)
        object = this->handleBakedPotato(dataA, dataB, contact);

    else if (model->selected==RecipeName::wrap)
        object = this->handleWrap(dataA, dataB);

    else if (model->selected==RecipeName::nachos)
        object = this->handleNachos(dataA, dataB, contact);

    if (!(dataA == ObjectName::microwave || dataA == ObjectName::plant || dataB == ObjectName::microwave || dataB == ObjectName::plant || object == nullptr))
    {
        bodiesMarkedToChange[contact->GetFixtureA()->GetBody()] = object;
        bodiesMarkedForDeletion.push_back(contact->GetFixtureB()->GetBody());
    }
}

GameObject* collisionCallback::handleAlfredoRecipe(ObjectName dataA, ObjectName dataB, b2Contact* contact)
{
    if ((dataA == ObjectName::bowl && dataB == ObjectName::water) || (dataB == ObjectName::water && dataA == ObjectName::bowl))
        return Model::createObject(ObjectName::bowlWater, QString(":/images/bowlWater.png"));
    if ((dataA == ObjectName::bowlWater && dataB == ObjectName::noodles) || (dataB == ObjectName::bowlWater && dataA == ObjectName::noodles))
        return Model::createObject(ObjectName::bowlWaterNoodles, QString(":/images/waterBowlRawPasta.png"));
    if ((dataA == ObjectName::bowlWaterNoodles && dataB == ObjectName::microwave) || (dataB == ObjectName::bowlWaterNoodles && dataA == ObjectName::microwave))
    {
        GameObject* object = Model::createObject(ObjectName::bowlWaterCookedNoodles, QString(":/images/bowlWaterCookedNoodles.png"));
        if (dataA == ObjectName::bowlWaterNoodles)
        {
            b2Vec2 pos = contact->GetFixtureA()->GetBody()->GetWorldCenter();
            QPoint spawnPoint(pos.x * 20, pos.y * 20);

            bodiesMarkedForDeletion.push_back(contact->GetFixtureA()->GetBody());
            QTimer::singleShot(1500, [=]() {bodiesToAdd[object] = spawnPoint;});
        }
        else
        {
            b2Vec2 pos = contact->GetFixtureB()->GetBody()->GetWorldCenter();
            QPoint spawnPoint(pos.x * 20, pos.y * 20);

            bodiesMarkedForDeletion.push_back(contact->GetFixtureB()->GetBody());
            QTimer::singleShot(1500, [=]() {bodiesToAdd[object] = spawnPoint;});
        }
        return object;
    }
    if ((dataA == ObjectName::plant && dataB == ObjectName::bowlWaterCookedNoodles) || (dataB == ObjectName::plant && dataA == ObjectName::bowlWaterCookedNoodles))
    {
        GameObject* object = Model::createObject(ObjectName::bowlCookedPasta, QString(":/images/bowlCookedPasta.png"));
        if (dataA == ObjectName::bowlWaterNoodles)
            bodiesMarkedToChange[contact->GetFixtureA()->GetBody()] = object;
        else
            bodiesMarkedToChange[contact->GetFixtureB()->GetBody()] = object;
        return object;
    }
    if ((dataA == ObjectName::bowlCookedPasta && dataB == ObjectName::sauce) || (dataA == ObjectName::sauce && dataB == ObjectName::bowlCookedPasta))
        return Model::createObject(ObjectName::bowlCookedPastaAlfredo, QString(":/images/bowlCookedPastaAlfredo.png"));
    if ((dataA == ObjectName::bowlCookedPastaAlfredo && dataB == ObjectName::chicken) || (dataB == ObjectName::chicken && dataA == ObjectName::bowlCookedPastaAlfredo))
    {
        QTimer::singleShot(3000, [=]() {model->showCongratulations(); });
        return Model::createObject(ObjectName::finalAlfredo, QString(":/images/finalAlfredo.png"));
    }
    return nullptr;
}

GameObject* collisionCallback::handleRamenRecipe(ObjectName dataA, ObjectName dataB, b2Contact* contact)
{

    if ((dataA == ObjectName::bowl && dataB == ObjectName::water) || (dataB == ObjectName::bowl && dataA == ObjectName::water))
        return Model::createObject(ObjectName::bowlWater, QString(":/images/bowlWater.png"));
    else if ((dataA == ObjectName::bowlWater && dataB == ObjectName::ramenPacket) || (dataB == ObjectName::bowlWater && dataA == ObjectName::ramenPacket))
        return Model::createObject(ObjectName::bowlWaterRamenNoodles, QString(":/images/waterBowlRawPasta.png"));
    else if ((dataA == ObjectName::bowlWaterRamenNoodles && dataB == ObjectName::microwave) || (dataB == ObjectName::bowlWaterRamenNoodles && dataA == ObjectName::microwave))
    {
        GameObject* object = Model::createObject(ObjectName::bowlWaterRamenNoodlesCooked, QString(":/images/bowlWaterCookedNoodles.png"));
        if (dataA == ObjectName::bowlWaterRamenNoodles)
        {
            b2Vec2 pos = contact->GetFixtureA()->GetBody()->GetWorldCenter();
            QPoint spawnPoint(pos.x * 20, pos.y * 20);

            bodiesMarkedForDeletion.push_back(contact->GetFixtureA()->GetBody());
            QTimer::singleShot(1500, [=]() {bodiesToAdd[object] = spawnPoint;});
        }
        else
        {
            b2Vec2 pos = contact->GetFixtureB()->GetBody()->GetWorldCenter();
            QPoint spawnPoint(pos.x * 20, pos.y * 20);

            bodiesMarkedForDeletion.push_back(contact->GetFixtureB()->GetBody());
            QTimer::singleShot(1500, [=]() {bodiesToAdd[object] = spawnPoint;});
        }
        return object;
    }
    else if ((dataA == ObjectName::plant && dataB == ObjectName::bowlWaterRamenNoodlesCooked) || (dataB == ObjectName::plant && dataA == ObjectName::bowlWaterRamenNoodlesCooked))
    {
        GameObject* object = Model::createObject(ObjectName::bowlCookedPasta, QString(":/images/bowlCookedPasta.png"));
        if (dataA == ObjectName::bowlWaterRamenNoodlesCooked)
            bodiesMarkedToChange[contact->GetFixtureA()->GetBody()] = object;
        else
            bodiesMarkedToChange[contact->GetFixtureB()->GetBody()] = object;
        return object;
    }
    else if ((dataA == ObjectName::bowlCookedPasta && dataB == ObjectName::oil) || (dataB == ObjectName::bowlCookedPasta && dataA == ObjectName::oil))
    {
        QTimer::singleShot(3000, [=]() {model->showCongratulations(); });
        return Model::createObject(ObjectName::finalRamen, QString(":/images/finalRamen.png"));
    }
    return nullptr;
}

GameObject* collisionCallback::handleQuesadilla(ObjectName dataA, ObjectName dataB, b2Contact* contact)
{
    if ((dataA == ObjectName::plate && dataB == ObjectName::tortillas) || (dataA == ObjectName::tortillas && dataB == ObjectName::plate))
        return Model::createObject(ObjectName::plateTortilla, QString(":/images/plateTortilla.png"));
    else if ((dataA == ObjectName::plateTortilla && dataB == ObjectName::cheese) || (dataA == ObjectName::cheese && dataB == ObjectName::plateTortilla))
        return Model::createObject(ObjectName::plateTortillaCheese, QString(":/images/plateTortillaCheese.png"));
    else if ((dataA == ObjectName::plateTortillaCheese && dataB == ObjectName::chicken) || (dataA == ObjectName::chicken && dataB == ObjectName::plateTortillaCheese))
        return Model::createObject(ObjectName::plateTortillaCheeseChicken, QString(":/images/plateTortillaCheeseChicken.png"));
    else if ((dataA == ObjectName::plateTortillaCheeseChicken && dataB == ObjectName::tortillas) || (dataA == ObjectName::tortillas && dataB == ObjectName::plateTortillaCheeseChicken))
        return Model::createObject(ObjectName::plateTortillaCheeseChickenTortilla, QString(":/images/plateTortillaCheeseChickenTortilla.png"));
    else if ((dataA == ObjectName::plateTortillaCheeseChickenTortilla && dataB == ObjectName::microwave) || (dataB == ObjectName::plateTortillaCheeseChickenTortilla && dataA == ObjectName::microwave))
    {
        GameObject* object = Model::createObject(ObjectName::plateCookedTortillaCheeseChickenTortilla, QString(":/images/plateTortillaCheeseChickenTortilla.png"));

        if (dataA == ObjectName::plateTortillaCheeseChickenTortilla)
        {
            b2Vec2 pos = contact->GetFixtureA()->GetBody()->GetWorldCenter();
            QPoint spawnPoint(pos.x * 20, pos.y * 20);

            bodiesMarkedForDeletion.push_back(contact->GetFixtureA()->GetBody());
            QTimer::singleShot(1500, [=]() {bodiesToAdd[object] = spawnPoint;});
        }
        else
        {
            b2Vec2 pos = contact->GetFixtureB()->GetBody()->GetWorldCenter();
            QPoint spawnPoint(pos.x * 20, pos.y * 20);

            bodiesMarkedForDeletion.push_back(contact->GetFixtureB()->GetBody());
            QTimer::singleShot(1500, [=]() {bodiesToAdd[object] = spawnPoint;});
        }
        return object;
    }
    else if ((dataA == ObjectName::plateCookedTortillaCheeseChickenTortilla && dataB == ObjectName::sourCream) || (dataA == ObjectName::sourCream && dataB == ObjectName::plateCookedTortillaCheeseChickenTortilla))
    {
        QTimer::singleShot(3000, [=]() {model->showCongratulations(); });
        return Model::createObject(ObjectName::tortillaMayoLettuce, QString(":/images/finalQuesadilla.png"));
    }
    return nullptr;
}

GameObject* collisionCallback::handleBakedPotato(ObjectName dataA, ObjectName dataB, b2Contact* contact)
{
    if ((dataA == ObjectName::plate && dataB == ObjectName::rawPotato) || (dataB == ObjectName::rawPotato && dataA == ObjectName::plate))
        return Model::createObject(ObjectName::platePotato, QString(":/images/platePotato.png"));
    else if ((dataA == ObjectName::platePotato && dataB == ObjectName::microwave) || (dataB == ObjectName::platePotato && dataA == ObjectName::microwave))
    {
        GameObject* object = Model::createObject(ObjectName::plateCookedPotato, QString(":/images/platePotato.png"));
        if (dataA == ObjectName::platePotato)
        {
            b2Vec2 pos = contact->GetFixtureA()->GetBody()->GetWorldCenter();
            QPoint spawnPoint(pos.x * 20, pos.y * 20);

            bodiesMarkedForDeletion.push_back(contact->GetFixtureA()->GetBody());
            QTimer::singleShot(1500, [=]() {bodiesToAdd[object] = spawnPoint;});
        }
        else
        {
            b2Vec2 pos = contact->GetFixtureB()->GetBody()->GetWorldCenter();
            QPoint spawnPoint(pos.x * 20, pos.y * 20);

            bodiesMarkedForDeletion.push_back(contact->GetFixtureB()->GetBody());
            QTimer::singleShot(1500, [=]() {bodiesToAdd[object] = spawnPoint;});
        }
    }
    else if ((dataA == ObjectName::plateCookedPotato && dataB == ObjectName::cheese) || (dataA == ObjectName::cheese && dataB == ObjectName::plateCookedPotato))
        return Model::createObject(ObjectName::platePotatoCheese, QString(":/images/platePotatoCheese.png"));
    else if ((dataA == ObjectName::platePotatoCheese && dataB == ObjectName::sourCream) || (dataA == ObjectName::sourCream && dataB == ObjectName::platePotatoCheese))
    {
        QTimer::singleShot(3000, [=]() {model->showCongratulations(); });
        return Model::createObject(ObjectName::finalPotato, QString(":/images/platePotatoCheeseSourCream.png"));
    }
    return nullptr;
}

GameObject* collisionCallback::handleWrap(ObjectName dataA, ObjectName dataB)
{
    if ((dataA == ObjectName::plate && dataB == ObjectName::tortillas) || (dataA == ObjectName::tortillas && dataB == ObjectName::plate))
        return Model::createObject(ObjectName::plateTortilla, QString(":/images/plateTortilla.png"));
    else if ((dataA == ObjectName::plateTortilla && dataB == ObjectName::mayonaise) || (dataA == ObjectName::mayonaise && dataB == ObjectName::plateTortilla))
        return Model::createObject(ObjectName::plateTortillaMayo, QString(":/images/plateTortillaMayo.png"));
    else if ((dataA == ObjectName::plateTortillaMayo && dataB == ObjectName::lettuce) || (dataA == ObjectName::lettuce && dataB == ObjectName::plateTortillaMayo))
        return Model::createObject(ObjectName::plateTortillaMayoLettuce, QString(":/images/plateTortillaMayoLettuce.png"));
    else if ((dataA == ObjectName::plateTortillaMayoLettuce && dataB == ObjectName::chicken) || (dataA == ObjectName::chicken && dataB == ObjectName::plateTortillaMayoLettuce))
    {
        QTimer::singleShot(3000, [=]() {model->showCongratulations(); });
        return Model::createObject(ObjectName::finalWrap, QString(":/images/finalWrap.png"));
    }
    return nullptr;
}

GameObject* collisionCallback::handleNachos(ObjectName dataA, ObjectName dataB, b2Contact* contact)
{
    if ((dataA == ObjectName::plate && dataB == ObjectName::chips) || (dataA == ObjectName::chips && dataB == ObjectName::plate))
        return Model::createObject(ObjectName::plateChips, QString(":/images/plateChips.png"));
    if ((dataA == ObjectName::plateChips && dataB == ObjectName::cheese) || (dataA == ObjectName::cheese && dataB == ObjectName::plateChips))
        return Model::createObject(ObjectName::plateChipsCheese, QString(":/images/plateChipsCheese.png"));
    if ((dataA == ObjectName::plateChipsCheese && dataB == ObjectName::microwave) || (dataB == ObjectName::plateChipsCheese && dataA == ObjectName::microwave))
    {
        GameObject* object = Model::createObject(ObjectName::plateCookedChipsCheese, QString(":/images/plateChipsCheese.png"));
        if (dataA == ObjectName::plateChipsCheese)
        {
            b2Vec2 pos = contact->GetFixtureA()->GetBody()->GetWorldCenter();
            QPoint spawnPoint(pos.x * 20, pos.y * 20);

            bodiesMarkedForDeletion.push_back(contact->GetFixtureA()->GetBody());
            QTimer::singleShot(1500, [=]() {bodiesToAdd[object] = spawnPoint;});
        }
        else
        {
            b2Vec2 pos = contact->GetFixtureB()->GetBody()->GetWorldCenter();
            QPoint spawnPoint(pos.x * 20, pos.y * 20);

            bodiesMarkedForDeletion.push_back(contact->GetFixtureB()->GetBody());
            QTimer::singleShot(1500, [=]() {bodiesToAdd[object] = spawnPoint;});
        }
        return object;
    }
    if ((dataA == ObjectName::plateCookedChipsCheese && dataB == ObjectName::salsa) || (dataA == ObjectName::salsa && dataB == ObjectName::plateCookedChipsCheese))
        return Model::createObject(ObjectName::plateChipsCheeseSalsa, QString(":/images/plateChipsCheeseSalsa.png"));
    if ((dataA == ObjectName::plateChipsCheeseSalsa && dataB == ObjectName::sourCream) || (dataA == ObjectName::sourCream && dataB == ObjectName::plateChipsCheeseSalsa))
    {
        QTimer::singleShot(3000, [=]() {model->showCongratulations(); });
        return Model::createObject(ObjectName::finalNachos, QString(":/images/finalNacho.png"));
    }
    return nullptr;
}
