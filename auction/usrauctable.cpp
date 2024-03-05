#include "usrauctable.h"
#include "ui_usrauctable.h"

usrAuctable::usrAuctable(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::usrAuctable)
{
    ui->setupUi(this);
    this->setWindowTitle("显示可拍卖物品");
    this->resize(1000,700);

    QLabel *back = new QLabel(this);
    back->resize(1000,700);
    back->setPixmap(QPixmap(":/Logo/s.jpg"));
    back->setScaledContents(true);

    usrauctWidget = new QTableWidget(20,4,this);

    usrauctWidget->move(150,100);
    usrauctWidget->resize(700,450);
    usrauctWidget->setStyleSheet("QTableWidget {"
                                "background-color: rgba(255, 255, 255, 128);"
                                "color: rgba(0, 0, 0, 128);"
                                "border: 1px solid rgba(0, 0, 0, 128);"
                                "}");

    QTableWidgetItem *item0 = new QTableWidgetItem;
    QTableWidgetItem *item1 = new QTableWidgetItem;
    QTableWidgetItem *item2 = new QTableWidgetItem;
    QTableWidgetItem *item3 = new QTableWidgetItem;

//    item4 = new QTableWidgetItem;
//    item5 = new QTableWidgetItem;
//    item6 = new QTableWidgetItem;
//    item7 = new QTableWidgetItem;

    item0->setText("拍品");
    item1->setText("底价");
    item2->setText("当前拍价");
    item3->setText("是否被拍");

    usrauctWidget->setHorizontalHeaderItem(0,item0);
    usrauctWidget->setHorizontalHeaderItem(1,item1);
    usrauctWidget->setHorizontalHeaderItem(2,item2);
    usrauctWidget->setHorizontalHeaderItem(3,item3);

    Btn = new QPushButton("显示",this);

    Btn->resize(200,80);
    Btn->move(200,580);
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

    Btn1->resize(200,80);
    Btn1->move(500,580);
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

    connect(Btn,&QPushButton::clicked,this,&usrAuctable::Btn_slot);

    connect(Btn1,&QPushButton::clicked,this,&usrAuctable::Btn1_slot);

    connect(socket,&QTcpSocket::connected,this,&usrAuctable::connected_slot);

    connect(socket,&QTcpSocket::readyRead,this,&usrAuctable::readyRead_slot);
}

usrAuctable::~usrAuctable()
{
    delete ui;
    //    delete usrauctWidget;
}

void usrAuctable::keyPressEvent(QKeyEvent *event)
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

void usrAuctable::my_jump_slots()
{
    this->show();
}

void usrAuctable::Btn_slot()
{
    socket->connectToHost(ip,port);
}

void usrAuctable::connected_slot()
{
    msg.flag = 2;
    msg.usr.flag = 4;
    socket->write((char *)&msg,sizeof(msg));
}

void usrAuctable::readyRead_slot()
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
//            item4->setText(QString::fromUtf8(msg.usr.good[i].name));
////            char start_price[20];
////            sprintf(start_price,"%lf",msg.usr.good[i].starting_price);
//            item5->setText(QString::number(msg.usr.good[i].starting_price));
////            char current_high[20];
////            sprintf(current_high,"%lf",msg.usr.good[i].current_high);
//            item6->setText(QString::number(msg.usr.good[i].current_high));
//            item7->setText(state);
//            usrauctWidget->setItem(i,0,item4);
//            usrauctWidget->setItem(i,1,item5);
//            usrauctWidget->setItem(i,2,item6);
//            usrauctWidget->setItem(i,3,item7);
            QTableWidgetItem *item4 = new QTableWidgetItem(QString("%1").arg(msg.usr.good[i].name));
            QTableWidgetItem *item5 = new QTableWidgetItem(QString("%1").arg(msg.usr.good[i].starting_price));
            QTableWidgetItem *item6 = new QTableWidgetItem(QString("%1").arg(msg.usr.good[i].current_high));
            QTableWidgetItem *item7 = new QTableWidgetItem(QString("%1").arg(state));
            usrauctWidget->setItem(i,0,item4);
            usrauctWidget->setItem(i,1,item5);
            usrauctWidget->setItem(i,2,item6);
            usrauctWidget->setItem(i,3,item7);
        }
    }
    else if(msg.usr.ok == 0)
    {
        QMessageBox::information(this,"","显示失败");
    }
}

void usrAuctable::Btn1_slot()
{
    int ret = QMessageBox::question(this,"","是否退出查询界面",QMessageBox::Yes|QMessageBox::No);
    if(ret == QMessageBox::Yes)
    {

        for(int i = 0;i<msg.usr.count;i++)
        {
            for(int j = 0; j<4; j++)
            {
                QTableWidgetItem *emptyItem = new QTableWidgetItem("");
                usrauctWidget->setItem(i,j,emptyItem);
            }
        }
        this->close();
        emit Btn1_signal();
        socket->disconnectFromHost();
    }
}
