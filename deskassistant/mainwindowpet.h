#ifndef MAINWINDOWPET_H
#define MAINWINDOWPET_H

#include <QMainWindow>
#include <QPixmap>
#include <QDesktopWidget>
#include <QPaintEvent>
#include <QMainWindow>
#include <QPainter>
#include <QPushButton>
#include <QCloseEvent>

namespace Ui {
class MainWindowpet;
}

class MainWindowpet : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindowpet(QWidget *parent = nullptr);
    ~MainWindowpet();
    void mouseMoveEvent(QMouseEvent *);  //鼠标移动的动作
    void mousePressEvent(QMouseEvent *);  //鼠标按压的动作
    //    void enterEvent(QEvent *);  //鼠标移入

private:
    Ui::MainWindowpet *ui;
    //绘图事件
    void paintEvent(QPaintEvent *);
    //图片数量
    int pic_max = 3;
    int pic_min = 1;

    QPixmap pix;  //存放图片

    QPoint m_pos;  //鼠标按下的分量

    //加一个退出按钮试试
    QPushButton *Close;
    //切换画面对于的按钮
    QPushButton *pic_1;
    QPushButton *pic_2;
    QPushButton *pic_3;
    QPushButton *pic_4;
    QPushButton *pic_5;

    QString pic_address;
    QString pic_address_1=":/pet_pix/smiling.png"; //笑
    QString pic_address_2=":/pet_pix/crying.png"; //哭
    QString pic_address_3=":/pet_pix/dancing.png";  //跳舞
    QString pic_address_4=":/pet_pix/playing.png";  //玩
    QString pic_address_5=":/pet_pix/studying.png";  //学习
    //窗口现在的位置
    QPoint current_pos;
    //窗口
    QDesktopWidget *desk;
public slots:
    //笑
    void show_1();
    //哭
    void show_2();
    //跳舞
    void show_3();
    //玩
    void show_4();
    //学习
    void show_5();


    //关闭事件
    void fanhui();

};

#endif // MAINWINDOWPET_H
