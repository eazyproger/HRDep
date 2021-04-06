#include "registration.h"
#include "ui_registration.h"
#include "database.h"
#include <QMessageBox>
#include "authorization.h"

Registration::Registration(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Registration)
{
    ui->setupUi(this);
    this->setWindowTitle("Регистрация");
    this->setWindowIcon(QIcon(":/img/icon/edit.png"));
    this->setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint); // убрал вопрос
    ui->marritalStatus->addItem("");
}

Registration::~Registration()
{
    delete ui;
}

void Registration::on_okCancelRegistration_accepted()
{
    if (!ui->name->text().isEmpty() && !ui->surname->text().isEmpty() &&
            !ui->lastName->text().isEmpty() && !ui->education->text().isEmpty() &&
            !ui->profession->text().isEmpty() && !(ui->marritalStatus->currentText().isEmpty()))
    {
        User *newUser = Database::userList.last();
        newUser->name = ui->name->text();
        newUser->surname = ui->surname->text();
        newUser->lastName = ui->lastName->text();
        newUser->birthday = ui->birthday->date();
        newUser->education = ui->education->text();
        newUser->profession = ui->profession->text();
        if(ui->marritalStatus->currentText()=="Женат" || ui->marritalStatus->currentText()=="Замужем")
        {
            newUser->marritalStatus = true;
        }
        else
        {
            newUser->marritalStatus = false;
        }
        newUser->numberOfChildren = ui->numberOfChildren->value();
        Database::addNewUserIntoDatabase();
        QMessageBox info(QMessageBox::NoIcon, "Информация","");
        info.setWindowIcon(style()->standardIcon(QStyle::SP_MessageBoxInformation));
        if (Database::userList.length()==1)
        {
            info.setText("Вы успешно зарегистрировались!");
        }
        else
        {
            info.setText("Вы успешно зарегистрировались! Дождитесь подтверждения учетной записи работником отдела кадров.");
        }
        info.exec();
        this->close();
        Authorization w;
        w.exec();
    }
    else
    {
        QMessageBox info(QMessageBox::NoIcon, "Информация",
                         "Не все поля заполнены!");
        info.setWindowIcon(style()->standardIcon(QStyle::SP_MessageBoxInformation));
        info.exec();
    }
}

void Registration::on_okCancelRegistration_rejected()
{
    Database::userList.removeLast();
    this->close();
}

void Registration::on_lastName_textChanged(const QString &arg1)
{
    if(ui->lastName->text().right(3)=="вич")
    {
        ui->marritalStatus->clear();
        ui->marritalStatus->addItem("Женат");
        ui->marritalStatus->addItem("Холост");
    }
    else if(ui->lastName->text().right(3)=="вна")
    {
        ui->marritalStatus->clear();
        ui->marritalStatus->addItem("Замужем");
        ui->marritalStatus->addItem("Не замужем");
    }
}
