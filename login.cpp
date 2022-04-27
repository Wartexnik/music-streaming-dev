#include "mainwindow.h"
#include "login.h"
#include "ui_login.h"

Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    ui->label_error->setVisible(false);
}

Login::~Login()
{
    delete ui;
}

void Login::on_button_login_clicked()
{
    QSqlQuery query;
    QString username = ui->line_username->text();
    QString password = ui->line_password->text();
    QString hash;

    //QString hash = QString("%1").arg(QString(QCryptographicHash::hash(password.toUtf8(),QCryptographicHash::Sha224).toHex()));
    query.prepare("SELECT pass FROM client WHERE username = (:username)");
    query.bindValue(":username", username);
    if (query.exec()) {
        qDebug() << query.executedQuery();
        if (query.size()>0) {
            query.next();
            hash = query.value(0).toString();
            qDebug() << hash;
            query.prepare("SELECT SHA2((:password), 256)='"+hash+"'");
            query.bindValue(":password", password);
            if (query.exec()) {
                query.next();
                if (query.value(0)==1) {
                    qDebug() << "Login success";
                    emit login_success(username);
                    //account.show();
                    close();
                }
                else {
                    QMessageBox msg;
                    msg.setText("Incorrect username/password!");
                    msg.setIcon(QMessageBox::Critical);
                    msg.exec();
                }
            }
        }
        else {
            QMessageBox msg;
            msg.setText("Incorrect username/password!");
            msg.setIcon(QMessageBox::Critical);
            msg.exec();
        }
    }
    else {
        qDebug() << "Query failed";
    }

}


void Login::on_button_signup_clicked()
{
    SignUp *signup = new SignUp();
    signup->show();
    close();
}
