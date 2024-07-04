#include "mainwindownote.h"
#include "ui_mainwindownote.h"
#include "mainwindow.h"
#include <QT>
#include <QTime>
#include <QTimer>
#include <QDateTime>
#include <QFileDialog>
#include <QMessageBox>
#include <QTextEdit>
#include <QWheelEvent>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QDebug>
//#include <QApplication>

MainWindownote::MainWindownote(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindownote)
{
    ui->setupUi(this);
    isChange = 0; //当文件被修改后才为1
    newfile = 1; //当尝试保存已经有的文件时才会为0
    val = 0;

    //状态栏时间
    timelabel = new QLabel;  //创建
    ui->statusbar->addWidget(timelabel);  //添加
    QTimer *timer = new QTimer(this);
    timer->start(1000);  //每隔1000ms发射一次timeout的信号
    connect(timer , SIGNAL(timeout()),this,SLOT(time_update()));

    label = new QLabel;
    label->resize(100,30);
    ui->statusbar->addPermanentWidget(label);
    //设置软件图标
    setWindowIcon(QIcon(":/logo/logotry.png"));
}

MainWindownote::~MainWindownote()
{
    delete ui;
}


//临时返回按钮
void MainWindownote::on_toolButton_clicked()
{
    MainWindow *mainwindow = new MainWindow;
    this->close();
    mainwindow->show();
}





//尝试实现第一个功能
//打开文件
void MainWindownote::on_action_open_triggered()
{
    newfile = 0;
    //打开文件对话框 选择文件
    fileName = QFileDialog::getOpenFileName(this,\
        tr("打开"),".",tr("Text(*.c *.cpp *.txt *.png *.jpg *.bmp)"));//'.'为当前目录

    //显示到状态栏
    ui->statusbar->showMessage("will open"+fileName,3000);

    if(fileName.isEmpty())
    {
        ui->statusbar->showMessage("选择文件失败");
        return;
    }
    //打开文件
    QFile file(fileName);
    bool ret = file.open(QIODevice::ReadOnly);
    if(!ret)
    {
        ui->statusbar->showMessage("打开文件失败");
        return;
    }
    //读取文件内容
    QByteArray buf = file.readAll();
    //把字节流转换为相应编码的QString(utf-8)
    //代表读出的字节流 是utf-8编码，那么fromUtf8接口会按照Utf8编码转换为utf-8
    QString str = QString::fromUtf8(buf);
    //代表读出的字节流是gbk编码，那么fromLocal8Bit接口会按照gbk编码转换为utf-8
    ui->textEdit->setText(QString(str));
}
//至此是第72行代码  文章为《QT实现记事本功能》

//接下来实现“另存为”功能
void MainWindownote::on_actionlingcunwei_triggered()
{
    //打开选择保存类型的对话框
    fileName = QFileDialog::getSaveFileName(this,\
                                            tr("打开"),".",tr("Text(*.c *.cpp *.txt *.png *.jpg *.bmp)"));//'.'为当前目录
    //判断保存地址
    if(fileName.isEmpty())
    {
        ui->statusbar->showMessage("选择文件位置失败");
    }
    //打开文件并保存
    QFile file(fileName);
    bool ret = file.open(QIODevice::ReadWrite | QIODevice::Truncate); //读写和清空
    if(!ret)
    {
        ui->statusbar->showMessage(QStringLiteral("文件位置不合法"));
        return;
    }
    //写
    QString text = ui->textEdit->toPlainText();
    QByteArray arr = text.toUtf8();
    file.write(arr);
    ui->statusbar->showMessage("保存成功",2000);
}
//一番操作下来算是完成了、
//下面实现“退出”这个环节
//当尝试退出时，要询问是否保存

void MainWindownote::on_actiontuichu_triggered()
{
    if(isChange == 0)
        this->close();
    else
    {
        int ret = QMessageBox::question(NULL,"注意","文件还未保存，是否要保存");
        if(ret == QMessageBox::Yes)  //选择保存
        {
            if(newfile == 1)
            {
                on_actionlingcunwei_triggered();
            }
            else
            {
                quick_save(fileName); //直接保存
            }
        }
        else
            this->close();
    }
}
//接下来把quick_save函数完成一下
void MainWindownote::quick_save(const QString &sfileName)
{
    QFile sFile(sfileName);
    if(!sFile.open(QIODevice::ReadWrite | QIODevice::Truncate))
        return;
    QString text = ui->textEdit->toPlainText();
    QByteArray arr = text.toUtf8();
    sFile.write(arr);
    ui->statusbar->showMessage("保存成功");
}
//还有一个问题就是 isChange 的变化
//这部分在 新建 中 由明天再解决

