#include "signup.h"
#include "ui_signup.h"
#include "login.h"

SignUp::SignUp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SignUp)
{
    ui->setupUi(this);
}

SignUp::~SignUp()
{
    delete ui;
}

void SignUp::on_button_login_clicked()
{
    Login *login = new Login();
    login->show();
    close();
}

