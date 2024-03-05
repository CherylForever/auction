#include "adminlogin.h"
#include "ui_adminlogin.h"

adminLogin::adminLogin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::adminLogin)
{
    ui->setupUi(this);
    this->resize(550,650);
    this->setFixedSize(550,650);


    //背景
    QLabel *lab1 = new QLabel(this);
    lab1->resize(550,650);
    lab1->setPixmap(QPixmap(":/Logo/shanChuan.jpg"));
    lab1->setScaledContents(true);
    lab1->setStyleSheet("QLabel { "
                          "opacity: 0.5;"
                          "}");

    QLabel *lab2 = new QLabel("管理登录",this);
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

    connect(loginBtn,&QPushButton::clicked,this,&adminLogin::loginBtn_slots);


}

adminLogin::~adminLogin()
{
    delete ui;
}

void adminLogin::keyPressEvent(QKeyEvent *event)
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

void adminLogin::my_jump_slots()
{
    this->show();
}

void adminLogin::loginBtn_slots()
{
    if("admin" != usredit->text() || "admin" != passwdedit->text() )
    {
        QMessageBox::information(this,"登录提示框","用户名或密码输入错误!!!");
    }
    else{
        int ret = QMessageBox::information(this,"登陆提示框","登陆成功");
        if(ret == QMessageBox::Ok)
        {
            this->close();
            emit adminlogin_jump();
        }
    }

}
