#include "dice.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dice w;
    w.show();
    return a.exec();
}
