#ifndef REQUESTCERTIFICATE_H
#define REQUESTCERTIFICATE_H

#include <QDialog>
#include <user.h>

namespace Ui {
class RequestCertificate;
}

class RequestCertificate : public QDialog
{
    Q_OBJECT

public:
    explicit RequestCertificate(User *user, QWidget *parent = nullptr);
    ~RequestCertificate();

private slots:
    void on_buttonBox_rejected();

    void on_buttonBox_accepted();

private:
    Ui::RequestCertificate *ui;
    User *currentUser;
};

#endif // REQUESTCERTIFICATE_H
