#ifndef MAINWINDOWNOTE_H
#define MAINWINDOWNOTE_H
#pragma execution_character_set("utf-8") // 解决汉字乱码问题
#include <QMainWindow>
#include <QWidget>
#include <QLineEdit>
#include <QLabel>
namespace Ui {
class MainWindownote;
}

class MainWindownote : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindownote(QWidget *parent = nullptr);
    ~MainWindownote();

    //直接性保存
    void quick_save(const QString &sfileName);
    //滑轮控制的放大与缩小
    void wheelEvent(QWheelEvent *event);
//    //鼠标相关工作
    void mouseMoveEvent(QMouseEvent *event);

private slots:
    //返回键（临时）
    void on_toolButton_clicked();


    //基本功能
    void on_action_open_triggered();  //打开按钮 尝试实现的第一个功能——打开文件
    void on_actionlingcunwei_triggered();  //另存为
    void on_actiontuichu_triggered();  //退出
    void on_actionnew_triggered();  //新建
    void on_actionsave_triggered(); // 保存
    void on_actionwindow_triggered();  //创建新窗口
    void on_actionDateAndTime_triggered(); //时间日日期
    void on_actionsearch_triggered();  //搜索
    void find_showSlot();  //show出search的东西
    void on_actioncopy_triggered();  //复制
    void on_actioncut_triggered();  //剪切
    void on_actionpaste_triggered();  //粘贴
    void on_actionpicture_triggered(); //图片

    //状态栏时间
    void time_update();

    //对齐
    void on_actionjuzhong_triggered();  //居中对齐
    void on_actionzuo_triggered();  //左对齐
    void on_actionyou_triggered();  //右对齐

   //字体的相关编辑
    void on_actionsong_triggered();  //宋体
    void on_actionhei_triggered();  // 黑体
    void on_actionkai_triggered();  //楷书

    void on_actionjiacu_2_triggered();  //加粗
    void on_actiondejiacu_2_triggered();  //取消加粗
    void on_actionxieti_2_triggered();  //斜体
    void on_actiondexieti_triggered();  //取消斜体
    void on_actionxiahuaxian_2_triggered();  //下划线
    void on_actiondexiahuaxian_triggered();  //取消下划线

    //字体颜色
    void on_actionred_triggered();
    void on_actionblue_triggered();
    void on_actiongreen_triggered();

    //字号·
    void on_action10_triggered();
    void on_action12_triggered();
    void on_action14_triggered();
    void on_action1_triggered();
    void on_action18_triggered();
    void on_action20_triggered();
    void on_action32_triggered();
    void on_action64_triggered();

    void on_pushButton_clicked();

private:
    Ui::MainWindownote *ui;
    QString fileName;
    int isChange;//判断文件是否变动 是否保存
    int newfile;//判断是否为新文件
    QFont font;  //用于字体设置
    int val; //用于ctrl鼠标滑轮放大缩小
    QDialog * find_word;  //实例查找
    QLineEdit *findLineEdit;  //文本框
    QLabel *timelabel;
    QLabel *label;

};

#endif // MAINWINDOWNOTE_H
