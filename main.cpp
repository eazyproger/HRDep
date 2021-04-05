#include <QApplication>
#include "authorization.h"
#include "database.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Database::openDatabase();
    Authorization w;
    w.show();
    return a.exec();
}
