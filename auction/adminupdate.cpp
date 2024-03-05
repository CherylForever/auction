#include "adminupdate.h"
#include "ui_adminupdate.h"

adminUpdate::adminUpdate(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::adminUpdate)
{
    ui->setupUi(this);
    this->resize(700,450);
    this->setWindowTitle("修改拍品价格");

    QLabel *back = new QLabel(this);
    back->resize(700,450);
    back->setPixmap(QPixmap(":/Logo/sell.png"));
    back->setScaledContents(true);

    updateEdit_name = new QLineEdit(this);
    updateEdit_sprice = new QLineEdit(this);

    updateEdit_name->resize(380,80);
    updateEdit_name->move(160,80);
    updateEdit_name->setPlaceholderText("请要更新的拍品名");
    updateEdit_name->setStyleSheet("QLineEdit {"
                               "background-color: rgba(255, 255, 255, 128);"
                               "border: 1px solid rgba(0, 0, 0, 128);"
                               "}");

    updateEdit_sprice->resize(380,80);
    updateEdit_sprice->move(160,200);
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

    connect(Btn,&QPushButton::clicked,this,&adminUpdate::Btn_slot);

    connect(socket,&QTcpSocket::connected,this,&adminUpdate::connected_slot);

    connect(socket,&QTcpSocket::readyRead,this,&adminUpdate::readyRead_slot);
}

adminUpdate::~adminUpdate()
{
    delete ui;
}

void adminUpdate::keyPressEvent(QKeyEvent *event)
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

void adminUpdate::my_jump_slots()
{
    this->show();
}

void adminUpdate::Btn_slot()
{
    if(updateEdit_name->text() == "" || updateEdit_sprice->text() == "" )
    {
        QMessageBox::information(this,"","请填写商品名&&商品价格");
    }
    else {
        socket->connectToHost(ip,port);
    }
}

void adminUpdate::connected_slot()
{
    msg.flag = 1;
    msg.usr.flag = 2;
    strcpy( msg.usr.good[0].name,updateEdit_name->text().toStdString().c_str() );
    msg.usr.good[0].starting_price = updateEdit_sprice->text().toDouble();
    QString name = "admin";
    strcpy(msg.usr.good[0].seller_name,name.toStdString().c_str());
    socket->write((char *)&msg,sizeof(msg));
}

void adminUpdate::readyRead_slot()
{
    socket->read((char *)&msg,sizeof(msg));
    int res;
    int ret;
    if(msg.usr.ok == 1)
    {
        res = QMessageBox::information(this,"","修改成功");
    }
    else if(msg.usr.ok == 0)
    {
        ret = QMessageBox::information(this,"","修改失败");
    }
    if(ret == QMessageBox::Ok || res == QMessageBox::Ok)
    {
        this->close();
        socket->disconnectFromHost();
        emit updatetowidget_signal();
    }
}


