#ifndef USRUPDATEDATE_H
#define USRUPDATEDATE_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QMessageBox>
#include <QTcpSocket>
#include <QKeyEvent>
#include "struct.h"
#include <QLabel>


namespace Ui {
class usrUpdateDate;
}

class usrUpdateDate : public QWidget
{
    Q_OBJECT

public:
    explicit usrUpdateDate(QWidget *parent = 0);
    ~usrUpdateDate();
    void keyPressEvent(QKeyEvent *event) override;

signals:
    void updatetowidget_signal();

public slots:
    void my_jump_slots();
    void Btn_slot();
    void connected_slot();
    void readyRead_slot();

private:
    Ui::usrUpdateDate *ui;
    QLineEdit *updateEdit_name;
    QLineEdit *updateEdit_sprice;
    QLineEdit *usrName;

    msg_info msg;
    double starting_price; //起拍价
    char seller_name[20];    //卖家
    QString ip = "192.168.126.84";
    quint16 port = 8888;
    QTcpSocket *socket;

    QPushButton *Btn;
};

#endif // USRUPDATEDATE_H
