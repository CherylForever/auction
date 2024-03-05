#ifndef USRLOGIN_H
#define USRLOGIN_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QMessageBox>
#include "struct.h"
#include <QKeyEvent>

namespace Ui {
class usrLogin;
}

class usrLogin : public QWidget
{
    Q_OBJECT

public:
    explicit usrLogin(QWidget *parent = 0);
    ~usrLogin();
    void keyPressEvent(QKeyEvent *event) override;

signals:
    void regi_jump();

    void usr_jump();

public slots:
    void my_jump_slots();

    void loginBtn_slots();
    void regiBtn_slots();

    void connected_slot();
    void readyRead_slot();

private:
    Ui::usrLogin *ui;
    QString name;
    QString passwd;
    msg_info msg;
    QString ip = "192.168.126.84";
    quint16 port = 8888;
    QTcpSocket *socket;
    QLineEdit *usredit;
    QLineEdit *passwdedit;
    QPushButton *loginBtn;
};

#endif // USRLOGIN_H