//新建
void MainWindownote::on_actionnew_triggered()
{
    if(isChange == 1)
    {
        int ret = QMessageBox::question(NULL,"注意","文件未被保存，需要保存吗");
        if (ret == QMessageBox::Yes)
        {
            on_actionlingcunwei_triggered();
        }
    }
    else
    {
        ui->textEdit->clear();
        isChange = 1;
        newfile = 1;
    }
}
//然后我看懂这个作者的投机取巧了
//就用了一个isChange完全不能包含所有情况啊
//有两个方法
//一是更聪明地投机取巧
//在保存文件的同时关闭页面
//二是老老实实想办法解决bug
//暂时先搁置吧

//先来处理这个保存
void MainWindownote::on_actionsave_triggered()
{
    if(newfile==0)
    {
        quick_save(fileName);  //直接用打开文件的文件名保存
    }
    else
    {
        on_actionlingcunwei_triggered();  //调用另存为函数
    }
}
//完成

//创建新窗口
void MainWindownote::on_actionwindow_triggered()
{
    MainWindownote *MWnotes = new MainWindownote;
    MWnotes->show();
}
//我觉得用处不大

//工具 日期和时间
void MainWindownote::on_actionDateAndTime_triggered()
{
    QFont font("Microsoft SimHei",10,10);  //配置字体
    QDateTime time= QDateTime::currentDateTime();  //获取现在时间
    QString tim = time.toString("yyyy-MM-dd hh;mm;ss dddd");  //改变格式
    ui->textEdit->setFont(font);  //字体
    ui->textEdit->setText(tim);  //内容
}
//OK 这样就完成了一个我觉得用处不大的功能
//接下来实现一个比较牛波一的功能
//ctrl加鼠标滑轮进行放大和缩小
void MainWindownote::wheelEvent(QWheelEvent *event)
{
    if(QApplication::keyboardModifiers() == Qt::ControlModifier)  //如果按下了keyBoard上的ctrl键
    {
        if(event->delta()>0)
        {
            font.setPixelSize(++val);
            ui->textEdit->setFont(font);
        }
        else
        {
            font.setPixelSize(--val);
            ui->textEdit->setFont(font);
        }

    }
}
//完成了 原码中缺少引用头文件QWheelEvent
//工具：搜索
void MainWindownote::on_actionsearch_triggered()
{
    find_word = new QDialog(this);  //实例化对话框
    find_word->setWindowTitle(tr("查找")); //设置对话框标题
    findLineEdit = new QLineEdit(find_word); //文本框在对话框中
    QPushButton *btn = new QPushButton(tr("查找下一个"),find_word);

    //垂直布局 对话框和按钮
    QVBoxLayout *layout = new QVBoxLayout(find_word);
    layout->addWidget(findLineEdit);
    layout->addWidget(btn);
    QObject::connect(btn,SIGNAL(clicked()),this,SLOT(find_showSlot()));
    find_word->show();  //show一下
}
//然后完善一下刚才调用的那个函数
void MainWindownote::find_showSlot()
{
    qDebug() << "开始搜索";
    QString part = findLineEdit->text();
    bool ret = ui->textEdit->find(part,QTextDocument::FindBackward|QTextDocument::FindWholeWords);  //QTextDocument 结构化副文本框容器
    if(!ret)
    {
        QMessageBox::warning(this,tr("查找结果"),tr("未找到%1").arg(part));  //如果没找到 就输出没找到
    }
}
//这是个很鸡肋的功能 在英文写作是有点用吧...

////工具：复制
void MainWindownote::on_actioncopy_triggered()
{
    qDebug("copy");
}
//工具:剪切
void MainWindownote::on_actioncut_triggered()
{
    ui->textEdit->cut();
}
//工具:粘贴
void MainWindownote::on_actionpaste_triggered()
{
    ui->textEdit->paste();
}

//这是到了第237行

//插入图片的功能
void MainWindownote::on_actionpicture_triggered()
{
    //打开文件对话框 选择文件
    fileName = QFileDialog::getOpenFileName(this,\
                                            tr("打开"),"/",tr("Text (*.jpg *.png)"));  //'.'为默认打开的目录
    //显示到状态栏
    ui->statusbar->showMessage("will open"+fileName,3000);

    if(fileName.isEmpty())
    {
        ui->statusbar->showMessage("选择文件失败");
        return;
    }
    QTextImageFormat qtext_image_format;
    qtext_image_format.setName(fileName);  //把图片放在debug的文件夹里
    ui->textEdit->textCursor().insertImage(qtext_image_format);  //插入到textEdit里

}
//状态栏时间
void MainWindownote::time_update()
{
    //显示时间
    QDateTime current_time = QDateTime::currentDateTime();
    //设置显示的格式
    QString timestr = current_time.toString("yyyy年MM月dd日 hh:mm:ss");
    timelabel->setText(timestr);
}
//完成了

