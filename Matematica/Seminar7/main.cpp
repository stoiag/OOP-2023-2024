#include "mainwindow.h"
#include <QApplication>

// TO DO inainte de rulat proiectul:
// instalat Qt de la https://www.qt.io/download-open-source (~30 min, 36GB) (*)
// (de asemenea, când ati instalat VS, trebuie sa aveti disponibile si pachetele mentionate la
// https://stackoverflow.com/questions/42258311/cannot-open-include-file-ctype-h-no-such-file-or-directory)
// daca folositi VS, instalat de la Extensions->Manage extensions->cautati dupa qt->Qt Visual Studio Tools
// Dupa ce reporniti VS, aveti posibilitatea sa creati un proiect Empty Qt project.
// Setati calea pentru Qt instalat la (*) prin selectia Extension-> Qt VS Tools -> Qt Versions,
// cautati calea pentru qmake.exe instalata (ex. D:\Qt\6.5.1\msvc2019_64\bin)
// Daca IDE-ul da eroare la instructiunile include pentru pachete Qt,
// setati Extensions->Qt VS Tools->Qt Project Settings->sectiunea Qt Project Settings->subsectiunea Qt Modules, si
// adaugati core;gui;widgets.
// Exemplu tutorial: https://doc.qt.io/qt-6/qtwidgets-tutorials-notepad-example.html

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
