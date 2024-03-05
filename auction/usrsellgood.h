#ifndef USRSELLGOOD_H
#define USRSELLGOOD_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include "struct.h"
#include <QTcpSocket>
#include <QMessageBox>
#include <QLabel>
#include <QKeyEvent>


namespace Ui {
class usrSellGood;
}

class usrSellGood : public QWidget
{
    Q_OBJECT

public:
    explicit usrSellGood(QWidget *parent = 0);
    ~usrSellGood();
    void keyPressEvent(QKeyEvent *event) override;

signals:
    void sell_signal();
public slots:
    void my_jump_slots();
    void Btn_slot();
    void connected_slot();
    void readyRead_slot();

private:
    Ui::usrSellGood *ui;
    QLineEdit *sellgoodEdit;
    QLineEdit *usrName;

    msg_info msg;
    QString ip = "192.168.126.84";
    quint16 port = 8888;
    QTcpSocket *socket;
    QPushButton *Btn;
};

#endif // USRSELLGOOD_H
