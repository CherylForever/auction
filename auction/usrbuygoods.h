#ifndef USRBUYGOODS_H
#define USRBUYGOODS_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QMessageBox>
#include "struct.h"
#include <QTcpSocket>
#include <QLabel>
#include <QKeyEvent>

namespace Ui {
class usrBuyGoods;
}

class usrBuyGoods : public QWidget
{
    Q_OBJECT

public:
    explicit usrBuyGoods(QWidget *parent = 0);
    ~usrBuyGoods();
    void keyPressEvent(QKeyEvent *event) override;

signals:
    void buytoWidget_signal();
public slots:
    void my_jump_slots();
    void Btn_slot();
    void connected_slot();
    void readyRead_slot();

private:
    Ui::usrBuyGoods *ui;

    QLineEdit *buyedGoodname;
    QLineEdit *buyPrice;
    QLineEdit *usrName;

    msg_info msg;
    QString ip = "192.168.126.84";
    quint16 port = 8888;
    QTcpSocket *socket;
    QPushButton *Btn;
};

#endif // USRBUYGOODS_H
