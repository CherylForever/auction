#ifndef USRDELETEDATE_H
#define USRDELETEDATE_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include "struct.h"
#include <QTcpSocket>
#include <QMessageBox>
#include <QLabel>
#include <QKeyEvent>
namespace Ui {
class usrDeleteDate;
}

class usrDeleteDate : public QWidget
{
    Q_OBJECT

public:
    explicit usrDeleteDate(QWidget *parent = 0);
    ~usrDeleteDate();
    void keyPressEvent(QKeyEvent *event) override;
signals:
    void deletetowidget_signal();
public slots:
    void my_jump_slots();
    void Btn_slots();
    void connected_slots();
    void readyRead_slots();

private:
    Ui::usrDeleteDate *ui;

    QLineEdit *deleteEdit_name;
    QLineEdit *deleteUsr_name;

    QTcpSocket *socket;
    msg_info msg;
    QString ip = "192.168.126.84";
    quint16 port = 8888;
    QPushButton *Btn;
};

#endif // USRDELETEDATE_H
