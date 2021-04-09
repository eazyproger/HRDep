#ifndef EDITWINDOW_H
#define EDITWINDOW_H

#include <QDialog>
#include "user.h"

namespace Ui {
class EditWindow;
}

class EditWindow : public QDialog
{
    Q_OBJECT

public:
    explicit EditWindow(User *user, QWidget *parent = nullptr);
    ~EditWindow();

private slots:
    void on_divisionNumber_currentIndexChanged(int index);

    void on_divisionName_currentIndexChanged(int index);

    void on_okCancelButton_rejected();

    void on_okCancelButton_accepted();

private:
    Ui::EditWindow *ui;
    QStringList divisionNames = {"Не указано","Отдел кадров","Техническая служба","Отдел разработки"};
    User *currentUser;
};

#endif // EDITWINDOW_H
