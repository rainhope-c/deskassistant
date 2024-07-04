#ifndef PETWINNDOW_H
#define PETWINNDOW_H

#include <QMainWindow>

namespace Ui {
class PetWinndow;
}

class PetWinndow : public QMainWindow
{
    Q_OBJECT

public:
    explicit PetWinndow(QWidget *parent = nullptr);
    ~PetWinndow();

private:
    Ui::PetWinndow *ui;
};

#endif // PETWINNDOW_H
