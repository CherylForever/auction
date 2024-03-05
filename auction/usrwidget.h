#ifndef USRWIDGET_H
#define USRWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QMessageBox>
#include <QKeyEvent>
#include "struct.h"
#include <QLabel>

namespace Ui {
class usrWidget;
}

class usrWidget : public QWidget
{
    Q_OBJECT

public:
    explicit usrWidget(QWidget *parent = 0);
    ~usrWidget();
    void keyPressEvent(QKeyEvent *event) override;

signals:
    void insert_signal();
    void delete_signal();
    void update_signal();
    void auctable_signal();
    void sellgood_signal();
    void auctionrecord_signal();

public slots:
    void my_jump_slots();

    void insertBtn_slot();

    void deleteBtn_slot();

    void updateBtn_slot();

    void auctableBtn_slot();

    void sellgoodBtn_slot();

    void auctionrecordBtn_slot();

//    void insert_connected_slot();  //新增请求连接



private:
    Ui::usrWidget *ui;

    QPushButton *insertBtn;
    QPushButton *deleteBtn;
    QPushButton *updateBtn;
    QPushButton *auctableBtn;
    QPushButton *sellgoodBtn;
    QPushButton *auctionrecordBtn;

};

#endif // USRWIDGET_H
