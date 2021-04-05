#include "database.h"
#include <QFile>
#include <QDataStream>
#include <QString>
#include "QList"
#include "user.h"
#include <QDate>
#include "QMessageBox"
#include "registration.h"


QList<User *> Database::userList;
const QString Database::DATABASE = "db2.dat";

void Database::openDatabase()
{
    QFile db(DATABASE);
    if (db.open(QIODevice::ReadOnly))
    {
        QDataStream stream(&db);
        while(!stream.atEnd())
        {
            User *user = new User();
            stream >> user->login
                    >> user->password
                    >> user->name
                    >> user->surname
                    >> user->lastName
                    >> user->personalNumber
                    >> user->birthday
                    >> user->education
                    >> user->profession
                    >> user->post
                    >> user->divisionNumber
                    >> user->marritalStatus
                    >> user->numberOfChildren
                    >> user->divisionName
                    >> user->director;
            userList  << user;
        }
        db.close();
    }
}

void Database::addNewUser(QString login, QString pass)
{
    bool loginAvailable = true;
    for (int i = 0; i < userList.length(); i++)
    {
        if (userList[i]->login == login)
        {
            loginAvailable = false;
            break;
        }
    }
    if (loginAvailable)
    {
        User *newUser = new User(login, pass);
        userList.append(newUser);
        Registration w;
        w.exec();
    }
    else
    {
        QMessageBox info;
        info.setText("Данный логин занят!");
        info.exec();
    }

}



void Database::updateDatabase()
{

}

void Database::addNewUserIntoDatabase()
{
    User *user = Database::userList.last();
    QFile db(DATABASE);
    if (db.open(QIODevice::Append))
    {
        QDataStream stream(&db);
            stream << user->login
                    << user->password
                    << user->name
                    << user->surname
                    << user->lastName
                    << user->personalNumber
                    << user->birthday
                    << user->education
                    << user->profession
                    << user->post
                    << user->divisionNumber
                    << user->marritalStatus
                    << user->numberOfChildren
                    << user->divisionName
                    << user->director;
        db.close();
    }
}

bool Database::userIsExists(QString login, QString pass)
{
    for (int i = 0; i < userList.length(); i++)
    {
        if (userList[i]->login == login)
        {
            if (userList[i]->password == pass)
            {
                return true;
            }
        }
    }
    return false;
}
