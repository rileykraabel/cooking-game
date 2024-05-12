#include "ui_popup.h"
#include "popup.h"

PopUp::PopUp(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PopUp)
{
    ui->setupUi(this);

    // Add icons to buttons for picking a recipe
    QIcon ramenRecipeIcon(QString(":/images/finalRamen.png"));
    ui->ramenRecipe->setIcon(ramenRecipeIcon);
    ui->ramenRecipe->setIconSize(QSize(300, 300));

    QIcon potatoRecipeIcon(QString(":/images/finalBakedPotato.png"));
    ui->potatoRecipe->setIcon(potatoRecipeIcon);
    ui->potatoRecipe->setIconSize(QSize(300, 300));

    QIcon quesadillaRecipeIcon(QString(":/images/quesadilla.png"));
    ui->quesadillaRecipe->setIcon(quesadillaRecipeIcon);
    ui->quesadillaRecipe->setIconSize(QSize(300, 300));

    QIcon nachosRecipeIcon(QString(":/images/finalNacho.png"));
    ui->nachosRecipe->setIcon(nachosRecipeIcon);
    ui->nachosRecipe->setIconSize(QSize(300, 300));

    QIcon alfredoRecipeIcon(QString(":/images/finalAlfredo.png"));
    ui->alfredoRecipe->setIcon(alfredoRecipeIcon);
    ui->alfredoRecipe->setIconSize(QSize(300, 300));

    QIcon wrapRecipeIcon(QString(":/images/wrap.png"));
    ui->wrapRecipe->setIcon(wrapRecipeIcon);
    ui->wrapRecipe->setIconSize(QSize(300, 300));
}

PopUp::~PopUp()
{
    delete ui;
}


void PopUp::on_ramenRecipe_clicked()
{
    this->hide();
    emit currentRecipe(RecipeName::ramen);
}


void PopUp::on_potatoRecipe_clicked()
{
    this->hide();
    emit currentRecipe(RecipeName::bakedPotato);
}


void PopUp::on_alfredoRecipe_clicked()
{
    this->hide();
    emit currentRecipe(RecipeName::alfredo);
}


void PopUp::on_nachosRecipe_clicked()
{
    this->hide();
    emit currentRecipe(RecipeName::nachos);
}


void PopUp::on_wrapRecipe_clicked()
{
    this->hide();
    emit currentRecipe(RecipeName::wrap);
}


void PopUp::on_quesadillaRecipe_clicked()
{
    this->hide();
    emit currentRecipe(RecipeName::quesadilla);
}