//鼠标光标
void MainWindownote::mouseMoveEvent(QMouseEvent *event)
{
    double x = event->pos().x();
    double y = event->pos().y();
    QString str = "(" + QString::number(x) + "," + QString::number(y) + ")";
    label->setText(str);
}
//对齐
//居中对齐
void MainWindownote::on_actionjuzhong_triggered()
{
    ui->textEdit->setAlignment(Qt::AlignCenter);
}
//左对齐
void MainWindownote::on_actionzuo_triggered()
{
    ui->textEdit->setAlignment(Qt::AlignLeft);
}
//右对齐
void MainWindownote::on_actionyou_triggered()
{
    ui->textEdit->setAlignment(Qt::AlignRight);
}


//字体
//宋
void MainWindownote::on_actionsong_triggered()
{
    font = ui->textEdit->font();  //获取font
    font.setFamily("SimSun");
    ui->textEdit->setFont(font);//设置

}
//黑体
void MainWindownote::on_actionhei_triggered()
{
    font = ui->textEdit->font();  //获取font
    font.setFamily("SimHei");
    ui->textEdit->setFont(font);//设置
}
//楷书
void MainWindownote::on_actionkai_triggered()
{
    font = ui->textEdit->font();  //获取font
    font.setFamily("KaiTi");
    ui->textEdit->setFont(font);//设置
}
//应该是可以导入更多字体的 但暂时不搞了
//加粗  这个代码只能实现加粗 不能改回来了 笑死我另外 我试试能不能改回来
void MainWindownote::on_actionjiacu_2_triggered()
{
    font = ui->textEdit->font();
    font.setBold(true);
    ui->textEdit->setFont(font);
}
//取消加粗
void MainWindownote::on_actiondejiacu_2_triggered()
{
    font = ui->textEdit->font();
    font.setBold(false);
    ui->textEdit->setFont(font);
}
//斜体
void MainWindownote::on_actionxieti_2_triggered()
{
    font = ui->textEdit->font();
    font.setItalic(true);
    ui->textEdit->setFont(font);
}
//取消斜体
void MainWindownote::on_actiondexieti_triggered()
{
    font = ui->textEdit->font();
    font.setItalic(false);
    ui->textEdit->setFont(font);
}
//下划线
void MainWindownote::on_actionxiahuaxian_2_triggered()
{
    font = ui->textEdit->font();
    font.setUnderline(true);
    ui->textEdit->setFont(font);
}
//取消下划线
void MainWindownote::on_actiondexiahuaxian_triggered()
{
    font = ui->textEdit->font();
    font.setUnderline(false);
    ui->textEdit->setFont(font);
}
//字体颜色
void MainWindownote::on_actionred_triggered()
{
    ui->textEdit->setTextColor(Qt::red);
}
void MainWindownote::on_actionblue_triggered()
{
    ui->textEdit->setTextColor(Qt::blue);
}
void MainWindownote::on_actiongreen_triggered()
{
    ui->textEdit->setTextColor(Qt::green);
}
//字号
void MainWindownote::on_action10_triggered()
{
    font.setPointSize(10);
    ui->textEdit->setFont(font);
}
void MainWindownote::on_action12_triggered()
{
    font.setPointSize(12);
    ui->textEdit->setFont(font);
}
void MainWindownote::on_action14_triggered()
{
    font.setPointSize(14);
    ui->textEdit->setFont(font);
}
void MainWindownote::on_action1_triggered()
{
    font.setPointSize(16);
    ui->textEdit->setFont(font);
}
void MainWindownote::on_action18_triggered()
{
    font.setPointSize(18);
    ui->textEdit->setFont(font);
}
void MainWindownote::on_action20_triggered()
{
    font.setPointSize(20);
    ui->textEdit->setFont(font);
}
void MainWindownote::on_action32_triggered()
{
    font.setPointSize(32);
    ui->textEdit->setFont(font);
}
void MainWindownote::on_action64_triggered()
{
    font.setPointSize(64);
    ui->textEdit->setFont(font);
}
//第一阶段完成


void MainWindownote::on_pushButton_clicked()
{
    MainWindow *mainwindow = new MainWindow;
    this->close();
    mainwindow->show();
}

