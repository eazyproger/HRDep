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
    static int userIsExists(QString login, QString pass);
    static User* getUser(QString login);
    static void updateUser(User *user);
    static void deleteUser(int index);
};

#endif // DATABASE_H
