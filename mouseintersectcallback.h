#ifndef MOUSEINTERSECTCALLBACK_H
#define MOUSEINTERSECTCALLBACK_H
#include <Box2D/Box2D.h>

/*!
 * \brief The mouseIntersectCallback class is used to detect mouse collisions with objects.
 * \authors Ethan Collier, Haidan Nelson, Riley Kraabel, Victoria Locke, Samantha Roberts, Jack Larson for CS 3505 A9.
 */
class mouseIntersectCallback : public b2QueryCallback
{
public:
    /*!
     * \brief mouseIntersectCallback - Method to handle the callback to use in the QueryAABB function of Box2D.
     * \param b2Vect2 type object - The point to test against.
     */
    mouseIntersectCallback(const b2Vec2& point);

    /*!
     * \brief ReportFixture - Reports what fixture is currently being overlapped.
     * \param fixture: The fixture to test against.
     * \return - If the fixture is found, return true to stop the QueryAABB function. Otherwise, return false.
     */
    bool ReportFixture(b2Fixture* fixture) override;

    /*!
     * \brief point: b2Vec2 type object - The point to test against.
     */
    b2Vec2 point;

    /*!
     * \brief body: b2Body type object - The body that is being intersected.
     */
    b2Body* body;
};

#endif // MOUSEINTERSECTCALLBACK_H
