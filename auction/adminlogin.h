#ifndef ADMINLOGIN_H
#define ADMINLOGIN_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QMessageBox>
#include <QKeyEvent>
namespace Ui {
class adminLogin;
}

class adminLogin : public QWidget
{
    Q_OBJECT

public:
    explicit adminLogin(QWidget *parent = 0);
    ~adminLogin();
    void keyPressEvent(QKeyEvent *event) override;

public slots:
    void my_jump_slots();
    void loginBtn_slots();

signals:
    void adminlogin_jump();
private:
    Ui::adminLogin *ui;

    QLineEdit *usredit;
    QLineEdit *passwdedit;
    QPushButton *loginBtn;
};

#endif // ADMINLOGIN_H
