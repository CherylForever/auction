#ifndef USRINSERTDATE_H
#define USRINSERTDATE_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QMessageBox>
#include <QTcpSocket>
#include "struct.h"
#include <QKeyEvent>
#include <QLabel>
namespace Ui {
class usrInsertDate;
}

class usrInsertDate : public QWidget
{
    Q_OBJECT

public:
    explicit usrInsertDate(QWidget *parent = 0);
    ~usrInsertDate();
    void keyPressEvent(QKeyEvent *event) override;
signals:
    void inserttowidget_signal();

public slots:
    void my_jump_slots();

    void Btn_slot();

    void connected_slot();

    void readyRead_slot();

private:
    Ui::usrInsertDate *ui;
    msg_info msg;
    double starting_price; //起拍价
    double current_high;   //当前最高价
    char seller_name[20];    //卖家
    QString ip = "192.168.126.84";
    quint16 port = 8888;
    QTcpSocket *socket;
    QPushButton *Btn;

    QLineEdit *insertEdit_name;
    QLineEdit *insertEdit_sprice;
    QLineEdit *usr_name;

};

#endif // USRINSERTDATE_H
