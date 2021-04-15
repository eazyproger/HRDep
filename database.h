#ifndef DATABASE_H
#define DATABASE_H
#include <QString>
#include "user.h"
#include <QList>

class Database
{
private:
    static const QString DATABASE;
    static const QString CERTIFICATES;
public:
    static QList<User *> userList;
    static QList<QStringList> certificateList;
    static void openDatabase();
    static void addNewUser(QString login, QString pass);
    static void updateDatabase();
    static void addNewUserIntoDatabase();
    static int userIsExists(QString login, QString pass);
    static User* getUser(qint16 personalNumber);
    static User *getUser(QString login);
    static void updateUser(User *user);
    static void deleteUser(qint16 personalNumber);
    static void addCertificate(QString login, QString certificateType);
    static QList<QStringList> getCetificateList();
    static void deleteCertificate(QString login, QString certificateType);
};

#endif // DATABASE_H
