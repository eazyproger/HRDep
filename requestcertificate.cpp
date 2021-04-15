#include "requestcertificate.h"
#include "ui_requestcertificate.h"
#include "database.h"
#include <QMessageBox>
#include <QStyle>

RequestCertificate::RequestCertificate(User *user, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RequestCertificate)
{
    ui->setupUi(this);
    this->currentUser = user;
    this->setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
    this->setWindowTitle("Заказ справки");
    this->setWindowIcon(style()->standardIcon(QStyle::SP_FileIcon));
    ui->certificateType->addItem("Справка с места работы");
    ui->certificateType->addItem("Справка о доходе");
}

RequestCertificate::~RequestCertificate()
{
    delete ui;
}

void RequestCertificate::on_buttonBox_rejected()
{
    close();
}

void RequestCertificate::on_buttonBox_accepted()
{
    Database::addCertificate(currentUser->login, ui->certificateType->currentText());
    QMessageBox info(QMessageBox::NoIcon, "Информация",
                     "Справка успешно заказана. Для ее получения обратитесь к сотруднику отдела кадров.");
    info.setWindowIcon(style()->standardIcon(QStyle::SP_MessageBoxInformation));
    info.exec();
    close();
}
