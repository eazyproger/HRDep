#ifndef REGISTRATION_H
#define REGISTRATION_H

#include <QDialog>

namespace Ui {
class Registration;
}

class Registration : public QDialog
{
    Q_OBJECT

public:
    explicit Registration(QWidget *parent = nullptr);
    ~Registration();

private slots:
    void on_okCancelRegistration_accepted();

    void on_okCancelRegistration_rejected();

    void on_lastName_textChanged(const QString &arg1);

private:
    Ui::Registration *ui;
};

#endif // REGISTRATION_H
