#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_tbM_C_clicked();
    void on_tbM_T_clicked();



    void on_tpM_N_clicked();

    void on_tbM_P_clicked();


    void on_toolButton_8_clicked();

    void on_toolButton_6_clicked();

    void on_toolButton_clicked();

    void on_toolButton_9_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
