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

private:
    Ui::Registration *ui;
};

#endif // REGISTRATION_H
