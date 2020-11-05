#ifndef DICEWINDOW_H
#define DICEWINDOW_H

#include <QWidget>
#include <QRandomGenerator>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class DiceWindow; }
QT_END_NAMESPACE

class DiceWindow : public QWidget
{
    Q_OBJECT

public:
    DiceWindow(QWidget *parent = nullptr);
    ~DiceWindow();

private slots:
    void on_rollButton_clicked();

private:
    Ui::DiceWindow *ui;

    bool validateInput();
};
#endif // DICEWINDOW_H
