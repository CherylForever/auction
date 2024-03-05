#include "usrlogin.h"
#include "ui_usrlogin.h"

usrLogin::usrLogin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::usrLogin)
{
    ui->setupUi(this);
    this->resize(550,650);
    this->setFixedSize(550,650);
    this->setWindowTitle("拍卖系统");


    //背景
    QLabel *lab1 = new QLabel(this);
    lab1->resize(550,650);
    lab1->setPixmap(QPixmap(":/Logo/shanChuan.jpg"));
    lab1->setScaledContents(true);
    lab1->setStyleSheet("QLabel { "
                          "opacity: 0.5;"
                          "}");

    QLabel *lab2 = new QLabel("用户登录",this);
    lab2->resize(200,50);
    lab2->move(175,150);
    lab2->setStyleSheet("font-size: 24pt");

    //用户名
    QLabel *usrlab = new QLabel(this);
    usrlab->resize(50,50);
    usrlab->move(100,300);
    usrlab->setPixmap(QPixmap(":/Logo/userName.jpg"));
    usrlab->setScaledContents(true);

    usredit = new QLineEdit(this);
    usredit->move(175,300);
    usredit->resize(300,50);
    usredit->setStyleSheet("background-color: rgba(255, 255, 255, 90);"
                           "border: none;");
    usredit->setPlaceholderText("用户名");

    //密码
    QLabel *passwdlab = new QLabel(this);
    passwdlab->resize(50,50);
    passwdlab->move(100,400);
    passwdlab->setPixmap(QPixmap(":/Logo/passwd.jpg"));
    passwdlab->setScaledContents(true);

    passwdedit = new QLineEdit(this);
    passwdedit->resize(300,50);
    passwdedit->move(175,400);
    passwdedit->setStyleSheet("background-color: rgba(255, 255, 255, 90);"
                           "border: none;");
    passwdedit->setPlaceholderText("密码");
    passwdedit->setEchoMode(QLineEdit::Password);


    //登录按钮
    loginBtn = new QPushButton("登录",this);
    loginBtn->resize(150,80);
    loginBtn->move(200,500);

    //注册
    QPushButton *regiBtn = new QPushButton("点击注册",this);
    regiBtn->resize(100,20);
    regiBtn->move(0,630);
    regiBtn->setStyleSheet("background-color: rgba(255, 255, 255, 50);");

    connect(loginBtn,&QPushButton::clicked,this,&usrLogin::loginBtn_slots);
    connect(regiBtn,&QPushButton::clicked,this,&usrLogin::regiBtn_slots);

    socket = new QTcpSocket(this);

    connect(socket,&QTcpSocket::connected,this,&usrLogin::connected_slot);

    connect(socket,&QTcpSocket::readyRead,this,&usrLogin::readyRead_slot);


}

usrLogin::~usrLogin()
{
    delete ui;
//    delete passwdedit;
    //    delete usredit;
}

void usrLogin::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Enter || event->key() == Qt::Key_Return) {
        // 模拟按钮点击
        loginBtn->click();
        // 阻止回车键的默认行为（如提交表单）
        event->accept();
    } else {
        // 否则，调用基类的keyPressEvent处理其他按键
        QWidget::keyPressEvent(event);
    }
}

void usrLogin::my_jump_slots()
{
    this->show();
}

//点击登录按钮对应的槽函数
void usrLogin::loginBtn_slots()
{
    name = usredit->text();
    passwd = passwdedit->text();

    socket->connectToHost(ip,port);

}

//注册按钮点击对应的槽函数
void usrLogin::regiBtn_slots()
{
    emit regi_jump();
}

void usrLogin::connected_slot()
{
    QMessageBox::information(this,"","已经连上服务器");

    //    填充信息
    msg.flag = 2;
    strcpy(msg.name, name.toStdString().c_str() );
    strcpy(msg.passwd , passwd.toStdString().c_str() );
    msg.usr.flag = 22;
    msg.state = 0;

    socket->write((char *)&msg,sizeof(msg));

}

void usrLogin::readyRead_slot()
{
    socket->read((char *)&msg,sizeof(msg));
    qDebug() << msg.usr.ok;
    int ret;
    if(msg.usr.ok == 1)
    {
        ret = QMessageBox::information(this,"","登录成功");
    }
    else if(msg.usr.ok == 0)
    {
        QMessageBox::information(this,"","登录失败");
    }
    if(ret == QMessageBox::Ok)
    {
        this->close();
        socket->disconnectFromHost();
        emit usr_jump();
    }
}
