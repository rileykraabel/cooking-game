#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "popup.h"
#include "model.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

/*!
 * \brief The MainWindow class is the overarching window for the background of the game.
 * \authors Ethan Collier, Haidan Nelson, Riley Kraabel, Victoria Locke, Samantha Roberts, Jack Larson for CS 3505 A9.
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /*!
     * \brief MainWindow - The Constructor for an instance of the MainWindow.
     * \param parent - QWidget type object - the MainWindow requires a QWidget object to execute.
     */
    MainWindow(QWidget *parent = nullptr);

    /*!
     * \brief ~MainWindow - The Destructor for an instance of the MainWindow.
     */
    ~MainWindow();

    /*!
     * \brief connectRecipes - This method connects the currently chosen recipe to the phone to display the correct recipe instructions.
     */
    void connectRecipes();

    /*!
     * \brief showPop - This method displays the popup widget elements.
     */
    void showPop();

public slots:
    /*!
     * \brief handleCurrentRecipeOnPhone - This method handles displaying the current recipe on the phone widget.
     * \param gameRecipe: RecipeName type object - the recipe chosen by the user.
     */
    void handleCurrentRecipeOnPhone(RecipeName gameRecipe);

private slots:
    /*!
     * \brief on_mayoButton_pressed - adds the selected element to the MainWindow.
     */
    void on_mayoButton_pressed();

    /*!
     * \brief on_oilButton_pressed - adds the selected element to the MainWindow.
     */
    void on_oilButton_pressed();

    /*!
     * \brief on_potatoButton_pressed - adds the selected element to the MainWindow.
     */
    void on_potatoButton_pressed();

    /*!
     * \brief on_noodlesButton_pressed - adds the selected element to the MainWindow.
     */
    void on_noodlesButton_pressed();

    /*!
     * \brief on_ramenButton_pressed - adds the selected element to the MainWindow.
     */
    void on_ramenButton_pressed();

    /*!
     * \brief on_sauceButton_pressed - adds the selected element to the MainWindow.
     */
    void on_sauceButton_pressed();

    /*!
     * \brief on_chipsButton_pressed - adds the selected element to the MainWindow.
     */
    void on_chipsButton_pressed();

    /*!
     * \brief on_tortillasButton_pressed - adds the selected element to the MainWindow.
     */
    void on_tortillasButton_pressed();

    /*!
     * \brief on_platesButton_pressed - adds the selected element to the MainWindow.
     */
    void on_platesButton_pressed();

    /*!
     * \brief on_bowlsButton_pressed - adds the selected element to the MainWindow.
     */
    void on_bowlsButton_pressed();

    /*!
     * \brief on_waterButton_pressed - adds the selected element to the MainWindow.
     */
    void on_waterButton_pressed();

    /*!
     * \brief on_chickenButton_pressed - adds the selected element to the MainWindow.
     */
    void on_chickenButton_pressed();

    /*!
     * \brief on_salsaButton_pressed - adds the selected element to the MainWindow.
     */
    void on_salsaButton_pressed();

    /*!
     * \brief on_sourCreamButton_pressed - adds the selected element to the MainWindow.
     */
    void on_sourCreamButton_pressed();

    /*!
     * \brief on_lettuceButton_pressed - adds the selected element to the MainWindow.
     */
    void on_lettuceButton_pressed();

    /*!
     * \brief on_cheeseButton_pressed - adds the selected element to the MainWindow.
     */
    void on_cheeseButton_pressed();

    /*!
     * \brief on_resetButton_clicked - adds the selected element to the MainWindow.
     */
    void on_resetButton_clicked();

private:
    /*!
     * \brief ui - MainWindow instance of ui type.
     */
    Ui::MainWindow *ui;

    /*!
     * \brief popUp - PopUp type instance for the MainWindow class.
     */
    PopUp* popUp;

    /*!
     * \brief model - The Model object that backs the MainWindow class.
     */
    Model* model;
};

#endif // MAINWINDOW_H
