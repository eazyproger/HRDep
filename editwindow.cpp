#include "editwindow.h"
#include "ui_editwindow.h"
#include <QMessageBox>
#include <QStyle>
#include "database.h"

EditWindow::EditWindow(User *user, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Редактирование");
    this->setWindowIcon(style()->standardIcon(QStyle::SP_DialogResetButton));
    this->setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);

    currentUser = user;

    for (int i = 0; i < divisionNames.length(); i++)
    {
        ui->divisionNumber->addItem(QString::number(i));
        ui->divisionName->addItem(divisionNames[i]);
    }

    ui->name->setText(user->name);
    ui->surname->setText(user->surname);
    ui->lastName->setText(user->lastName);
    ui->personalNumber->setText(QString::number(user->personalNumber));
    ui->birthday->setText(user->birthday.toString());
    ui->education->setText(user->education);
    ui->post->setText(user->post);
    ui->profession->setText(user->profession);
    for (int i = 0; i < divisionNames.length(); i++)
    {
        if (user->divisionNumber==i)
        {
            ui->divisionNumber->setCurrentIndex(i);
            ui->divisionName->setCurrentIndex(i);
        }
    }
    if (user->lastName.right(3)=="вич")
    {
        if (user->marritalStatus)
        {
            ui->marritalStatus->setText("Женат");
        }
        else
        {
            ui->marritalStatus->setText("Не женат");
        }
    }
    else if(ui->lastName->text().right(3)=="вна")
    {
        if (user->marritalStatus)
        {
            ui->marritalStatus->setText("Замужем");
        }
        else
        {
            ui->marritalStatus->setText("Не замужем");
        }
    }
    ui->numberOfChildren->setText(QString::number(user->numberOfChildren));
    ui->director->setText(user->director);

    ui->name->setReadOnly(true);
    ui->surname->setReadOnly(true);
    ui->lastName->setReadOnly(true);
    ui->birthday->setReadOnly(true);
    ui->personalNumber->setReadOnly(true);
    ui->education->setReadOnly(true);
    ui->profession->setReadOnly(true);
    ui->marritalStatus->setReadOnly(true);
    ui->numberOfChildren->setReadOnly(true);

    ui->name->setFrame(false);
    ui->surname->setFrame(false);
    ui->lastName->setFrame(false);
    ui->birthday->setFrame(false);
    ui->personalNumber->setFrame(false);
    ui->education->setFrame(false);
    ui->profession->setFrame(false);
    ui->marritalStatus->setFrame(false);
    ui->numberOfChildren->setFrame(false);

}

EditWindow::~EditWindow()
{
    delete ui;
}

void EditWindow::on_divisionNumber_currentIndexChanged(int index)
{
    ui->divisionName->setCurrentIndex(index);
}

void EditWindow::on_divisionName_currentIndexChanged(int index)
{
    ui->divisionNumber->setCurrentIndex(index);
}

void EditWindow::on_okCancelButton_rejected()
{
    close();
}

void EditWindow::on_okCancelButton_accepted()
{
    currentUser->divisionName = ui->divisionName->currentText();
    currentUser->divisionNumber = ui->divisionNumber->currentText().toInt();
    currentUser->director = ui->director->text();
    currentUser->post = ui->post->text();
    Database::updateDatabase();
    QMessageBox info(QMessageBox::NoIcon, "Информация",
                     "Изменения внесены в базу данных!");
    info.setWindowIcon(style()->standardIcon(QStyle::SP_MessageBoxInformation));
    info.exec();
    this->close();

}
