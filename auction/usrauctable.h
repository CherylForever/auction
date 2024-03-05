#ifndef USRAUCTABLE_H
#define USRAUCTABLE_H

#include <QWidget>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QPushButton>
#include <QMessageBox>
#include "struct.h"
#include <QTcpSocket>
#include <QLabel>
#include <QKeyEvent>

namespace Ui {
class usrAuctable;
}

class usrAuctable : public QWidget
{
    Q_OBJECT

public:
    explicit usrAuctable(QWidget *parent = 0);
    ~usrAuctable();
    void keyPressEvent(QKeyEvent *event) override;
signals:
    void Btn1_signal();
public slots:
    void my_jump_slots();

    void Btn_slot();

    void connected_slot();

    void readyRead_slot();

    void Btn1_slot();

private:
    Ui::usrAuctable *ui;
    QTableWidget *usrauctWidget;

//    QTableWidgetItem *item4;
//    QTableWidgetItem *item5;
//    QTableWidgetItem *item6;
//    QTableWidgetItem *item7;

    msg_info msg;
    QString ip = "192.168.126.84";
    quint16 port = 8888;
    QTcpSocket *socket;

    QPushButton *Btn;
};

#endif // USRAUCTABLE_H
