#include "changepassword.h"
#include "ui_changepassword.h"
#include <QMessageBox>
#include <QStyle>

ChangePassword::ChangePassword(User *user, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChangePassword)
{
    ui->setupUi(this);
    this->user = user;
    this->setWindowTitle("Изменение пароля");
    this->setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
    this->setWindowIcon(style()->standardIcon(QStyle::SP_VistaShield));
}

ChangePassword::~ChangePassword()
{
    delete ui;
}

void ChangePassword::on_okCancelButton_rejected()
{
    this->close();
}

void ChangePassword::on_okCancelButton_accepted()
{
    if (this->user->password == ui->oldPassword->text())
    {
        if (ui->newPassword->text()==ui->newPassword2->text())
        {
            this->user->password = ui->newPassword->text();
            QMessageBox info(QMessageBox::NoIcon, "Информация",
                             "Пароль успешно изменен!");
            info.setWindowIcon(style()->standardIcon(QStyle::SP_MessageBoxInformation));
            info.exec();
            this->close();

        }
        else
        {
            QMessageBox info(QMessageBox::NoIcon, "Информация",
                             "Пароли не совпадают!");
            info.setWindowIcon(style()->standardIcon(QStyle::SP_MessageBoxInformation));
            info.exec();
        }
    }
    else
    {
        QMessageBox info(QMessageBox::NoIcon, "Информация",
                         "Неверно введен старый пароль!");
        info.setWindowIcon(style()->standardIcon(QStyle::SP_MessageBoxInformation));
        info.exec();
    }
}
