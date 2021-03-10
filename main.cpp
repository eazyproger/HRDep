#include "mainwindow.h"
#include "userwindow.h"
#include "registration.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Registration w;
    w.show();

    return a.exec();
}
