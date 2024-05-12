#ifndef CONGRATULATIONSPOPUP_H
#define CONGRATULATIONSPOPUP_H

#include <QWidget>

namespace Ui
{
/*!
 * \brief The CongratulationsPopup is a type of widget popup that appears once the user has correctly executed their chosen recipe.
 */
class CongratulationsPopUp;
}

/*!
 * \brief This is a popup that appears when the user correctly finishes a recipe.
 * \authors Ethan Collier, Haidan Nelson, Riley Kraabel, Victoria Locke, Samantha Roberts, Jack Larson for CS 3505 A9.
 */
class CongratulationsPopUp : public QWidget
{
    Q_OBJECT

public:
    /*!
     * \brief CongratulationsPopUp - Constructor method for the Congratulations Popup widget.
     * \param parent - QWidget type object - Inherits from QWidget.
     */
    explicit CongratulationsPopUp(QWidget *parent = nullptr);

    /*!
     * \brief ~CongratulationsPopUp - Destructor method for the Congratulations Popup widget.
     */
    ~CongratulationsPopUp();

private:
    /*!
     * \brief ui -  Congratulations Popup type object - The specific instance of the Popup.
     */
    Ui::CongratulationsPopUp *ui;
};

#endif // CONGRATULATIONSPOPUP_H
