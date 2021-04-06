#ifndef REQUESTCERTIFICATE_H
#define REQUESTCERTIFICATE_H

#include <QDialog>

namespace Ui {
class RequestCertificate;
}

class RequestCertificate : public QDialog
{
    Q_OBJECT

public:
    explicit RequestCertificate(QWidget *parent = nullptr);
    ~RequestCertificate();

private slots:
    void on_buttonBox_rejected();

    void on_buttonBox_accepted();

private:
    Ui::RequestCertificate *ui;
};

#endif // REQUESTCERTIFICATE_H
