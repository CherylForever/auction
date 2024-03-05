#include "usrdeletedate.h"
#include "ui_usrdeletedate.h"

usrDeleteDate::usrDeleteDate(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::usrDeleteDate)
{
    ui->setupUi(this);
    this->resize(700,450);
    this->setWindowTitle("删除拍品");

    QLabel *back = new QLabel(this);
    back->resize(800,550);
    back->setPixmap(QPixmap(":/Logo/f.jpg"));
    back->setScaledContents(true);

    deleteEdit_name = new QLineEdit(this);
    deleteUsr_name = new QLineEdit(this);

    deleteUsr_name->resize(370,80);
    deleteUsr_name->move(185,20);
    deleteUsr_name->setPlaceholderText("请输入您的名字");
    deleteUsr_name->setStyleSheet("QLineEdit {"
                               "background-color: rgba(255, 255, 255, 128);"
                               "border: 1px solid rgba(0, 0, 0, 128);"
                               "}");

    deleteEdit_name->resize(370,80);
    deleteEdit_name->move(185,150);
    deleteEdit_name->setPlaceholderText("请输入商品名");
    deleteEdit_name->setStyleSheet("QLineEdit {"
                               "background-color: rgba(255, 255, 255, 128);"
                               "border: 1px solid rgba(0, 0, 0, 128);"
                               "}");

    Btn = new QPushButton("确定",this);

    Btn->move(240,320);
    Btn->resize(210,80);
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

    connect(Btn,&QPushButton::clicked,this,&usrDeleteDate::Btn_slots);

    connect(socket,&QTcpSocket::connected,this,&usrDeleteDate::connected_slots);

    connect(socket,&QTcpSocket::readyRead,this,&usrDeleteDate::readyRead_slots);

}

usrDeleteDate::~usrDeleteDate()
{
    delete ui;
    //    delete deleteEdit_name;
}

void usrDeleteDate::keyPressEvent(QKeyEvent *event)
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

void usrDeleteDate::my_jump_slots()
{
    this->show();
}

void usrDeleteDate::Btn_slots()
{
    if(deleteEdit_name->text() == "" || deleteUsr_name->text() == "" )
    {
        QMessageBox::information(this,"","未输入商品名或您的名字");
    }
    else{
        socket->connectToHost(ip,port);
    }
}

void usrDeleteDate::connected_slots()
{
    msg.usr.flag = 3;
    strcpy(msg.usr.good[0].name,deleteEdit_name->text().toStdString().c_str());
    strcpy(msg.usr.good[0].seller_name,deleteUsr_name->text().toStdString().c_str());
    socket->write((char *)&msg,sizeof(msg));
}

void usrDeleteDate::readyRead_slots()
{
    socket->read((char *)&msg,sizeof(msg));
    int res;
    int ret;
    int res1;
    if(msg.usr.ok == 1)
    {
        ret = QMessageBox::information(this,"","删除拍品成功");
    }
    else if(msg.usr.ok == 0)
    {
        res = QMessageBox::information(this,"","删除拍品失败");
    }
    else if(msg.usr.ok == 2)
    {
        res1 = QMessageBox::information(this,"","用户名不匹配");
    }
    if(ret == QMessageBox::Ok || res == QMessageBox::Ok || res1 == QMessageBox::Ok )
    {
        this->close();
        socket->disconnectFromHost();
        emit deletetowidget_signal();
    }
}
