#include "usrregister.h"
#include "ui_usrregister.h"

usrRegister::usrRegister(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::usrRegister)
{
    ui->setupUi(this);
    this->setWindowTitle("用户注册");

    nameEdit = new QLineEdit(this);
    passwdEdit = new QLineEdit(this);
    repasswdEdit = new QLineEdit(this);

    nameEdit->move(100,50);
    nameEdit->resize(200,35);
    passwdEdit->move(100,100);
    passwdEdit->resize(200,35);
    repasswdEdit->move(100,150);
    repasswdEdit->resize(200,35);

    nameEdit->setPlaceholderText("请输入用户名");
    passwdEdit->setPlaceholderText("请输入密码");
    repasswdEdit->setPlaceholderText("请确认密码");

    passwdEdit->setEchoMode(QLineEdit::Password);
    repasswdEdit->setEchoMode(QLineEdit::Password);

    regiBtn = new QPushButton("点击注册",this);
    regiBtn->resize(100,50);
    regiBtn->move(145,210);

    connect(regiBtn,&QPushButton::clicked,this,&usrRegister::regiBtn_clicked);

    socket = new QTcpSocket(this);


    connect(socket,&QTcpSocket::connected,this,&usrRegister::connected_slot);

    connect(socket,&QTcpSocket::readyRead,this,&usrRegister::readyRead_slot);

    connect(socket,&QTcpSocket::disconnected,this,&usrRegister::disconnected_slot);


}

usrRegister::~usrRegister()
{
    delete ui;
//    delete nameEdit;
//    delete passwdEdit;
    //    delete repasswdEdit;
}

void usrRegister::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Enter || event->key() == Qt::Key_Return) {
        // 模拟按钮点击
        regiBtn->click();
        // 阻止回车键的默认行为（如提交表单）
        event->accept();
    } else {
        // 否则，调用基类的keyPressEvent处理其他按键
        QWidget::keyPressEvent(event);
    }
}

void usrRegister::my_jump_slots()
{
    this->show();
}

void usrRegister::regiBtn_clicked()
{
    name = nameEdit->text();
    passwd = passwdEdit->text();
    if(passwd != repasswdEdit->text())
    {
        QMessageBox::information(this,"","输入密码不一致");
    }

    socket->connectToHost(ip,port);
}

void usrRegister::connected_slot()
{
    QMessageBox::information(this,"","已经连上服务器");

    //填充信息
    msg.flag = 2;
    strcpy(msg.name, name.toStdString().c_str() );
    strcpy(msg.passwd , passwd.toStdString().c_str() );
    msg.usr.flag = 21;
    msg.state=0;

    socket->write((char *)&msg,sizeof(msg));

}

void usrRegister::readyRead_slot()
{
    socket->read((char *)&msg,sizeof(msg));
    qDebug() << msg.usr.ok;
    int ret;
    if(msg.usr.ok == 1)
    {
        ret = QMessageBox::information(this,"","注册成功");
    }
    else if(msg.usr.ok == 0)
    {
        QMessageBox::information(this,"","注册失败");
    }
    if(ret == QMessageBox::Ok)
    {
        this->close();
        socket->disconnectFromHost();
    }
}

void usrRegister::disconnected_slot()
{
//    QMessageBox::information(this,"","连接已经断开");
}
