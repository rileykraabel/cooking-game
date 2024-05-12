#include "model.h"
#include "GameObject.h"
#include <QDebug>

Model::Model(CongratulationsPopUp* congratulations) : congratsPopUp(congratulations) {}

GameObject* Model::createObject(ObjectName name, QString filePath)
{
    QGraphicsPixmapItem* image = new QGraphicsPixmapItem(QPixmap(filePath));
    GameObject* object = new GameObject();
    object->picture = image;
    object->name    = name;
    return object;
}

void Model::showCongratulations()
{
    congratsPopUp->show();
}
