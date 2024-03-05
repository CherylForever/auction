#include "adminallgood.h"
#include "ui_adminallgood.h"

adminAllgood::adminAllgood(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::adminAllgood)
{
    ui->setupUi(this);
    this->setWindowTitle("显示所有拍卖物品");
    this->resize(1000,700);

    QLabel *back = new QLabel(this);
    back->resize(1000,700);
    back->setPixmap(QPixmap(":/Logo/sell.png"));
    back->setScaledContents(true);

    allgoodWidget = new QTableWidget(20,7,this);
    allgoodWidget->setStyleSheet("QTableWidget {"
                                "background-color: rgba(255, 255, 255, 128);"
                                "color: rgba(0, 0, 0, 128);"
                                "border: 1px solid rgba(0, 0, 0, 128);"
                                "}");

    allgoodWidget->move(125,100);
    allgoodWidget->resize(750,450);

    QTableWidgetItem *item0 = new QTableWidgetItem;
    QTableWidgetItem *item1 = new QTableWidgetItem;
    QTableWidgetItem *item2 = new QTableWidgetItem;
    QTableWidgetItem *item3 = new QTableWidgetItem;
    QTableWidgetItem *item4 = new QTableWidgetItem;
    QTableWidgetItem *item5 = new QTableWidgetItem;
    QTableWidgetItem *item6 = new QTableWidgetItem;

    item0->setText("拍品");
    item1->setText("底价");
    item2->setText("当前拍价");
    item3->setText("成交价");
    item4->setText("出售者");
    item5->setText("购买者");
    item6->setText("是否被拍");

    allgoodWidget->setHorizontalHeaderItem(0,item0);
    allgoodWidget->setHorizontalHeaderItem(1,item1);
    allgoodWidget->setHorizontalHeaderItem(2,item2);
    allgoodWidget->setHorizontalHeaderItem(3,item3);
    allgoodWidget->setHorizontalHeaderItem(4,item4);
    allgoodWidget->setHorizontalHeaderItem(5,item5);
    allgoodWidget->setHorizontalHeaderItem(6,item6);

    Btn = new QPushButton("显示",this);

    Btn->resize(200,90);
    Btn->move(250,580);
    Btn->setStyleSheet("QPushButton { "
                          "background-color: rgba(0, 0, 0, 60); "
                          "border: none; "
                          "font-size: 16pt;"
                          "} "
                          "QPushButton:hover { "
                          "background-color: rgba(0, 0, 0, 30); "
                          "font-size: 20pt;"
                          "}");

    QPushButton *Btn1 = new QPushButton("退出",this);

    Btn1->resize(200,90);
    Btn1->move(550,580);
    Btn1->setStyleSheet("QPushButton { "
                          "background-color: rgba(0, 0, 0, 60); "
                          "border: none; "
                          "font-size: 16pt;"
                          "} "
                          "QPushButton:hover { "
                          "background-color: rgba(0, 0, 0, 30); "
                          "font-size: 20pt;"
                          "}");

    socket = new QTcpSocket(this);

    connect(Btn,&QPushButton::clicked,this,&adminAllgood::Btn_slot);

    connect(Btn1,&QPushButton::clicked,this,&adminAllgood::Btn1_slot);

    connect(socket,&QTcpSocket::connected,this,&adminAllgood::connected_slot);

    connect(socket,&QTcpSocket::readyRead,this,&adminAllgood::readyRead_slot);

}

adminAllgood::~adminAllgood()
{
    delete ui;
}

void adminAllgood::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Enter || event->key() == Qt::Key_Return) {
        // 模拟按钮点击
        Btn->click();
        // 阻止回车键的默认行为（如提交表单）
        event->accept();
    } else {
        // 否则，调用基类的keyPressEvent处理其他按键
        QWidget::keyPressEvent(event);
    }
}

void adminAllgood::my_jump_slots()
{
    this->show();
}

void adminAllgood::Btn_slot()
{
    socket->connectToHost(ip,port);
}

void adminAllgood::Btn1_slot()
{
    int ret = QMessageBox::question(this,"","是否退出总查询界面",QMessageBox::Yes|QMessageBox::No);
    if(ret == QMessageBox::Yes)
    {
        for(int i = 0;i < msg.usr.count ; i++)
        {
//            QTableWidgetItem *emptyItem1 = new QTableWidgetItem("");
//            QTableWidgetItem *emptyItem2 = new QTableWidgetItem("");
//            QTableWidgetItem *emptyItem3 = new QTableWidgetItem("");
//            QTableWidgetItem *emptyItem4 = new QTableWidgetItem("");
//            QTableWidgetItem *emptyItem5 = new QTableWidgetItem("");
//            QTableWidgetItem *emptyItem6 = new QTableWidgetItem("");
//            QTableWidgetItem *emptyItem7 = new QTableWidgetItem("");

//            allgoodWidget->setItem(i,0,emptyItem1);
//            allgoodWidget->setItem(i,1,emptyItem2);
//            allgoodWidget->setItem(i,2,emptyItem3);
//            allgoodWidget->setItem(i,3,emptyItem4);
//            allgoodWidget->setItem(i,4,emptyItem5);
//            allgoodWidget->setItem(i,5,emptyItem6);
//            allgoodWidget->setItem(i,6,emptyItem7);
            for(int j = 0;j<7;j++)
            {
                QTableWidgetItem *emptyItem = new QTableWidgetItem("");
                allgoodWidget->setItem(i,j,emptyItem);

            }
        }

        this->close();
        emit Btn1_signal();
        socket->disconnectFromHost();
    }

}

void adminAllgood::connected_slot()
{
    msg.flag = 1;
    msg.usr.flag = 12;
    socket->write((char *)&msg,sizeof(msg));
}

void adminAllgood::readyRead_slot()
{
    socket->read((char *)&msg,sizeof(msg));

    if(msg.usr.ok == 1)
    {
        QMessageBox::information(this,"","显示成功");
        int flag;
        char state[20];
        qDebug() << msg.usr.count;
        for(int i = 0;i < msg.usr.count;i++)
        {
            flag = msg.usr.good[i].state;
            if(flag == 0)
            {
                strcpy(state,"未拍");
            }
            else if(flag == 1)
            {
                strcpy(state,"已拍");
            }
            QTableWidgetItem *item_1 = new QTableWidgetItem(QString("%1").arg(msg.usr.good[i].name));
            QTableWidgetItem *item_2 = new QTableWidgetItem(QString("%1").arg(msg.usr.good[i].starting_price));
            QTableWidgetItem *item_3 = new QTableWidgetItem(QString("%1").arg(msg.usr.good[i].current_high));
            QTableWidgetItem *item_4 = new QTableWidgetItem(QString("%1").arg(msg.usr.good[i].transaction_price));
            QTableWidgetItem *item_5 = new QTableWidgetItem(QString("%1").arg(msg.usr.good[i].seller_name));
            QTableWidgetItem *item_6 = new QTableWidgetItem(QString("%1").arg(msg.usr.good[i].buyer_name));
            QTableWidgetItem *item_7 = new QTableWidgetItem(QString("%1").arg(state));

            allgoodWidget->setItem(i,0,item_1);
            allgoodWidget->setItem(i,1,item_2);
            allgoodWidget->setItem(i,2,item_3);
            allgoodWidget->setItem(i,3,item_4);
            allgoodWidget->setItem(i,4,item_5);
            allgoodWidget->setItem(i,5,item_6);
            allgoodWidget->setItem(i,6,item_7);
        }
    }
    else if(msg.usr.ok == 0)
    {
        QMessageBox::information(this,"","显示失败");
    }
}
