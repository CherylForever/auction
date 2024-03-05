#include "usrinsertdate.h"
#include "ui_usrinsertdate.h"

usrInsertDate::usrInsertDate(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::usrInsertDate)
{
    ui->setupUi(this);
    this->resize(700,450);
    this->setWindowTitle("添加拍品");

    QLabel *back = new QLabel(this);
    back->resize(800,550);
    back->setPixmap(QPixmap(":/Logo/f.jpg"));
    back->setScaledContents(true);

    insertEdit_name = new QLineEdit(this);
    insertEdit_sprice = new QLineEdit(this);
    usr_name = new QLineEdit(this);

    usr_name->resize(370,70);
    usr_name->move(160,30);
    usr_name->setPlaceholderText("请输入您的名字");
    usr_name->setStyleSheet("QLineEdit {"
                               "background-color: rgba(255, 255, 255, 128);"
                               "border: 1px solid rgba(0, 0, 0, 128);"
                               "}");

    insertEdit_name->move(160,140);
    insertEdit_name->resize(370,70);
    insertEdit_name->setPlaceholderText("请输入要新增的拍品名");
    insertEdit_name->setStyleSheet("QLineEdit {"
                               "background-color: rgba(255, 255, 255, 128);"
                               "border: 1px solid rgba(0, 0, 0, 128);"
                               "}");


    insertEdit_sprice->move(160,250);
    insertEdit_sprice->resize(370,70);
    insertEdit_sprice->setPlaceholderText("请输入新增拍品底价");
    insertEdit_sprice->setStyleSheet("QLineEdit {"
                               "background-color: rgba(255, 255, 255, 128);"
                               "border: 1px solid rgba(0, 0, 0, 128);"
                               "}");

    Btn = new QPushButton("确定",this);

    Btn->move(250,345);
    Btn->resize(200,75);
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

    connect(Btn,&QPushButton::clicked,this,&usrInsertDate::Btn_slot);

    connect(socket,&QTcpSocket::connected,this,&usrInsertDate::connected_slot);

    connect(socket,&QTcpSocket::readyRead,this,&usrInsertDate::readyRead_slot);

}

usrInsertDate::~usrInsertDate()
{
    delete ui;
//    delete insertEdit_name;
    //    delete insertEdit_sprice;
}

void usrInsertDate::keyPressEvent(QKeyEvent *event)
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

void usrInsertDate::my_jump_slots()
{
    this->show();
}

void usrInsertDate::Btn_slot()
{
    if(insertEdit_name->text() == "" || insertEdit_sprice->text() == "" || usr_name->text() == "")
    {
        QMessageBox::information(this,"","请填写完整");
    }
    else {
        socket->connectToHost(ip,port);
    }
}

void usrInsertDate::connected_slot()
{
    msg.flag = 2;
    msg.usr.flag = 1;
    strcpy(msg.usr.good[0].name,insertEdit_name->text().toStdString().c_str() );
    strcpy(msg.usr.good[0].seller_name,usr_name->text().toStdString().c_str());
    msg.usr.good[0].starting_price = insertEdit_sprice->text().toDouble();
    msg.usr.good[0].state = 0;


    socket->write((char *)&msg,sizeof(msg));
}

void usrInsertDate::readyRead_slot()
{
    socket->read((char *)&msg,sizeof(msg));

    qDebug() << msg.usr.ok;
    int ret;
    int res;
    int ret1;
    if(msg.usr.ok == 1)
    {
        ret = QMessageBox::information(this,"","添加拍品成功");
    }
    else if(msg.usr.ok == 0)
    {
        res = QMessageBox::information(this,"","添加拍品失败");
    }
    else if(msg.usr.ok == 2)
    {
        ret1 = QMessageBox::information(this,"","没有这个用户！！！");
    }
    if(ret == QMessageBox::Ok || res == QMessageBox::Ok || ret1 == QMessageBox::Ok )
    {
        this->close();
        socket->disconnectFromHost();
        emit inserttowidget_signal();
    }

}

