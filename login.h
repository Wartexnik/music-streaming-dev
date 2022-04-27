#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>

namespace Ui {
class Login;
}

class Login : public QDialog
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();

private slots:
    void on_button_login_clicked();

    void on_button_signup_clicked();
signals:
    void login_success(QString username);
private:
    Ui::Login *ui;
};

#endif // LOGIN_H
