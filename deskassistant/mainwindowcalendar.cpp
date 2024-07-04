#include "mainwindowcalendar.h"
#include "ui_mainwindowcalendar.h"
#include "mainwindow.h"

MainWindowcalendar::MainWindowcalendar(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindowcalendar)
{
    ui->setupUi(this);
    //设置软件图标
    setWindowIcon(QIcon(":/logo/logotry.png"));
}

MainWindowcalendar::~MainWindowcalendar()
{
    delete ui;
}


void MainWindowcalendar::on_tbC_M_clicked()
{
    MainWindow *mainwindow = new MainWindow;
    this->close();
    mainwindow->show();
}

