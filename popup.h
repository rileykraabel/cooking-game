#ifndef POPUP_H
#define POPUP_H

#include <QWidget>
#include "objectName.h"

using std::string;

namespace Ui { class PopUp; }
/*!
 * \brief The PopUp class handles any instances where there will be a PopUp widget.
 * \authors Ethan Collier, Haidan Nelson, Riley Kraabel, Victoria Locke, Samantha Roberts, Jack Larson for CS 3505 A9.
 */
class PopUp : public QWidget
{
    Q_OBJECT

public:
    /*!
     * \brief PopUp - Constructor method for the PopUp widget instances.
     * \param parent - QWidget type object - required to create an instance of PopUp.
     */
    explicit PopUp(QWidget *parent = nullptr);

    /*!
     * \brief ~PopUp - Destructor method for the PopUp widget instances.
     */
    ~PopUp();

private slots:
    /*!
     * \brief on_ramenRecipe_clicked - Method to handle when the user chooses a recipe.
     */
    void on_ramenRecipe_clicked();

    /*!
     * \brief on_potatoRecipe_clicked - Method to handle when the user chooses a recipe.
     */
    void on_potatoRecipe_clicked();

    /*!
     * \brief on_alfredoRecipe_clicked - Method to handle when the user chooses a recipe.
     */
    void on_alfredoRecipe_clicked();

    /*!
     * \brief on_nachosRecipe_clicked - Method to handle when the user chooses a recipe.
     */
    void on_nachosRecipe_clicked();

    /*!
     * \brief on_wrapRecipe_clicked - Method to handle when the user chooses a recipe.
     */
    void on_wrapRecipe_clicked();

    /*!
     * \brief on_quesadillaRecipe_clicked - Method to handle when the user chooses a recipe.
     */
    void on_quesadillaRecipe_clicked();

signals:
    /*!
     * \brief currentRecipe - Emits the currently chosen recipe to the rest of the game.
     * \param gameRecipe - RecipeName type object - the chosen recipe for the game.
     */
    void currentRecipe(RecipeName gameRecipe);

private:
    /*!
     * \brief PopUp - instance of the PopUp class.
     */
    Ui::PopUp *ui;
};

#endif // POPUP_H
