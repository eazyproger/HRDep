#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "authorization.h"
#include "changepassword.h"
#include <QMessageBox>
#include "database.h"
#include "requestcertificate.h"

MainWindow::MainWindow(User *currentUser, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    this->currentUser = currentUser;
    this->setWindowTitle("Отдел Кадров");
    this->setWindowIcon(QIcon(":/img/icon/main.png"));

    this->setFixedSize(width(), height());

    if (currentUser->levelAccess==1)
    {
        ui->tabWidget->setTabVisible(1,false);
        ui->tabWidget->setTabVisible(2,false);
    }
    else if (currentUser->levelAccess==2)
    {
        ui->tabWidget->setTabVisible(2,false);
    }

    ui->mainTable->setColumnCount(13);
    ui->mainTable->setRowCount(13);

    QStringList columnsNames;
    columnsNames.append(QString("Фамилия"));
    columnsNames.append(QString("Имя"));
    columnsNames.append(QString("Отчество"));
    columnsNames.append(QString("Личный\nномер"));
    columnsNames.append(QString("Дата\nрождения"));
    columnsNames.append(QString("Образование"));
    columnsNames.append(QString("Профессия"));
    columnsNames.append(QString("Должность"));
    columnsNames.append(QString("Номер\nподразделения"));
    columnsNames.append(QString("Семейное\nположение"));
    columnsNames.append(QString("Количество\nдетей"));
    columnsNames.append(QString("Название\nподразделения"));
    columnsNames.append(QString("Руководитель"));
    ui->mainTable->setHorizontalHeaderLabels(columnsNames);

    ui->name->setText(currentUser->name);
    ui->surname->setText(currentUser->surname);
    ui->lastName->setText(currentUser->lastName);
    ui->personalNumber->setText(QString::number(currentUser->personalNumber));
    ui->birthday->setDate(currentUser->birthday);
    ui->education->setText(currentUser->education);
    ui->post->setText(currentUser->post);
    ui->profession->setText(currentUser->profession);
    if(currentUser->divisionNumber!=0)
    {
        ui->divisionNumber->setText(QString::number(currentUser->divisionNumber));
    }
    else
    {
        ui->divisionNumber->setText("Не указан");
    }
    if (currentUser->lastName.right(3)=="вич")
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
    if (currentUser->marritalStatus)
    {
        ui->marritalStatus->setCurrentIndex(0);
    }
    else
    {
        ui->marritalStatus->setCurrentIndex(1);
    }
    ui->numberOfChildren->setValue(currentUser->numberOfChildren);
    ui->divisionName->setText(currentUser->divisionName);
    ui->director->setText(currentUser->director);
    ui->personalNumber->setReadOnly(true);
    ui->post->setReadOnly(true);
    ui->divisionNumber->setReadOnly(true);
    ui->divisionName->setReadOnly(true);
    ui->director->setReadOnly(true);

    ui->saveChanges->setEnabled(false);

    connect(ui->name, SIGNAL(textChanged(QString)), this, SLOT(updateCurrentUser()));
    connect(ui->surname, SIGNAL(textChanged(QString)), this, SLOT(updateCurrentUser()));
    connect(ui->lastName, SIGNAL(textChanged(QString)), this, SLOT(updateCurrentUser()));
    connect(ui->birthday, SIGNAL(dateChanged(QDate)), this, SLOT(updateCurrentUser()));
    connect(ui->education, SIGNAL(textChanged(QString)), this, SLOT(updateCurrentUser()));
    connect(ui->profession, SIGNAL(textChanged(QString)), this, SLOT(updateCurrentUser()));
    connect(ui->marritalStatus, SIGNAL(currentTextChanged(QString)), this, SLOT(updateCurrentUser()));
    connect(ui->numberOfChildren, SIGNAL(valueChanged(int)), this, SLOT(updateCurrentUser()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateCurrentUser()
{
    ui->saveChanges->setEnabled(true);
    currentUser->name = ui->name->text();
    currentUser->surname = ui->surname->text();
    currentUser->lastName = ui->lastName->text();
    currentUser->birthday = ui->birthday->date();
    currentUser->education = ui->education->text();
    currentUser->profession = ui->profession->text();
    if(ui->marritalStatus->currentText()=="Женат" || ui->marritalStatus->currentText()=="Замужем")
    {
        currentUser->marritalStatus = true;
    }
    else
    {
        currentUser->marritalStatus = false;
    }
    currentUser->numberOfChildren = ui->numberOfChildren->value();

}


void MainWindow::on_tabWidget_currentChanged(int index)
{
    this->showNormal();
    if (index>0)
    {

        this->setFixedSize(QWIDGETSIZE_MAX, QWIDGETSIZE_MAX);
        this->showMaximized();
    }
}
void MainWindow::on_logOut_triggered()
{
    Authorization *w = new Authorization();
    w->show();
    close();
}

void MainWindow::on_changePassword_clicked()
{
    ChangePassword w(this->currentUser);
    w.exec();
    Database::updateDatabase();
}

void MainWindow::on_saveChanges_clicked()
{
    Database::updateDatabase();
    QMessageBox info(QMessageBox::NoIcon, "Информация",
                     "Изменения внесены в базу данных!");
    info.setWindowIcon(style()->standardIcon(QStyle::SP_MessageBoxInformation));
    info.exec();
    ui->saveChanges->setEnabled(false);
}



void MainWindow::on_requestCertificate_clicked()
{
        RequestCertificate w;
        w.exec();
}
