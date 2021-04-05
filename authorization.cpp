#include "authorization.h"
#include "ui_authorization.h"
#include "database.h"
#include "registration.h"
#include <QMessageBox>

Authorization::Authorization(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Authorization)
{
    ui->setupUi(this);
    this->setWindowTitle("Авторизация");
    this->setWindowIcon(QIcon(":/img/icon/authorization.png"));
    this->setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
    ui->infoLabel->setVisible(false);

    if (Database::userList.length()==0) //проверка на наличие записей в базе, если нет то нужен хотя бы админ
    {
        ui->logInButton->setDisabled(true);
        ui->infoLabel->setVisible(true);
    }

}

Authorization::~Authorization()
{
    delete ui;
}



void Authorization::on_registrationButton_clicked()
{
    QString login = ui->loginLine->text();
    QString pass = ui->passLine->text();
    if (!login.isEmpty() && !pass.isEmpty())
    {
        Database::addNewUser(login, pass);
        this->close();
    }
    else
    {
        QMessageBox info;
        info.setText("Поля логин и пароль не могут быть пустыми!");
        info.exec();
    }
}

void Authorization::on_logInButton_clicked()
{
    if (Database::userIsExists(ui->loginLine->text(), ui->passLine->text()))
    {
        QMessageBox info;
        info.setText("ok");
        info.exec();

    }
    else
    {
        QMessageBox info;
        info.setText("Данные введены не верно!");
        info.exec();
    }
}
