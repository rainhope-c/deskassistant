#ifndef MAINWINDOWCALENDAR_H
#define MAINWINDOWCALENDAR_H

#include <QMainWindow>

namespace Ui {
class MainWindowcalendar;
}

class MainWindowcalendar : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindowcalendar(QWidget *parent = nullptr);
    ~MainWindowcalendar();

private slots:

    void on_tbC_M_clicked();

private:
    Ui::MainWindowcalendar *ui;
};

#endif // MAINWINDOWCALENDAR_H
