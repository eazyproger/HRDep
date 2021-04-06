#ifndef USER_H
#define USER_H
#include "QString"
#include "QDate"

class User
{
public:
    User();
    User(QString login, QString pass);
    QString login;
    QString password;
    qint16 levelAccess;
    QString name;
    QString surname;
    QString lastName;
    qint16 personalNumber;
    QDate birthday;
    QString education;
    QString profession;
    QString post;
    qint16 divisionNumber;
    bool marritalStatus;
    qint16 numberOfChildren;
    QString divisionName;
    QString director;
};

#endif // USER_H
