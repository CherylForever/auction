#include "admindelete.h"
#include "ui_admindelete.h"

adminDelete::adminDelete(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::adminDelete)
{
    ui->setupUi(this);
    this->resize(700,450);
    this->setWindowTitle("删除拍品");

    QLabel *back = new QLabel(this);
    back->resize(700,450);
    back->setPixmap(QPixmap(":/Logo/sell.png"));
    back->setScaledContents(true);

    deleteEdit_name = new QLineEdit(this);

    deleteEdit_name->resize(370,80);
    deleteEdit_name->move(185,150);
    deleteEdit_name->setPlaceholderText("请输入商品名");
    deleteEdit_name->setStyleSheet("QLineEdit {"
                               "background-color: rgba(255, 255, 255, 128);"
                               "border: 1px solid rgba(0, 0, 0, 128);"
                               "}");

    Btn = new QPushButton("确定",this);
    Btn->setStyleSheet("QPushButton { "
                          "background-color: rgba(0, 0, 0, 60); "
                          "border: none; "
                          "font-size: 16pt;"
                          "} "
                          "QPushButton:hover { "
                          "background-color: rgba(0, 0, 0, 30); "
                          "font-size: 20pt;"
                          "}");

    Btn->move(240,320);
    Btn->resize(210,80);

    socket = new QTcpSocket(this);

    connect(Btn,&QPushButton::clicked,this,&adminDelete::Btn_slots);

    connect(socket,&QTcpSocket::connected,this,&adminDelete::connected_slots);

    connect(socket,&QTcpSocket::readyRead,this,&adminDelete::readyRead_slots);

}

adminDelete::~adminDelete()
{
    delete ui;
}

void adminDelete::keyPressEvent(QKeyEvent *event)
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

void adminDelete::my_jump_slots()
{
    this->show();
}

void adminDelete::Btn_slots()
{
    if(deleteEdit_name->text() == "" )
    {
        QMessageBox::information(this,"","未输入商品名");
    }
    else{
        socket->connectToHost(ip,port);
    }
}

void adminDelete::connected_slots()
{
    msg.usr.flag = 3;
    strcpy(msg.usr.good[0].name,deleteEdit_name->text().toStdString().c_str());
    QString name = "admin";
    strcpy(msg.usr.good[0].seller_name,name.toStdString().c_str());
    socket->write((char *)&msg,sizeof(msg));
}

void adminDelete::readyRead_slots()
{
    socket->read((char *)&msg,sizeof(msg));
    int res;
    int ret;
    if(msg.usr.ok == 1)
    {
        ret = QMessageBox::information(this,"","删除拍品成功");
    }
    else if(msg.usr.ok == 0)
    {
        res = QMessageBox::information(this,"","删除拍品失败");

    }
    if(ret == QMessageBox::Ok || res == QMessageBox::Ok)
    {
        this->close();
        socket->disconnectFromHost();
        emit deletetowidget_signal();
    }
}
