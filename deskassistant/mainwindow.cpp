#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mainwindowcalendar.h"
#include "mainwindowtimer.h"
#include "mainwindownote.h"
#include "mainwindowpet.h"
#include "QIcon"
#include "QMessageBox"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //设置软件图标
    setWindowIcon(QIcon(":/logo/logotry.png"));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_tbM_C_clicked()
{
    MainWindowcalendar *MWcalendar = new MainWindowcalendar;//生成一个叫MWcalendar的MainWindowcalendar文件
    this->close();//点击按钮时关闭这个窗口即主窗口
    MWcalendar->show();//显示MWcalendar
}



void MainWindow::on_tbM_T_clicked()
{
    MainWindowtimer *MWtimer = new MainWindowtimer;
    this ->close();
    MWtimer->show();
}



void MainWindow::on_tpM_N_clicked()
{
    MainWindownote *MWnote = new MainWindownote;
    this->close();
    MWnote->show();
}


void MainWindow::on_tbM_P_clicked()
{
    MainWindowpet *MWpet = new MainWindowpet;
    this->close();
    MWpet->show();
}


//下面来补充一下暂未完成部分的提示
void MainWindow::on_toolButton_8_clicked()
{
    QMessageBox::warning(this,tr("抱歉"),tr("该部分功能还未完善，敬请期待"));
}


void MainWindow::on_toolButton_6_clicked()
{
    QMessageBox::warning(this,tr("抱歉"),tr("该部分功能还未完善，敬请期待"));
}


void MainWindow::on_toolButton_clicked()
{
    QMessageBox::warning(this,tr("抱歉"),tr("该部分功能还未完善，敬请期待"));
}


void MainWindow::on_toolButton_9_clicked()
{
    QMessageBox::warning(this,tr("抱歉"),tr("该部分功能还未完善，敬请期待"));
}

