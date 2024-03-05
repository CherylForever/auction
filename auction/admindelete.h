#ifndef ADMINDELETE_H
#define ADMINDELETE_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include "struct.h"
#include <QTcpSocket>
#include <QMessageBox>
#include <QLabel>
#include <QKeyEvent>

namespace Ui {
class adminDelete;
}

class adminDelete : public QWidget
{
    Q_OBJECT

public:
    explicit adminDelete(QWidget *parent = 0);
    ~adminDelete();
    void keyPressEvent(QKeyEvent *event) override;
signals:
    void deletetowidget_signal();
public slots:
    void my_jump_slots();

    void Btn_slots();

    void connected_slots();

    void readyRead_slots();
private:
    Ui::adminDelete *ui;
    QLineEdit *deleteEdit_name;
    QTcpSocket *socket;
    msg_info msg;
    QString ip = "192.168.126.84";
    quint16 port = 8888;
    QPushButton *Btn;
};

#endif // ADMINDELETE_H
