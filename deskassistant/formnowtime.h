#ifndef FORMNOWTIME_H
#define FORMNOWTIME_H

#include <QTime>
#include <QWidget>

namespace Ui {
class Formnowtime;
}

class Formnowtime : public QWidget
{
    Q_OBJECT

public:
    explicit Formnowtime(QWidget *parent = nullptr);
    ~Formnowtime();
    void paintEvent(QPaintEvent *event);  //绘画事件
    void timerEvent(QTimerEvent *event);  //计时器事件

private:
    Ui::Formnowtime *ui;
    int h= 0;
    int m =0;
    int s =0;
    //创建三个变量来存储时间
    int timer;  //存储计时器返回的信号
};

#endif // FORMNOWTIME_H
