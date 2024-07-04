#include "mainwindowpet.h"
#include "ui_mainwindowpet.h"
#include "mainwindow.h"

MainWindowpet::MainWindowpet(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindowpet)
{
    ui->setupUi(this);

    pix.load(":/pet_pix/smiling.png");
    setWindowFlag(Qt::FramelessWindowHint);  //隐藏边框
    this->setAttribute(Qt::WA_TranslucentBackground);  //透明背景
    this->setFixedSize(pix.width()+100,pix.height());  //固定大小
    this->setWindowFlags(this->windowFlags()|Qt::Tool);  //设置窗口顶层

    //窗口移动到中间
    this->desk =QApplication::desktop();
    this->current_pos = QPoint(desk->width()-this->width(),desk->height()/2);
    this->move(current_pos);

    //默认动画地址
    this->pic_address = this->pic_address_1;

    //按钮加载关闭按钮
    this->Close = new QPushButton(this);
    this->Close->setIcon(QIcon(":/pet_icons/stop.png"));
    this->Close->move(180,0);  //位置设置
    this->Close->setFixedSize(20,20);
    //设置样式
    connect(this->Close,&QPushButton::clicked,[=](){
        exit(0);
    });

    //实现返回按钮
    QPushButton *btn_1 = new QPushButton(this);
    btn_1->setParent(this);
    btn_1->setIcon(QIcon(":/pet_icons/left.png"));
    btn_1->move(0,0);
    btn_1->setFixedSize(20,20);
//    connect(btn_1, &QPushButton::clicked, this, [=](){
//        this->close();
//    });
    connect(btn_1, &QPushButton::clicked, this, &MainWindowpet::fanhui);

    //按钮加载的动画

    //设计按钮_1  笑
    this->pic_1 = new QPushButton(this);
    this->pic_1->setIcon(QIcon(":/pet_icons/com.png"));
    this->pic_1->move(180,25);
    this->pic_1->setFixedSize(20,20);
    //连接一下槽函数
    connect(this->pic_1,&QPushButton::clicked,this,&MainWindowpet::show_1);

    //设计按钮_2  哭
    this->pic_2 = new QPushButton(this);
    this->pic_2->setIcon(QIcon(":/pet_icons/com.png"));
    this->pic_2->move(180,50);
    this->pic_2->setFixedSize(20,20);
    //连接一下槽函数
    connect(this->pic_2,&QPushButton::clicked,this,&MainWindowpet::show_2);

    //设计按钮_3  跳舞
    this->pic_3 = new QPushButton(this);
    this->pic_3->setIcon(QIcon(":/pet_icons/com.png"));
    this->pic_3->move(180,75);
    this->pic_3->setFixedSize(20,20);
    //连接一下槽函数
    connect(this->pic_3,&QPushButton::clicked,this,&MainWindowpet::show_3);

    //设计按钮_4  玩
    this->pic_4 = new QPushButton(this);
    this->pic_4->setIcon(QIcon(":/pet_icons/com.png"));
    this->pic_4->move(180,100);
    this->pic_4->setFixedSize(20,20);
    //连接一下槽函数
    connect(this->pic_4,&QPushButton::clicked,this,&MainWindowpet::show_4);

    //设计按钮_5  学习
    this->pic_5 = new QPushButton(this);
    this->pic_5->setIcon(QIcon(":/pet_icons/com.png"));
    this->pic_5->move(180,125);
    this->pic_5->setFixedSize(20,20);
    //连接一下槽函数
    connect(this->pic_5,&QPushButton::clicked,this,&MainWindowpet::show_5);

}
//绘图事件
void MainWindowpet::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.drawPixmap(0,0,pix);
}
//这样大致就显示出啦

//鼠标移动事件
void MainWindowpet::mouseMoveEvent(QMouseEvent *e)
{
    //更新当前位置
    this->current_pos = QPoint(e->globalPos()-m_pos);
    this->move(e->globalPos()-this->m_pos);
}
//鼠标按下
void MainWindowpet::mousePressEvent(QMouseEvent *e)
{
    //鼠标按下的时候有记录分量
    m_pos = e->globalPos()-this->pos();
}


//写一下几个槽函数

//1、展示笑的图画
void MainWindowpet::show_1()
{
    this->pic_address = this->pic_address_1;  //把相应图片存过去
    pix.load(pic_address);  //把图片load上去
    update();  //更新绘画事件

}

//2、哭
void MainWindowpet::show_2()
{
    this->pic_address = this->pic_address_2;
    pix.load(pic_address);
    update();
}

//3、跳舞
void MainWindowpet::show_3()
{
    this->pic_address = this->pic_address_3;
    pix.load(pic_address);
    update();
}

//4、玩
void MainWindowpet::show_4()
{
    this->pic_address = this->pic_address_4;
    pix.load(pic_address);
    update();
}

//5、学习
void MainWindowpet::show_5()
{
    this->pic_address = this->pic_address_5;
    pix.load(pic_address);
    update();
}

void MainWindowpet::fanhui()
{
    MainWindow *mainwindow = new MainWindow;
    mainwindow->show();
    this->close();
}


MainWindowpet::~MainWindowpet()
{
    delete ui;
}
