#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "user.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(User *currentUser, QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_tabWidget_currentChanged(int index);

    void on_logOut_triggered();

    void on_changePassword_clicked();

    void on_saveChanges_clicked();

    void updateCurrentUser();

    void on_requestCertificate_clicked();

private:
    Ui::MainWindow *ui;
    User *currentUser;

};
#endif // MAINWINDOW_H
