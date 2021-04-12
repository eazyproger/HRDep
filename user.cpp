#include "user.h"
#include "database.h"

User::User()
{

}

User::User(QString login, QString pass)
{
    this->login = login;
    this->password = pass;
    if (Database::userList.length()>0)
    {
        this->personalNumber = Database::userList.last()->personalNumber + 1;
        this->levelAccess = 0;
    }
    else
    {
        this->levelAccess = 3;
        this->personalNumber = 1;
    }
    this->post = "Не указана";
    this->divisionNumber = 0;
    this->divisionName = "Не указано";
    this->director = "Не указан";
}

QString User::getItem(int i)
{
    switch (i) {
    case 0:
        return this->surname;
    case 1:
        return this->name;
    case 2:
        return this->lastName;
    case 3:
        return QString::number(this->personalNumber);
    case 4:
        return this->birthday.toString();
    case 5:
        return this->education;
    case 6:
        return this->profession;
    case 7:
        return this->post;
    case 8:
        if (divisionNumber!=0)
        {
            return QString::number(this->divisionNumber);
        }
        else
        {
            return "Не указан";
        }
    case 9:
        if (this->marritalStatus==true)
        {
            if (this->lastName.right(3)=="вич")
            {
                return "Женат";
            }
            else
            {
                return "Замужем";
            }
        }
        else
        {
            if (this->lastName.right(3)=="вич")
            {
                return "Не женат";
            }
            else
            {
                return "Не замужем";
            }
        }
    case 10:
        return QString::number(this->numberOfChildren);
    case 11:
        return this->divisionName;
    case 12:
        return this->director;
    }
}
