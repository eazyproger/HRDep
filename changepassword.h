#ifndef CHANGEPASSWORD_H
#define CHANGEPASSWORD_H

#include <QDialog>
#include <QString>
#include "user.h"

namespace Ui {
class ChangePassword;
}

class ChangePassword : public QDialog
{
    Q_OBJECT

public:
    explicit ChangePassword(User *user, QWidget *parent = nullptr);
    ~ChangePassword();

private slots:
    void on_buttonBox_rejected();

    void on_buttonBox_accepted();

private:
    Ui::ChangePassword *ui;
    User *user;
};

#endif // CHANGEPASSWORD_H
