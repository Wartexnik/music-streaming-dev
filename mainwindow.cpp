#include "mainwindow.h"
#include "login.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("127.0.0.1");
    db.setUserName("root");
    db.setPassword("123123");
    db.setDatabaseName("music");

    if (!db.open())
    {
        qDebug() << "Failed to connect to database.";
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_button_account_status_change_clicked()
{
    if (connected) {
        connected = false;
        ui->label_account_status->setText("Guest");
        ui->button_account_status_change->setText("Connect");
    }
    else {
        Login *login = new Login();
        QObject:connect(login, &Login::login_success, this, &MainWindow::connect_account);
        login->show();
    }
}

void MainWindow::connect_account(QString name) {
    username = name;
    connected = true;
    ui->label_account_status->setText(username);
    ui->button_account_status_change->setText("Log out");
}


