#ifndef ADMINPROFIT_H
#define ADMINPROFIT_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QPushButton>
#include <QMessageBox>
#include <QLabel>
#include <QTableWidget>
#include "struct.h"
#include <QTcpSocket>
#include <QTableWidgetItem>
#include <QKeyEvent>

namespace Ui {
class adminProfit;
}

class adminProfit : public QWidget
{
    Q_OBJECT

public:
    explicit adminProfit(QWidget *parent = 0);
    ~adminProfit();
    void keyPressEvent(QKeyEvent *event) override;
signals:
    void adprofittoWidget_signal();
public slots:
    void my_jump_slots();

    void Btn_slot();

    void connected_slot();

    void readyRead_slot();

    void Btn1_slot();
private:
    Ui::adminProfit *ui;
//    QLabel *profitLab;

    QTableWidget *profitWidget;
    msg_info msg;
    QString ip = "192.168.126.84";
    quint16 port = 8888;
    QTcpSocket *socket;
    QPushButton *Btn;
};

#endif // ADMINPROFIT_H
