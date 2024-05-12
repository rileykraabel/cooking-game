#include "mouseintersectcallback.h"

mouseIntersectCallback::mouseIntersectCallback(const b2Vec2& point)
{
    this->point = point;
    this->body = nullptr;
}

bool mouseIntersectCallback::ReportFixture(b2Fixture* fixture)
{
    b2Body* body = fixture->GetBody();
    if (body->GetType() == b2_staticBody)
    {
        this->body = nullptr;
        return false;
    }
    if (body->GetType() == b2_dynamicBody && fixture->TestPoint(point))
    {
        this->body = body;
        return false;
    }
    return true;
}
