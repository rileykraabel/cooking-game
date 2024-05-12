#ifndef COLLISIONCALLBACK_H
#define COLLISIONCALLBACK_H

#include <Box2D/Box2D.h>
#include <GameObject.h>
#include <model.h>

using std::vector;
using std::string;
using std::vector;
using std::map;

/*!
 * \brief The collisionCallback class inherits from a b2ContactListener and specifies specific actions to happen as a result of collisions between game objects
 *      passed into a b2World in the box2Dwidget class.
 * \authors Ethan Collier, Haidan Nelson, Riley Kraabel, Victoria Locke, Samantha Roberts, Jack Larson for CS 3505 A9.
 */
class collisionCallback : public b2ContactListener
{
public:
    /*!
     * \brief collisionCallback: Default constructor.
     * \param Model type object - Represents the current recipe.
     */
    collisionCallback(Model* model);

    /*!
     * \brief BeginContact: Called by Box2D whenever a collision between two bodies happens.
     * \param contact: b2Contact type object - The contact stores the fixtures that are contacting.
     */
    void BeginContact(b2Contact* contact) override;

/* -- methods to handle user recipe choices -- */
    /*!
     * \brief handleRamenRecipe - Method to handle the case where the user has chosen to make the Ramen recipe.
     * \param dataA: ObjectName type object - the first object being collided with.
     * \param dataB: ObjectName type object - the second object being collided with.
     * \param contact - b2Contact type object - the instance where the items are colliding.
     * \return - GameObject type object - a new Object representing the two items collided.
     */
    GameObject* handleRamenRecipe(ObjectName dataA, ObjectName dataB, b2Contact* contact);

    /*!
     * \brief handleAlfredoRecipe - Method to handle the case where the user has chosen to make the Alfredo recipe.
     * \param dataA: ObjectName type object - the first object being collided with.
     * \param dataB: ObjectName type object - the second object being collided with.
     * \param contact - b2Contact type object - the instance where the items are colliding.
     * \return - GameObject type object - a new Object representing the two items collided.
     */
    GameObject* handleAlfredoRecipe(ObjectName dataA, ObjectName dataB, b2Contact* contact);

    /*!
     * \brief handleQuesadilla - Method to handle the case where the user has chosen to make the Quesadilla recipe.
     * \param dataA: ObjectName type object - the first object being collided with.
     * \param dataB: ObjectName type object - the second object being collided with.
     * \param contact - b2Contact type object - the instance where the items are colliding.
     * \return - GameObject type object - a new Object representing the two items collided.
     */
    GameObject* handleQuesadilla(ObjectName dataA, ObjectName dataB, b2Contact* contact);

    /*!
     * \brief handleBakedPotato - Method to handle the case where the user has chosen to make the Baked Potato recipe.
     * \param dataA: ObjectName type object - the first object being collided with.
     * \param dataB: ObjectName type object - the second object being collided with.
     * \param contact - b2Contact type object - the instance where the items are colliding.
     * \return - GameObject type object - a new Object representing the two items collided.
     */
    GameObject* handleBakedPotato(ObjectName dataA, ObjectName dataB, b2Contact* contact);

    /*!
     * \brief handleWrap - Method to handle the case where the user has chosen to make the Wrap recipe.
     * \param dataA: ObjectName type object - the first object being collided with.
     * \param dataB: ObjectName type object - the second object being collided with.
     * \return - GameObject type object - a new Object representing the two items collided.
     */
    GameObject* handleWrap(ObjectName dataA, ObjectName data);

    /*!
     * \brief handleNachos - Method to handle the case where the user has chosen to make the Nachos recipe.
     * \param dataA: ObjectName type object - the first object being collided with.
     * \param dataB: ObjectName type object - the second object being collided with.
     * \param contact - b2Contact type object - the instance where the items are colliding.
     * \return - GameObject type object - a new Object representing the two items collided.
     */
    GameObject* handleNachos(ObjectName dataA, ObjectName dataB, b2Contact* contact);

    /*!
     * \brief bodiesMarkedForDeletion: vector of b2Body objects - Bodies that should be deleted as a result of a collision. Deletion is handled in Box2DWidget.
     */
    vector<b2Body*> bodiesMarkedForDeletion;

    /*!
     * \brief bodiesToAdd: map of GameObjects as keys and QPoint objects as values - The box2Dworld will add these bodies when it is safe to do so at the point.
     */
    map<GameObject*, QPoint> bodiesToAdd;

    /*!
     * \brief bodiesChanged: map of b2Body objects as keys and GameObject objects as values - Add to this when changing a body.
     *      The key is the body to change and the value is the new data associated with the body.
     */
    map<b2Body*, GameObject*> bodiesMarkedToChange;

    /*!
     * \brief model: The model of the gameWorld.
     */
    Model* model;;
};

#endif // COLLISIONCALLBACK_H
