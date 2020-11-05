#ifndef DICE_H
#define DICE_H

#include <QObject>
#include <QString>

class dice : public QObject
{
    Q_OBJECT
    bool validateInput();
    int minRoll;
    int maxRoll;
    QString rollDice();
public:
    explicit dice(QObject *parent = nullptr);

signals:

};

#endif // DICE_H
