#include "mainwindownotepad.h"
#include "ui_mainwindownotepad.h"

//开始施工！
MainWindownotepad::MainWindownotepad(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindownotpad)
{
    ui->setupUi(this);
}

MainWindownotepad::~MainWindownotepad()
{
    delete ui;
}
