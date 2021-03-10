#include "registration.h"
#include "ui_registration.h"
#include "QMessageBox"

Registration::Registration(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Registration)
{
    ui->setupUi(this);
    this->setWindowTitle("Регистрация");
    this->setWindowIcon(QIcon(":/img/icon/edit.png"));
    this->setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint); // убрал вопрос
}

Registration::~Registration()
{
    delete ui;
}

void Registration::on_okCancelRegistration_accepted()
{

}
