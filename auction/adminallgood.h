#ifndef ADMINALLGOOD_H
#define ADMINALLGOOD_H

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
class adminAllgood;
}

class adminAllgood : public QWidget
{
    Q_OBJECT

public:
    explicit adminAllgood(QWidget *parent = 0);
    ~adminAllgood();
    void keyPressEvent(QKeyEvent *event) override;
signals:
    void Btn1_signal();
public slots:
    void my_jump_slots();

    void Btn_slot();

    void Btn1_slot();

    void connected_slot();

    void readyRead_slot();
private:
    Ui::adminAllgood *ui;

    QTableWidget *allgoodWidget;
    msg_info msg;
    QString ip = "192.168.126.84";
    quint16 port = 8888;
    QTcpSocket *socket;

    QPushButton *Btn;

};

#endif // ADMINALLGOOD_H
