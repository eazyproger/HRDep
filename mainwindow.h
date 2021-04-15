#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidget>
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

    void on_editUser_clicked();

    void on_userTable_cellClicked(int row, int column);

    void on_userTable_cellDoubleClicked(int row, int column);

    void on_deleteUser_clicked();

    void on_unVerificateUserTable_cellClicked(int row, int column);

    void on_verificateUser_clicked();

    void on_deleteUser_2_clicked();

    void on_upLevelAccess_clicked();

    void on_copyUserTable_cellClicked(int row, int column);

    void on_downLevelAccess_clicked();

    void on_search_clicked();

    void on_reset_clicked();

    void on_search_2_clicked();

    void on_reset_2_clicked();

    void on_deleteCertificate_clicked();

    void on_certificates_cellClicked(int row, int column);

    void on_mainTable_currentChanged(int index);

private:
    Ui::MainWindow *ui;
    User *currentUser;
    QList <User*> userList;
    void initUserMenu();
    void initHRMenu();
    void initAdminMenu();
    void resizeTable(QTableWidget *userTable);

};
#endif // MAINWINDOW_H
