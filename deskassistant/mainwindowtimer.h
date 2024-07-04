#ifndef MAINWINDOWTIMER_H
#define MAINWINDOWTIMER_H

#include <QMainWindow>
#include <QTime>
#include <QTimer>

namespace Ui {
class MainWindowtimer;
}

class MainWindowtimer : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindowtimer(QWidget *parent = nullptr);
    ~MainWindowtimer();

private slots:
    void on_tbT_M_clicked();//切换页面的按钮
    void initTime();//重置时间的函数
    void updateTime();//更新的函数

    //三个按钮 开始，暂停和重置
    void on_pbStart_clicked();
    void on_pbStop_clicked();
    void on_pbReset_clicked();

    void on_tbT_N_clicked();

private:
    Ui::MainWindowtimer *ui;
    QTimer *timer;//创建计时器
    QTime *TimeRecord;//创建记录时间的
};

#endif // MAINWINDOWTIMER_H
