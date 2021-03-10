#include "authorization.h"
#include "ui_authorization.h"

Authorization::Authorization(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Authorization)
{
    ui->setupUi(this);
    this->setWindowTitle("Авторизация");
    this->setWindowIcon(QIcon(":/img/icon/authorization.png"));
    this->setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint); // убрал вопрос

}

Authorization::~Authorization()
{
    delete ui;
}
