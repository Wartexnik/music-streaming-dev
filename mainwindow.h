#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>
#include <QDebug>
#include <login.h>
#include <signup.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    QString username;
    bool connected = false;
    MainWindow(QWidget *parent = nullptr);

    ~MainWindow();

private slots:
    void on_button_account_status_change_clicked();
    void connect_account(QString username);
private:
    Ui::MainWindow *ui;
    QSqlDatabase db;

};
#endif // MAINWINDOW_H
