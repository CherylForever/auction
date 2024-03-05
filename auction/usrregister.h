#ifndef USRREGISTER_H
#define USRREGISTER_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QMessageBox>
#include <QKeyEvent>
#include "struct.h"
#include <QTcpSocket>
namespace Ui {
class usrRegister;
}

class usrRegister : public QWidget
{
    Q_OBJECT

public:
    explicit usrRegister(QWidget *parent = 0);
    ~usrRegister();
    void keyPressEvent(QKeyEvent *event) override;
public slots:
    void my_jump_slots();
    void regiBtn_clicked();

    void connected_slot();
    void readyRead_slot();
    void disconnected_slot();
private:
    Ui::usrRegister *ui;

    QLineEdit *nameEdit;
    QLineEdit *passwdEdit;
    QLineEdit *repasswdEdit;
    msg_info msg;
    QString name;
    QString passwd;
    QString ip = "192.168.126.84";
    quint16 port = 8888;
    QTcpSocket *socket;
    QPushButton *regiBtn;
};

#endif // USRREGISTER_H
