#include "usrupdatedate.h"
#include "ui_usrupdatedate.h"

usrUpdateDate::usrUpdateDate(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::usrUpdateDate)
{
    ui->setupUi(this);
    this->resize(700,450);
    this->setWindowTitle("修改拍品价格");

    QLabel *back = new QLabel(this);
    back->resize(800,550);
    back->setPixmap(QPixmap(":/Logo/f.jpg"));
    back->setScaledContents(true);

    updateEdit_name = new QLineEdit(this);
    updateEdit_sprice = new QLineEdit(this);
    usrName = new QLineEdit(this);

    usrName->resize(380,80);
    usrName->move(160,30);
    usrName->setPlaceholderText("您的名字");
    usrName->setStyleSheet("QLineEdit {"
                               "background-color: rgba(255, 255, 255, 128);"
                               "border: 1px solid rgba(0, 0, 0, 128);"
                               "}");

    updateEdit_name->resize(380,80);
    updateEdit_name->move(160,130);
    updateEdit_name->setPlaceholderText("要更新的拍品名");
    updateEdit_name->setStyleSheet("QLineEdit {"
                               "background-color: rgba(255, 255, 255, 128);"
                               "border: 1px solid rgba(0, 0, 0, 128);"
                               "}");


    updateEdit_sprice->resize(380,80);
    updateEdit_sprice->move(160,235);
    updateEdit_sprice->setPlaceholderText("请输入更新底价");
    updateEdit_sprice->setStyleSheet("QLineEdit {"
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

    connect(Btn,&QPushButton::clicked,this,&usrUpdateDate::Btn_slot);

    connect(socket,&QTcpSocket::connected,this,&usrUpdateDate::connected_slot);

    connect(socket,&QTcpSocket::readyRead,this,&usrUpdateDate::readyRead_slot);

}

usrUpdateDate::~usrUpdateDate()
{
    delete ui;
//    delete updateEdit_name;
    //    delete updateEdit_sprice;
}

void usrUpdateDate::keyPressEvent(QKeyEvent *event)
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

void usrUpdateDate::my_jump_slots()
{
    this->show();
}

void usrUpdateDate::Btn_slot()
{
    if(updateEdit_name->text() == "" || updateEdit_sprice->text() == "" || usrName->text() == "" )
    {
        QMessageBox::information(this,"","请填写完整");
    }
    else {
        socket->connectToHost(ip,port);
    }
}

void usrUpdateDate::connected_slot()
{
    msg.flag = 2;
    msg.usr.flag = 2;
    strcpy( msg.usr.good[0].name,updateEdit_name->text().toStdString().c_str() );
    msg.usr.good[0].starting_price = updateEdit_sprice->text().toDouble();
    strcpy(msg.usr.good[0].seller_name,usrName->text().toStdString().c_str() );
    socket->write((char *)&msg,sizeof(msg));

}

void usrUpdateDate::readyRead_slot()
{
    socket->read((char *)&msg,sizeof(msg));
    int res;
    int ret;
    int res1;
    if(msg.usr.ok == 1)
    {
        res = QMessageBox::information(this,"","修改成功");
    }
    else if(msg.usr.ok == 0)
    {
        ret = QMessageBox::information(this,"","修改失败");
    }
    else if(msg.usr.ok == 2)
    {
        res1 = QMessageBox::information(this,"","用户名不匹配");
    }
    if(ret == QMessageBox::Ok || res == QMessageBox::Ok || res1 == QMessageBox::Ok)
    {
        this->close();
        socket->disconnectFromHost();
        emit updatetowidget_signal();
    }
}


