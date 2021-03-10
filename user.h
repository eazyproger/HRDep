#ifndef USER_H
#define USER_H
#include "QString"
#include "QDate"

class User
{
public:
    User();
    User(QString name, QString surname, QString lastname, QDate birthday, QString education,
         QString profession, QString marritalStatus, int numberOfChildren);
private:
    QString name;
    QString surname;
    QString lastname;
    int personalNumber;
    QDate birthday;
    QString education;
    QString profession;
    QString post;
    int divisionNumber;
    QString marritalStatus;
    int numberOfChildren;
    QString divisionName;
    QString director;
};

#endif // USER_H
