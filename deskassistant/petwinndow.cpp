#include "petwinndow.h"
#include "ui_petwinndow.h"

PetWinndow::PetWinndow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PetWinndow)
{
    ui->setupUi(this);
}

PetWinndow::~PetWinndow()
{
    delete ui;
}
