#include "usrbuygoods.h"
#include "ui_usrbuygoods.h"

usrBuyGoods::usrBuyGoods(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::usrBuyGoods)
{
    ui->setupUi(this);
    this->setWindowTitle("购买");

    this->resize(850,550);
    QLabel *back = new QLabel(this);
    back->resize(1000,700);
    back->setPixmap(QPixmap(":/Logo/bid.png"));
    back->setScaledContents(true);

    usrName = new QLineEdit(this);
    usrName->resize(450,80);
    usrName->move(200,100);
    usrName->setPlaceholderText("输入您的名字");
    usrName->setStyleSheet("QLineEdit {"
                               "background-color: rgba(255, 255, 255, 128);"
                               "border: 1px solid rgba(0, 0, 0, 128);"
                               "}");

    buyedGoodname = new QLineEdit(this);
    buyedGoodname->resize(450,80);
    buyedGoodname->move(200,200);
    buyedGoodname->setPlaceholderText("输入要竞拍的物品");
    buyedGoodname->setStyleSheet("QLineEdit {"
                               "background-color: rgba(255, 255, 255, 128);"
                               "border: 1px solid rgba(0, 0, 0, 128);"
                               "}");

    buyPrice = new QLineEdit(this);
    buyPrice->resize(450,80);
    buyPrice->move(200,300);
    buyPrice->setPlaceholderText("输入要竞拍的价格");
    buyPrice->setStyleSheet("QLineEdit {"
                               "background-color: rgba(255, 255, 255, 128);"
                               "border: 1px solid rgba(0, 0, 0, 128);"
                               "}");


    Btn = new QPushButton("出价",this);
    Btn->resize(230,80);
    Btn->move(300,435);
    Btn->setStyleSheet("QPushButton { "
                          "background-color: rgba(0, 0, 0, 60); "
                          "border: none; "
                          "font-size: 16pt;"
                          "} "
                          "QPushButton:hover { "
                          "background-color: rgba(0, 0, 0, 30); "
                          "font-size: 20pt;"
                          "}");

    socket = new QTcpSocket(this);

    connect(Btn,&QPushButton::clicked,this,&usrBuyGoods::Btn_slot);

    connect(socket,&QTcpSocket::connected,this,&usrBuyGoods::connected_slot);

    connect(socket,&QTcpSocket::readyRead,this,&usrBuyGoods::readyRead_slot);


}

usrBuyGoods::~usrBuyGoods()
{
    delete ui;
//    delete buyedGoodname;
    //    delete buyPrice;
}

void usrBuyGoods::keyPressEvent(QKeyEvent *event)
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

void usrBuyGoods::my_jump_slots()
{
    this->show();
}

void usrBuyGoods::Btn_slot()
{
    socket->connectToHost(ip,port);
}

void usrBuyGoods::connected_slot()
{
    msg.flag = 2;
    msg.usr.flag = 6;
    strcpy(msg.usr.good[0].buyer_name,usrName->text().toStdString().c_str());
    strcpy(msg.usr.good[0].name,buyedGoodname->text().toStdString().c_str());
    msg.usr.good[0].current_high = buyPrice->text().toDouble();

    socket->write((char *)&msg,sizeof(msg));
}

void usrBuyGoods::readyRead_slot()
{
    socket->read((char *)&msg,sizeof(msg));
    int ret;
    int res;
    int res2;
    if(msg.usr.ok == 1)
    {
        ret = QMessageBox::information(this,"","出价成功");
    }
    else if(msg.usr.ok == 0)
    {
        res = QMessageBox::information(this,"","出价失败");
    }
    else if(msg.usr.ok == 2)
    {
        res2 = QMessageBox::information(this,"","出价太低");
    }
    if(ret == QMessageBox::Ok || res == QMessageBox::Ok || res2== QMessageBox::Ok )
    {
        usrName->clear();
        buyedGoodname->clear();
        buyPrice->clear();
        this->close();
        socket->disconnectFromHost();
        emit buytoWidget_signal();
    }
}
