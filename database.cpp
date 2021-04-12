#include "database.h"
#include <QFile>
#include <QDataStream>
#include <QString>
#include "QList"
#include "user.h"
#include <QDate>
#include "QMessageBox"
#include "registration.h"
#include <QStyle>
#include "authorization.h"


QList<User *> Database::userList;
const QString Database::DATABASE = "db3.dat";

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
                    >> user->levelAccess
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
        QMessageBox info(QMessageBox::NoIcon, "Информация",
                         "Данный логин занят!");
        info.setWindowIcon(info.style()->standardIcon(QStyle::SP_MessageBoxInformation));
        info.exec();
        Authorization w;
        w.exec();
    }

}



void Database::updateDatabase()
{
    QFile db(DATABASE);
    if (db.open(QIODevice::WriteOnly))
    {
        QDataStream stream(&db);
        for (int i = 0; i < userList.length(); i++)
        {
            stream << userList[i]->login
                    << userList[i]->password
                    << userList[i]->levelAccess
                    << userList[i]->name
                    << userList[i]->surname
                    << userList[i]->lastName
                    << userList[i]->personalNumber
                    << userList[i]->birthday
                    << userList[i]->education
                    << userList[i]->profession
                    << userList[i]->post
                    << userList[i]->divisionNumber
                    << userList[i]->marritalStatus
                    << userList[i]->numberOfChildren
                    << userList[i]->divisionName
                    << userList[i]->director;
        }
        db.close();
    }
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
                    << user->levelAccess
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

int Database::userIsExists(QString login, QString pass)
{
    //если найден возращает уровень доступа, иначе -1
    for (int i = 0; i < userList.length(); i++)
    {
        if (userList[i]->login == login)
        {
            if (userList[i]->password == pass)
            {
                return userList[i]->levelAccess;
            }
        }
    }
    return -1;
}

User* Database::getUser(qint16 personalNumber)
{
    for (int i = 0; i < userList.length(); i++)
    {
        if (userList[i]->personalNumber == personalNumber)
        {
                return userList[i];
        }
    }
}

User *Database::getUser(QString login)
{
    for (int i = 0; i < userList.length(); i++)
    {
        if (userList[i]->login == login)
        {
                return userList[i];
        }
    }
}

void Database::updateUser(User *user)
{
    for (int i = 0; i < userList.length(); i++)
    {
        if (userList[i]->login == user->login)
        {
                userList[i] = user;
        }
    }
}

void Database::deleteUser(qint16 personalNumber)
{
    userList.removeOne(getUser(personalNumber));
    updateDatabase();
}
