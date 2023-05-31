#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = 0);
    ~MainWindow();
    bool checkIfWon();
    void setPlayerTurn();

private slots:
    void on_newGameButton_clicked();
    void onGridButtonClicked();
private:
    char symbols[2];
    int playerTurn;
    Ui::MainWindow* ui;
};

#endif // MAINWINDOW_H
