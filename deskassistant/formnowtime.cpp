#include "formnowtime.h"
#include "ui_formnowtime.h"
#include <QPainter>
#include<QIcon>

Formnowtime::Formnowtime(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Formnowtime)
{
    ui->setupUi(this);
    timer = startTimer(1000);
    QTime nowtime = QTime::currentTime();//调用currentTime来获取当前时间 并存储在定义的变量nowtime中
    h = nowtime.hour();
    m = nowtime.minute();
    s = nowtime.second();
    //设置软件图标
    setWindowIcon(QIcon(":/logo/logotry.png"));
}

Formnowtime::~Formnowtime()
{
    delete ui;
}
//构造定时器事件
void Formnowtime::timerEvent(QTimerEvent *event)
{
    s++;
    if(s==60)
    {
        m++;
        if(m==60)
        {
            h++;
            if(h==24)
            {
                h=0;
            }
        }
    }

}
//描述出定时器中的进制转换

//构造绘图事件
void Formnowtime::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);  //必须在绘画事件中定义才会激活
    painter.setRenderHint(QPainter::Antialiasing,true);//抗锯齿即消除锯齿
    QPen mypen(Qt::black,3);  //创建一个画笔mypen
    painter.setPen(mypen);  //使用画笔
    QPoint center(this->width()/2,this->height()/2);  //把点center定义在画布的中心位置上
    painter.translate(center);  //利用translate函数把函数远点定位到中心位置
    QPoint cen(0,0);  //定义一个叫cen的点在原点
    painter.drawEllipse(cen,200,200);  //绘制出时钟的外围

    //绘制小时的刻度线
    for(int i = 0;i < 12;i++)
    {
        painter.rotate(30);
        painter.drawLine(0,-180,0,-200);
    }

    //绘制分钟的刻度线
    for(int i = 0;i<60;i++)
    {
        painter.rotate(6);
        painter.drawLine(0,-190,0,-200);
    }
    painter.end();

    QPainter painters(this);   //定义一个画家来控制秒针
    painters.setRenderHint(QPainter::Antialiasing,true);
    mypen.setWidth(1);

    painters.setPen(mypen);
    painters.translate(center);
    painters.rotate(s*6);     //秒针每秒转6度
    painters.drawLine(0,0,0,-150);     //画出秒针
    painters.end();


    QPainter painterm(this);  //定义一个画家来控制分针
    painters.setRenderHint(QPainter::Antialiasing,true);
    mypen.setWidth(4);

    painterm.setPen(mypen);
    painterm.translate(center);
    painterm.rotate(m*6);
    painterm.drawLine(0,0,0,-100);//分针适量短一些
    painterm.end();


    QPainter painterh(this);  //定义一个画家来控制时针
    painterh.setRenderHint(QPainter::Antialiasing,true);
    mypen.setWidth(7);
    painterh.setPen(mypen);
    painterh.translate(center);
    painterh.rotate(h*30+m*0.5);//时针每小时偏移30°并在此基础上每分钟偏移0.5°
    painterh.drawLine(0,0,0,-70);
    painterh.end();

    update();//刷新绘图事件

}
