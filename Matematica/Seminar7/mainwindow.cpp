#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <cstdlib>
#include <cstring>
#include <iostream>
#include <QMessageBox>

MainWindow::MainWindow(QWidget* parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->gamesWon1->setText("0");
    ui->gamesWon2->setText("0");

    // initialize player list
    symbols[0] = 1;
    symbols[1] = 2;

    // set player index
    playerTurn = 1 + rand() % 2;

    ui->status->setText(QString("Player %1's turn").arg(playerTurn));

    for (int i = 0; i < ui->gridLayout->rowCount(); i++)
        for (int j = 0; j < ui->gridLayout->columnCount(); j++) {
            QLayoutItem* item = ui->gridLayout->itemAtPosition(i, j);
            if (item->widget()) {
                QPushButton* btn = qobject_cast<QPushButton*>(item->widget());
                connect(btn, &QPushButton::clicked, this, &MainWindow::onGridButtonClicked);
            }
        }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_newGameButton_clicked()
{
    //QString XMAX = ui->gamesPlayed->text();
    //int value = XMAX.toInt() + 1;
    //ui->gamesPlayed->setText(QString("%1").arg(value));
    playerTurn = 1 + rand() % 2;

    ui->status->setText(QString("Player %1's turn").arg(playerTurn));

    for (int i = 0; i < ui->gridLayout->rowCount(); i++)
        for (int j = 0; j < ui->gridLayout->columnCount(); j++) {
            QLayoutItem* item = ui->gridLayout->itemAtPosition(i, j);
            if (item->widget()) {
                QPushButton* btn = qobject_cast<QPushButton*>(item->widget());
                btn->setText("");
            }
        }
}

void MainWindow::onGridButtonClicked()
{
    QPushButton* gridButton = qobject_cast<QPushButton*>(sender());

    QString value = gridButton->text();
    int convertedValue = value.toInt();
    if ((convertedValue == symbols[0]) || (convertedValue == symbols[1])) return;

    gridButton->setText(QString("%1").arg(playerTurn));

    bool won = checkIfWon();
    if (won) {
        ui->status->setText(QString("Player %1 won").arg(playerTurn));
        QLineEdit* noGamesWon = playerTurn == 1 ? ui->gamesWon1 : ui->gamesWon2;
        int noGamesWonInt = noGamesWon->text().toInt() + 1;
        noGamesWon->setText(QString("%1").arg(noGamesWonInt));
    }
    else {
        setPlayerTurn();
        ui->status->setText(QString("Player %1's turn").arg(playerTurn));
    }    
}

void MainWindow::setPlayerTurn() {
    playerTurn = ((playerTurn == symbols[0]) ? symbols[1] : symbols[0]);
}

bool MainWindow::checkIfWon() {
    int positions[8][3][2] = {
        {{0, 0}, {0, 1}, {0, 2}},
        {{1, 0}, {1, 1}, {1, 2}},
        {{2, 0}, {2, 1}, {2, 2}},
        {{0, 0}, {1, 0}, {2, 0}},
        {{0, 1}, {1, 1}, {1, 2}},
        {{0, 2}, {1, 2}, {2, 2}},
        {{0, 0}, {1, 1}, {2, 2}},
        {{0, 2}, {1, 1}, {2, 0}},
    };

    for (int i = 0; i < 8; i++) {
        QPushButton* item1 = qobject_cast<QPushButton*>(ui->gridLayout->itemAtPosition(positions[i][0][0], positions[i][0][1])->widget());
        QPushButton* item2 = qobject_cast<QPushButton*>(ui->gridLayout->itemAtPosition(positions[i][1][0], positions[i][1][1])->widget());
        QPushButton* item3 = qobject_cast<QPushButton*>(ui->gridLayout->itemAtPosition(positions[i][2][0], positions[i][2][1])->widget());
        if (
            (
                (item1->text() != "")
                && (item2->text() != "")
                && (item3->text() != "")
            )
            && (item1->text() == item2->text())
            && (item2->text() == item3->text())
        ) return true;
    }

    return false;
}
