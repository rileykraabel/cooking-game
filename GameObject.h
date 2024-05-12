#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <QPicture>
#include <QGraphicsPixmapItem>
#include <objectName.h>

/*!
 * \brief The GameObject class is used for userData in a b2Body. Stores the picture associated with it and the type of object.
 * \authors Ethan Collier, Haidan Nelson, Riley Kraabel, Victoria Locke, Samantha Roberts, Jack Larson for CS 3505 A9.
 */
struct GameObject
{
    /*!
     * \brief picture: QGraphicsPixmapItem type object - The picture of the object.
     */
    QGraphicsPixmapItem* picture;

    /*!
     * \brief name: ObjectName type object - The name of the object.
     */
    ObjectName name;
};

#endif // GAMEOBJECT_H
