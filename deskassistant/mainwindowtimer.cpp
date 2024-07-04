#include "mainwindowtimer.h"
#include "ui_mainwindowtimer.h"
#include "mainwindow.h"
#include "formnowtime.h"

MainWindowtimer::MainWindowtimer(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindowtimer)
{
    ui->setupUi(this);
    timer = new QTimer;
    TimeRecord = new QTime;
    ui->Timer->setDigitCount(8);
    initTime();  //让LCD显示00:00:00
    //链接槽函数，让timer的timeout行为链接到updateTime函数中
    connect(timer,SIGNAL(timeout()),this,SLOT(updateTime()));
    //设置软件图标
    setWindowIcon(QIcon(":/logo/logotry.png"));
}

MainWindowtimer::~MainWindowtimer()
{

    delete ui;
}

void MainWindowtimer::on_tbT_M_clicked()
{
    MainWindow *mainwindow = new MainWindow;
    this->close();
    mainwindow->show();
}


//一下是功能部分的实现
//initTime重置时间功能
void MainWindowtimer::initTime()
{
    TimeRecord->setHMS(0,0,0);
    ui->Timer->display(TimeRecord->toString("hh:mm:ss"));
}
//updateTime更新功能的实现
void MainWindowtimer::updateTime()
{
    *TimeRecord = TimeRecord->addSecs(1);
    ui->Timer->display(TimeRecord->toString("hh:mm:ss"));
}

void MainWindowtimer::on_pbStart_clicked()
{
    timer->start(1000);
}


void MainWindowtimer::on_pbStop_clicked()
{
    timer->stop();
}


void MainWindowtimer::on_pbReset_clicked()
{
    initTime();
}


//加一个没啥用的现在时间的时钟
//好不容易学的 不能白学
void MainWindowtimer::on_tbT_N_clicked()
{
    Formnowtime *Fnowtime = new Formnowtime;
    Fnowtime->show();
}

