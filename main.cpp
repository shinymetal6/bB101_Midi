#include "bb101_midi_mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    bB101_Midi_MainWindow w;
    w.show();
    return a.exec();
}

