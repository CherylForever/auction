#include "usrsellgood.h"
#include "ui_usrsellgood.h"

usrSellGood::usrSellGood(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::usrSellGood)
{
    ui->setupUi(this);
    this->resize(600,450);
    this->setWindowTitle("卖出拍品");

    QLabel *back = new QLabel(this);
    back->resize(800,550);
    back->setPixmap(QPixmap(":/Logo/f.jpg"));
    back->setScaledContents(true);

    usrName = new QLineEdit(this);
    usrName->setPlaceholderText("您的名字");
    usrName->resize(300,70);
    usrName->move(150,100);
    usrName->setStyleSheet("QLineEdit {"
                               "background-color: rgba(255, 255, 255, 128);"
                               "border: 1px solid rgba(0, 0, 0, 128);"
                               "}");

    sellgoodEdit = new QLineEdit(this);
    sellgoodEdit->setPlaceholderText("请输入你要卖出的拍品");
    sellgoodEdit->resize(300,70);
    sellgoodEdit->move(150,200);
    sellgoodEdit->setStyleSheet("QLineEdit {"
                               "background-color: rgba(255, 255, 255, 128);"
                               "border: 1px solid rgba(0, 0, 0, 128);"
                               "}");

    Btn = new QPushButton("确认",this);
    Btn->resize(160,60);
    Btn->move(220,320);
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

    connect(Btn,&QPushButton::clicked,this,&usrSellGood::Btn_slot);

    connect(socket,&QTcpSocket::connected,this,&usrSellGood::connected_slot);

    connect(socket,&QTcpSocket::readyRead,this,&usrSellGood::readyRead_slot);
}

usrSellGood::~usrSellGood()
{
    delete ui;
}

void usrSellGood::keyPressEvent(QKeyEvent *event)
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

void usrSellGood::my_jump_slots()
{
    this->show();
}

void usrSellGood::Btn_slot()
{
    if(usrName->text() == "" || sellgoodEdit->text() == "" )
    {
        QMessageBox::information(this,"","请填写完整");
    }
    else {
        socket->connectToHost(ip,port);
    }
}

void usrSellGood::connected_slot()
{
    msg.flag = 2;
    msg.usr.flag = 5;
    strcpy(msg.usr.good[0].name,sellgoodEdit->text().toStdString().c_str());
    strcpy(msg.usr.good[0].seller_name,usrName->text().toStdString().c_str() );
    socket->write((char *)&msg,sizeof(msg));
}

void usrSellGood::readyRead_slot()
{
    socket->read((char *)&msg,sizeof(msg));
    int ret;
    int res;
    int res1;
    int ret1;
    if(msg.usr.ok == 1)
    {
        ret = QMessageBox::information(this,"","已拍出");
    }
    else if(msg.usr.ok == 0)
    {
        res = QMessageBox::information(this,"","拍出失败");
    }
    else if(msg.usr.ok == 2)
    {
        res1 = QMessageBox::information(this,"","用户名不匹配");
    }
    else if(msg.usr.ok == 3)
    {
        ret1 = QMessageBox::information(this,"","还没有人出价！！！");
    }
    if(ret == QMessageBox::Ok || res == QMessageBox::Ok || res1 == QMessageBox::Ok || ret1 == QMessageBox::Ok)
    {
        this->close();
        emit sell_signal();
    }
}
