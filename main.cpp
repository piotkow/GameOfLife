#include "mainwindow.h"
#include "tests.h"
#include "Game.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    neighbours_test();
    rules_test();
    return a.exec();
}
