#include "mainwindow.h"

#include <QApplication>
#include <iostream>
#include "model/wallet.h"

int main(int argc, char *argv[])
{

    Wallet wallet;


    QApplication a(argc, argv);
    MainWindow w(&wallet);
    w.show();
    return a.exec();
}
