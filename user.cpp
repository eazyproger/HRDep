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
    }
    else
    {
        this->personalNumber = 0;
    }
    this->post = "Не указана";
    this->divisionNumber = 0;
    this->divisionName = "Не указано";
    this->director = "Не указан";
}
