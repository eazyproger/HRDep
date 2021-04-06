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
