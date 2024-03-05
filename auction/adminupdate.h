#ifndef ADMINUPDATE_H
#define ADMINUPDATE_H

#include <QWidget>
#include "struct.h"
#include <QTcpSocket>
#include <QLineEdit>
#include <QPushButton>
#include <QMessageBox>
#include <QLabel>
#include <QKeyEvent>
namespace Ui {
class adminUpdate;
}

class adminUpdate : public QWidget
{
    Q_OBJECT

public:
    explicit adminUpdate(QWidget *parent = 0);
    ~adminUpdate();
    void keyPressEvent(QKeyEvent *event) override;

signals:
    void updatetowidget_signal();
public slots:
    void my_jump_slots();

    void Btn_slot();

    void connected_slot();

    void readyRead_slot();

private:
    Ui::adminUpdate *ui;
    QLineEdit *updateEdit_name;
    QLineEdit *updateEdit_sprice;

    msg_info msg;
    double starting_price; //起拍价
    char seller_name[20];    //卖家
    QString ip = "192.168.126.84";
    quint16 port = 8888;
    QTcpSocket *socket;
    QPushButton *Btn;
};

#endif // ADMINUPDATE_H
