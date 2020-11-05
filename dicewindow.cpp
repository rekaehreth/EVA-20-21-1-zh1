#include "dicewindow.h"
#include "ui_dicewindow.h"

DiceWindow::DiceWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::DiceWindow)
{
    ui->setupUi(this);
    ui->handicapLineEdit->setText( QString::number(0) );
}

DiceWindow::~DiceWindow()
{
    delete ui;
}

bool DiceWindow::validateInput() {
    bool res = false;
    ui->handicapLineEdit->text().toInt( &res );
    if ( ui->dLineEdit->text().toInt( &res ) < 4 ) return false;
    if ( ui->numLineEdit->text().toInt( &res ) < 1 ) return false;
    return res;
}

void DiceWindow::on_rollButton_clicked()
{
    bool ok = validateInput();
    if ( ok ) {
        int curRoll;
        int res = 0;
        QString resString = "Roll " + ui->numLineEdit->text() + "d" + ui->dLineEdit->text() + "+" + ui->handicapLineEdit->text() + ": (";
        for ( int i = 0; i < ui->numLineEdit->text().toInt(); ++i ) {
            curRoll = QRandomGenerator::global()->generate() % ( ui->dLineEdit->text().toInt() + 1 );
            res += curRoll;
            resString += QString::number( curRoll );
            if ( i == ui->numLineEdit->text().toInt() - 1 ) {
                resString += ") + ";
            } else {
                resString += " + ";
            }
        }
        res += ui->handicapLineEdit->text().toInt();
        resString += ui->handicapLineEdit->text() + " = " + QString::number( res );
        ui->resultlcdNumber->display( res );
        ui->historyListWidget->addItem( resString );
    } else {
        QMessageBox *pauseDialog = new QMessageBox();
        pauseDialog->setText( "Every input field should contain a number\nNumber of dices have to be at least 1\nd should be at least 4" );
        pauseDialog->exec();
    }

}
