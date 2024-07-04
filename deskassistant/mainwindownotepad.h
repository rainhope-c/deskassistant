#ifndef MAINWINDOWNOTEPAD_H
#define MAINWINDOWNOTEPAD_H

#include <QTextEdit>
#include <QLabel>
#include <QMainWindow>

namespace Ui {
class MainWindownotepad;
}

class MainWindownotepad : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindownotepad(QWidget *parent = nullptr);
    ~MainWindownotepad();

    //主要文本区
    QTextEdit *textEdit = new QTextEdit();
    //标签
    QLabel *labelText;
    QLabel *labelText2;
    QLabel *labelText3;
    QLabel *labelText4;
    //当前文件
    QString currentFile;
    //状态栏动作
    QAction *actionStatus;



private:
    Ui::MainWindownotepad *ui;
};

#endif // MAINWINDOWNOTEPAD_H
