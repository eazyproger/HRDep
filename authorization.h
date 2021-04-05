#ifndef AUTHORIZATION_H
#define AUTHORIZATION_H

#include <QDialog>

namespace Ui {
class Authorization;
}

class Authorization : public QDialog
{
    Q_OBJECT

public:
    explicit Authorization(QWidget *parent = nullptr);
    ~Authorization();

private slots:


    void on_registrationButton_clicked();

    void on_logInButton_clicked();

private:
    Ui::Authorization *ui;
};

#endif // AUTHORIZATION_H
