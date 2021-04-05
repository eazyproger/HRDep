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
    QString name;
    QString surname;
    QString lastName;
    qint16 personalNumber;
    QDate birthday;
    QString education;
    QString profession;
    QString post;
    qint16 divisionNumber;
    QString marritalStatus;
    qint16 numberOfChildren;
    QString divisionName;
    QString director;
};

#endif // USER_H
