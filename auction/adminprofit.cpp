#include "adminprofit.h"
#include "ui_adminprofit.h"

adminProfit::adminProfit(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::adminProfit)
{
    ui->setupUi(this);
    this->resize(600,700);
    this->setWindowTitle("查询利润");

    QLabel *back = new QLabel(this);
    back->resize(600,700);
    back->setPixmap(QPixmap(":/Logo/sell.png"));
    back->setScaledContents(true);

    Btn = new QPushButton("查询",this);
    Btn->resize(160,60);
    Btn->move(100,580);
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
    Btn1->resize(160,60);
    Btn1->move(330,580);
    Btn1->setStyleSheet("QPushButton { "
                          "background-color: rgba(0, 0, 0, 60); "
                          "border: none; "
                          "font-size: 16pt;"
                          "} "
                          "QPushButton:hover { "
                          "background-color: rgba(0, 0, 0, 30); "
                          "font-size: 20pt;"
                          "}");

    profitWidget = new QTableWidget(20,2,this);
    profitWidget->move(150,100);
    profitWidget->resize(300,450);
    profitWidget->setStyleSheet("QTableWidget {"
                                "background-color: rgba(255, 255, 255, 128);"
                                "color: rgba(0, 0, 0, 128);"
                                "border: 1px solid rgba(0, 0, 0, 128);"
                                "}");

    QTableWidgetItem *item0 = new QTableWidgetItem;
    QTableWidgetItem *item1 = new QTableWidgetItem;

    item0->setText("拍品");
    item1->setText("利润");

    profitWidget->setHorizontalHeaderItem(0,item0);
    profitWidget->setHorizontalHeaderItem(1,item1);

    socket = new QTcpSocket(this);

    connect(Btn,&QPushButton::clicked,this,&adminProfit::Btn_slot);

    connect(socket,&QTcpSocket::connected,this,&adminProfit::connected_slot);

    connect(socket,&QTcpSocket::readyRead,this,&adminProfit::readyRead_slot);

    connect(Btn1,&QPushButton::clicked,this,&adminProfit::Btn1_slot);

}

adminProfit::~adminProfit()
{
    delete ui;

}

void adminProfit::keyPressEvent(QKeyEvent *event)
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

void adminProfit::my_jump_slots()
{
    this->show();
}

void adminProfit::Btn_slot()
{
    socket->connectToHost(ip,port);
}

void adminProfit::connected_slot()
{
    msg.usr.flag = 11;
    msg.flag = 1;
    socket->write((char *)&msg,sizeof(msg));
}

void adminProfit::readyRead_slot()
{
    socket->read((char *)&msg,sizeof(msg));

    if(msg.usr.ok == 1)
    {
        QMessageBox::information(this,"","查询成功");
        for(int i = 0;i<msg.usr.count;i++)
        {
            QTableWidgetItem *item2 = new QTableWidgetItem(QString("%1").arg(msg.usr.good[i].name));
            QTableWidgetItem *item3 = new QTableWidgetItem(QString("%1").arg(msg.usr.good[i].profit));
            profitWidget->setItem(i,0,item2);
            profitWidget->setItem(i,1,item3);
        }
    }
    else if(msg.usr.ok == 0)
    {
        QMessageBox::information(this,"","查询失败");
    }

}

void adminProfit::Btn1_slot()
{
    int ret = QMessageBox::question(this,"","确定退出界面",QMessageBox::Yes|QMessageBox::No);
    if(ret == QMessageBox::Yes)
    {
//        int rowCount = profitWidget->rowCount();
        qDebug() << msg.usr.count;
        for(int i = 0;i < msg.usr.count ; i++)
        {
            QTableWidgetItem *emptyItem1 = new QTableWidgetItem("");
            QTableWidgetItem *emptyItem2 = new QTableWidgetItem("");
            profitWidget->setItem(i,0,emptyItem1);
            profitWidget->setItem(i,1,emptyItem2);
        }
        this->close();
        socket->disconnectFromHost();
        emit adprofittoWidget_signal();
    }
}



