#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Отдел Кадров");
    this->setWindowIcon(QIcon(":/img/icon/main.png"));
    this->showMaximized();
    this->setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint); // убрал вопрос

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
}
MainWindow::~MainWindow()
{
    delete ui;
}

