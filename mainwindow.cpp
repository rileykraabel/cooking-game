#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "model.h"
#include "objectName.h"
#include <QLabel>
#include "popup.h"
#include "congratulationspopup.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , popUp(new class::PopUp(parent))
    , model(new class::Model(new class::CongratulationsPopUp()))

{
    ui->setupUi(this);
    ui->gameWindow->setModel(model);
    int fontSize = 15;

    QFont font = ui->phoneRecipe->font();
    font.setPointSize(fontSize);
    ui->phoneRecipe->setFont(font);

    // Set icons for ingredients on shelves and in fridge
    QIcon oilIcon(QString(":/images/oil.png"));
    ui->oilButton->setIcon(oilIcon);
    ui->oilButton->setIconSize(QSize(55, 55));
    ui->oilButton->setStyleSheet("QPushButton { background-color: transparent; border: 0px }");

    QIcon potatoIcon(QString(":/images/potato.png"));
    ui->potatoButton->setIcon(potatoIcon);
    ui->potatoButton->setIconSize(QSize(35, 35));
    ui->potatoButton->setStyleSheet("QPushButton { background-color: transparent; border: 0px }");

    QIcon noodlesIcon(QString(":/images/noodles.png"));
    ui->noodlesButton->setIcon(noodlesIcon);
    ui->noodlesButton->setIconSize(QSize(60, 100));
    ui->noodlesButton->setStyleSheet("QPushButton { background-color: transparent; border: 0px }");

    QIcon ramenIcon(QString(":/images/ramen.png"));
    ui->ramenButton->setIcon(ramenIcon);
    ui->ramenButton->setIconSize(QSize(50, 50));
    ui->ramenButton->setStyleSheet("QPushButton { background-color: transparent; border: 0px }");

    QIcon sauceIcon(QString(":/images/alfredo.png"));
    ui->sauceButton->setIcon(sauceIcon);
    ui->sauceButton->setIconSize(QSize(50, 50));
    ui->sauceButton->setStyleSheet("QPushButton { background-color: transparent; border: 0px }");

    QIcon chipsIcon(QString(":/images/chipBag.png"));
    ui->chipsButton->setIcon(chipsIcon);
    ui->chipsButton->setIconSize(QSize(50, 50));
    ui->chipsButton->setStyleSheet("QPushButton { background-color: transparent; border: 0px }");

    QIcon tortillasIcon(QString(":/images/tortillas.png"));
    ui->tortillasButton->setIcon(tortillasIcon);
    ui->tortillasButton->setIconSize(QSize(50, 50));
    ui->tortillasButton->setStyleSheet("QPushButton { background-color: transparent; border: 0px }");

    QIcon platesIcon(QString(":/images/plates.png"));
    ui->platesButton->setIcon(platesIcon);
    ui->platesButton->setIconSize(QSize(50, 50));
    ui->platesButton->setStyleSheet("QPushButton { background-color: transparent; border: 0px }");

    QIcon bowlsIcon(QString(":/images/bowls.png"));
    ui->bowlsButton->setIcon(bowlsIcon);
    ui->bowlsButton->setIconSize(QSize(50, 50));
    ui->bowlsButton->setStyleSheet("QPushButton { background-color: transparent; border: 0px }");

    QIcon lettuceIcon(QString(":/images/lettuce.png"));
    ui->lettuceButton->setIcon(lettuceIcon);
    ui->lettuceButton->setIconSize(QSize(50, 50));
    ui->lettuceButton->setStyleSheet("QPushButton { background-color: transparent; border: 0px }");

    QIcon cheeseIcon(QString(":/images/cheeseBag.png"));
    ui->cheeseButton->setIcon(cheeseIcon);
    ui->cheeseButton->setIconSize(QSize(50, 50));
    ui->cheeseButton->setStyleSheet("QPushButton { background-color: transparent; border: 0px }");

    QIcon mayoIcon(QString(":/images/mayo.png"));
    ui->mayoButton->setIcon(mayoIcon);
    ui->mayoButton->setIconSize(QSize(50, 50));
    ui->mayoButton->setStyleSheet("QPushButton { background-color: transparent; border: 0px }");

    QIcon chickenIcon(QString(":/images/chicken.png"));
    ui->chickenButton->setIcon(chickenIcon);
    ui->chickenButton->setIconSize(QSize(70, 70));
    ui->chickenButton->setStyleSheet("QPushButton { background-color: transparent; border: 0px }");

    QIcon salsaIcon(QString(":/images/salsa.png"));
    ui->salsaButton->setIcon(salsaIcon);
    ui->salsaButton->setIconSize(QSize(40, 40));
    ui->salsaButton->setStyleSheet("QPushButton { background-color: transparent; border: 0px }");

    QIcon sourCreamIcon(QString(":/images/sourCream.png"));
    ui->sourCreamButton->setIcon(sourCreamIcon);
    ui->sourCreamButton->setIconSize(QSize(50, 50));
    ui->sourCreamButton->setStyleSheet("QPushButton { background-color: transparent; border: 0px }");

    QIcon waterIcon(QString(":/images/water.png"));
    ui->waterButton->setIcon(waterIcon);
    ui->waterButton->setIconSize(QSize(50, 50));
    ui->waterButton->setStyleSheet("QPushButton { background-color: transparent; border: 0px }");

    QIcon phoneIcon(QString(":/images/phone.png"));
    ui->phoneButton->setIcon(phoneIcon);
    ui->phoneButton->setIconSize(QSize(400,400));
    ui->phoneButton->setStyleSheet("QPushButton { background-color: transparent; border: 0px }");

    connectRecipes();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::connectRecipes()
{
    connect(popUp,
            &PopUp::currentRecipe,
            this,
            &MainWindow::handleCurrentRecipeOnPhone);
}

void MainWindow::showPop()
{
    popUp->show();
}

void MainWindow::on_mayoButton_pressed()
{
    GameObject* mayoObject = Model::createObject(ObjectName::mayonaise, QString(":/images/mayo.png"));
    QPoint centerOfButton(ui->mayoButton->pos().x() + (ui->mayoButton->width() / 2), ui->mayoButton->pos().y() + (ui->mayoButton->height() / 2));
    ui->gameWindow->addBody(mayoObject, centerOfButton);
}

void MainWindow::on_oilButton_pressed()
{
    GameObject* oilObject = Model::createObject(ObjectName::oil, QString(":/images/oil.png"));
    QPoint centerOfButton(ui->oilButton->pos().x() + (ui->oilButton->width() / 2), ui->oilButton->pos().y() + (ui->oilButton->height() / 2));
    ui->gameWindow->addBody(oilObject, centerOfButton);
}

void MainWindow::on_potatoButton_pressed()
{
    GameObject* potatoObject = Model::createObject(ObjectName::rawPotato, QString(":/images/potato.png"));
    QPoint centerOfButton(ui->potatoButton->pos().x() + (ui->potatoButton->width() / 2), ui->potatoButton->pos().y() + (ui->potatoButton->height() / 2));
    ui->gameWindow->addBody(potatoObject, centerOfButton);
}


void MainWindow::on_noodlesButton_pressed()
{
    GameObject* noodlesObject = Model::createObject(ObjectName::noodles, QString(":/images/spaghettiNoodles.png"));
    QPoint centerOfButton(ui->noodlesButton->pos().x() + (ui->noodlesButton->width() / 2), ui->noodlesButton->pos().y() + (ui->noodlesButton->height() / 2));
    ui->gameWindow->addBody(noodlesObject, centerOfButton);
}


void MainWindow::on_ramenButton_pressed()
{
    GameObject* ramenObject = Model::createObject(ObjectName::ramenPacket, QString(":/images/ramen.png"));
    QPoint centerOfButton(ui->ramenButton->pos().x() + (ui->ramenButton->width() / 2), ui->ramenButton->pos().y() + (ui->ramenButton->height() / 2));
    ui->gameWindow->addBody(ramenObject, centerOfButton);
}


void MainWindow::on_sauceButton_pressed()
{
    GameObject* sauceObject = Model::createObject(ObjectName::sauce, QString(":/images/alfredo.png"));
    QPoint centerOfButton(ui->sauceButton->pos().x() + (ui->sauceButton->width() / 2), ui->sauceButton->pos().y() + (ui->sauceButton->height() / 2));
    ui->gameWindow->addBody(sauceObject, centerOfButton);
}


void MainWindow::on_chipsButton_pressed()
{
    GameObject* chipsObject = Model::createObject(ObjectName::chips, QString(":/images/chips.png"));
    QPoint centerOfButton(ui->chipsButton->pos().x() + (ui->chipsButton->width() / 2), ui->chipsButton->pos().y() + (ui->chipsButton->height() / 2));
    ui->gameWindow->addBody(chipsObject, centerOfButton);
}


void MainWindow::on_tortillasButton_pressed()
{
    GameObject* tortillaObject = Model::createObject(ObjectName::tortillas, QString(":/images/tortillas.png"));
    QPoint centerOfButton(ui->tortillasButton->pos().x() + (ui->tortillasButton->width() / 2), ui->tortillasButton->pos().y() + (ui->tortillasButton->height() / 2));
    ui->gameWindow->addBody(tortillaObject, centerOfButton);
}


void MainWindow::on_platesButton_pressed()
{
    GameObject* platesObject = Model::createObject(ObjectName::plate, QString(":/images/plate.png"));
    QPoint centerOfButton(ui->platesButton->pos().x() + (ui->platesButton->width() / 2), ui->platesButton->pos().y() + (ui->platesButton->height() / 2));
    ui->gameWindow->addBody(platesObject, centerOfButton);
}


void MainWindow::on_bowlsButton_pressed()
{
    GameObject* bowlsObject = Model::createObject(ObjectName::bowl, QString(":/images/bowl.png"));
    QPoint centerOfButton(ui->bowlsButton->pos().x() + (ui->bowlsButton->width() / 2), ui->bowlsButton->pos().y() + (ui->bowlsButton->height() / 2));
    ui->gameWindow->addBody(bowlsObject, centerOfButton);
}


void MainWindow::on_waterButton_pressed()
{
    GameObject* waterObject = Model::createObject(ObjectName::water, QString(":/images/water.png"));
    QPoint centerOfButton(ui->waterButton->pos().x() + (ui->waterButton->width() / 2), ui->waterButton->pos().y() + (ui->waterButton->height() / 2));
    ui->gameWindow->addBody(waterObject, centerOfButton);
}


void MainWindow::on_chickenButton_pressed()
{
    GameObject* chickenObject = Model::createObject(ObjectName::chicken, QString(":/images/chicken.png"));
    QPoint centerOfButton(ui->chickenButton->pos().x() + (ui->chickenButton->width() / 2), ui->chickenButton->pos().y() + (ui->chickenButton->height() / 2));
    ui->gameWindow->addBody(chickenObject, centerOfButton);
}


void MainWindow::on_salsaButton_pressed()
{
    GameObject* salsaObject = Model::createObject(ObjectName::salsa, QString(":/images/salsa.png"));
    QPoint centerOfButton(ui->salsaButton->pos().x() + (ui->salsaButton->width() / 2), ui->salsaButton->pos().y() + (ui->salsaButton->height() / 2));
    ui->gameWindow->addBody(salsaObject, centerOfButton);
}


void MainWindow::on_sourCreamButton_pressed()
{
    GameObject* sourCreamObject = Model::createObject(ObjectName::sourCream, QString(":/images/sourCream.png"));
    QPoint centerOfButton(ui->sourCreamButton->pos().x() + (ui->sourCreamButton->width() / 2), ui->sourCreamButton->pos().y() + (ui->sourCreamButton->height() / 2));
    ui->gameWindow->addBody(sourCreamObject, centerOfButton);
}


void MainWindow::on_lettuceButton_pressed()
{
    GameObject* lettuceObject = Model::createObject(ObjectName::lettuce, QString(":/images/lettuce.png"));
    QPoint centerOfButton(ui->lettuceButton->pos().x() + (ui->lettuceButton->width() / 2), ui->lettuceButton->pos().y() + (ui->lettuceButton->height() / 2));
    ui->gameWindow->addBody(lettuceObject, centerOfButton);
}


void MainWindow::on_cheeseButton_pressed()
{
    GameObject* cheeseObject = Model::createObject(ObjectName::cheese, QString(":/images/shreddedCheese.png"));
    QPoint centerOfButton(ui->cheeseButton->pos().x() + (ui->cheeseButton->width() / 2), ui->cheeseButton->pos().y() + (ui->cheeseButton->height() / 2));
    ui->gameWindow->addBody(cheeseObject, centerOfButton);
}


void MainWindow::on_resetButton_clicked()
{
    ui->gameWindow->resetWorld();
}

void MainWindow::handleCurrentRecipeOnPhone(RecipeName gameRecipe)
{
    model->selected = gameRecipe;
    if (gameRecipe == RecipeName::ramen)
    {
        ui->phoneRecipe->addItem("RAMEN:");
        ui->phoneRecipe->addItem("1. Grab a bowl.");
        ui->phoneRecipe->addItem("2. Fill the bowl with water.");
        ui->phoneRecipe->addItem("3. Add ramen noodles.");
        ui->phoneRecipe->addItem("4. Place the bowl in the \n     microwave.");
        ui->phoneRecipe->addItem("5. Drain the water out of the bowl \n     into the plant.");
        ui->phoneRecipe->addItem("6. Add flavored oil.");
    }
    else if (gameRecipe == RecipeName::nachos)
    {
        ui->phoneRecipe->addItem("NACHOS:");
        ui->phoneRecipe->addItem("1. Grab a plate.");
        ui->phoneRecipe->addItem("2. Place a handful of chips on \n     the plate.");
        ui->phoneRecipe->addItem("3. Add a handful of cheese.");
        ui->phoneRecipe->addItem("4. Place the plate in the \n     microwave.");
        ui->phoneRecipe->addItem("5. Add salsa.");
        ui->phoneRecipe->addItem("6. Add sourcream.");
    }
    else if (gameRecipe == RecipeName::bakedPotato)
    {
        ui->phoneRecipe->addItem("BAKED POTATO:");
        ui->phoneRecipe->addItem("1. Grab a plate.");
        ui->phoneRecipe->addItem("2. Place a potato on the plate.");
        ui->phoneRecipe->addItem("3. Place the plate in the \n     microwave.");
        ui->phoneRecipe->addItem("4. Add cheese.");
        ui->phoneRecipe->addItem("5. Add sour cream.");
    }
    else if (gameRecipe == RecipeName::wrap)
    {
        ui->phoneRecipe->addItem("CHICKEN WRAP:");
        ui->phoneRecipe->addItem("1. Grab a plate. ");
        ui->phoneRecipe->addItem("2. Place a tortilla on the plate.");
        ui->phoneRecipe->addItem("3. Add mayo.");
        ui->phoneRecipe->addItem("4. Add lettuce.");
        ui->phoneRecipe->addItem("5. Add chicken.");
    }
    else if (gameRecipe == RecipeName::quesadilla)
    {
        ui->phoneRecipe->addItem("CHICKEN QUESADILLA:");
        ui->phoneRecipe->addItem("1. Grab a plate.");
        ui->phoneRecipe->addItem("2. Place tortilla on the plate.");
        ui->phoneRecipe->addItem("3. Add a handful of cheese.");
        ui->phoneRecipe->addItem("4. Add chicken.");
        ui->phoneRecipe->addItem("5. Add another tortilla.");
        ui->phoneRecipe->addItem("6. Place the plate in the \n     microwave.");
        ui->phoneRecipe->addItem("7. Add a dollop of sour cream.");
    }
    else if (gameRecipe == RecipeName::alfredo)
    {
        ui->phoneRecipe->addItem("ALFREDO:");
        ui->phoneRecipe->addItem("1. Grab a bowl.");
        ui->phoneRecipe->addItem("2. Fill the bowl with water.");
        ui->phoneRecipe->addItem("3. Add noodles.");
        ui->phoneRecipe->addItem("4. Place the bowl in the \n     microwave.");
        ui->phoneRecipe->addItem("5. Drain the water out of the bowl \n     into the plant.");
        ui->phoneRecipe->addItem("6. Add alfredo sauce.");
        ui->phoneRecipe->addItem("7. Add chicken.");
    }
    else
    {
        ui->phoneRecipe->addItem("You did not select \na recipe.");
    }
}

