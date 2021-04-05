#ifndef DATABASE_H
#define DATABASE_H
#include <QString>
#include "user.h"
#include <QList>

class Database
{
private:
    static const QString DATABASE;
public:
    static QList<User *> userList;
    static void openDatabase();
    static void addNewUser(QString login, QString pass);
    static void updateDatabase();
    static void addNewUserIntoDatabase();
    static bool userIsExists(QString login, QString pass);
};

#endif // DATABASE_H
