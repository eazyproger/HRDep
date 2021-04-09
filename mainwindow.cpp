#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "authorization.h"
#include "changepassword.h"
#include <QMessageBox>
#include "database.h"
#include "requestcertificate.h"
#include "editwindow.h"

MainWindow::MainWindow(User *currentUser, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    this->currentUser = currentUser;
    this->userList = Database::userList;
    this->setWindowTitle("Отдел Кадров");
    this->setWindowIcon(QIcon(":/img/icon/main.png"));

    this->setFixedSize(width(), height());

    initUserMenu();
    if (currentUser->levelAccess > 1)
    {
        initHRMenu();
        ui->editUser->setEnabled(false);
        ui->deleteUser->setEnabled(false);
    }
    if (currentUser->levelAccess==3)
    {
        initAdminMenu();
    }




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


void MainWindow::initUserMenu()
{
    ui->tabWidget->setTabVisible(1,false);
    ui->tabWidget->setTabVisible(2,false);

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

    ui->personalNumber->setFrame(false);
    ui->post->setFrame(false);
    ui->divisionNumber->setFrame(false);
    ui->divisionName->setFrame(false);
    ui->director->setFrame(false);

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

void MainWindow::initHRMenu()
{
    ui->tabWidget->setTabVisible(1,true);
    ui->userTable->setColumnCount(13);
    ui->userTable->horizontalHeader()->setHighlightSections(false);
    ui->userTable->setEditTriggers(QAbstractItemView::NoEditTriggers);

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
    ui->userTable->setHorizontalHeaderLabels(columnsNames);
    ui->userTable->setRowCount(this->userList.length());
    for(int i = 0; i < this->userList.length(); i++)
    {
        for (int j = 0; j < ui->userTable->columnCount(); j++)
        {
            QTableWidgetItem *newItem = new QTableWidgetItem(userList[i]->getItem(j));
            newItem->setTextAlignment(Qt::AlignCenter);
            ui->userTable->setItem(i, j , newItem);
        }
    }
    resizeTable(ui->userTable);
}

void MainWindow::initAdminMenu()
{
    ui->tabWidget->setTabVisible(2,true);
}

void MainWindow::resizeTable(QTableWidget *userTable)
{
    userTable->resizeColumnsToContents();
    userTable->resizeRowsToContents();
    QHeaderView *header = userTable->horizontalHeader();
    header->setSectionResizeMode(11, QHeaderView::Stretch);
}

void MainWindow::on_editUser_clicked()
{
    EditWindow *editWindow = new EditWindow(userList[ui->userTable->currentRow()]);
    editWindow->exec();
    initHRMenu();
}

void MainWindow::on_userTable_cellClicked(int row, int column)
{
    ui->editUser->setEnabled(true);
    ui->deleteUser->setEnabled(true);
}

void MainWindow::on_userTable_cellDoubleClicked(int row, int column)
{
    ui->editUser->setEnabled(true);
    ui->deleteUser->setEnabled(true);
    EditWindow *editWindow = new EditWindow(userList[ui->userTable->currentRow()]);
    editWindow->exec();
    initHRMenu();
}

void MainWindow::on_deleteUser_clicked()
{
    if (currentUser != userList[ui->userTable->currentRow()])
    {
        if (currentUser->personalNumber!=0)
        {
        Database::deleteUser(ui->userTable->currentRow());
        QMessageBox info(QMessageBox::NoIcon, "Информация",
                         "Работник уволен!");
        info.setWindowIcon(style()->standardIcon(QStyle::SP_MessageBoxInformation));
        info.exec();
        }
        else
        {
            QMessageBox info(QMessageBox::NoIcon, "Информация",
                             "Вы не можете уволить администратора!");
            info.setWindowIcon(style()->standardIcon(QStyle::SP_MessageBoxInformation));
            info.exec();
        }
    }
    else
    {
        QMessageBox info(QMessageBox::NoIcon, "Информация",
                         "Вы не можете уволить самого себя!");
        info.setWindowIcon(style()->standardIcon(QStyle::SP_MessageBoxInformation));
        info.exec();
    }
}
