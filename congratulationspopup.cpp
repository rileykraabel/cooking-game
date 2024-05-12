#include "congratulationspopup.h"
#include "ui_congratulationspopup.h"

CongratulationsPopUp::CongratulationsPopUp(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CongratulationsPopUp)
{
    ui->setupUi(this);
}

CongratulationsPopUp::~CongratulationsPopUp()
{
    delete ui;
}
