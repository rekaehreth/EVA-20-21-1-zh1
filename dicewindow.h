#ifndef DICEWINDOW_H
#define DICEWINDOW_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class DiceWindow; }
QT_END_NAMESPACE

class DiceWindow : public QWidget
{
    Q_OBJECT

public:
    DiceWindow(QWidget *parent = nullptr);
    ~DiceWindow();

private:
    Ui::DiceWindow *ui;
};
#endif // DICEWINDOW_H
