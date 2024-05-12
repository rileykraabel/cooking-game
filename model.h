#ifndef MODEL_H
#define MODEL_H

#include <Box2D/Box2D.h>
#include <objectName.h>
#include "GameObject.h"
#include "congratulationspopup.h"

/*!
 * \brief The Model class handles all the logic that should happen as a result of actions done by the player in the game world.
 * \authors Ethan Collier, Haidan Nelson, Riley Kraabel, Victoria Locke, Samantha Roberts, Jack Larson for CS 3505 A9.
 */
class Model
{
public:
    /*!
     * \brief Model - The Constructor for an instance of the Model Class.
     * \param congratulations: CongratulationsPopUp type object - the congratulations popUp to show once recipe is completed.
     */
    Model(CongratulationsPopUp* congratulations);

    /*!
     * \brief createObject - Method to create a new object, used when combining objects for steps throughout the recipe.
     * \param name: ObjectName type object - the name of the object to create.
     * \param filePath: QString type object - the filePath of the new item's image.
     * \return - GameObject type object - The newly created object.
     */
    static GameObject* createObject(ObjectName name, QString filePath);

    /*!
     * \brief showCongratulations - Method to show the CongratulationsPopUp window.
     */
    void showCongratulations();

    /*!
     * \brief congratsPopUp - The instance of the CongratulationsPopUp type.
     */
    CongratulationsPopUp* congratsPopUp;

    /*!
     * \brief selected - RecipeName type object - the currently selected recipe.
     */
    RecipeName selected;
};

#endif // MODEL_H
