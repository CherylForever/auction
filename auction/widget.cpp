#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->resize(800,550);
    this->setFixedSize(800,550);
    this->setWindowTitle("选择身份");

    //设置标签提示选择身份
    QLabel *lab1 = new QLabel(this);
    lab1->resize(800,550);
    lab1->setPixmap(QPixmap(":/Logo/shangHai.jpg"));
    lab1->setScaledContents(true);

    QLabel *lab2 = new QLabel(this);
    lab2->resize(400,100);
    lab2->move(250,150);
    lab2->setText("请选择你的身份");
    lab2->setStyleSheet("QLabel { "
                          "text-align: center;"
                          "font-size: 18pt;"
                          "}");

    usrBtn = new QPushButton("用户(1)",this);
    usrBtn->move(150,400);
    usrBtn->resize(150,80);
    usrBtn->setStyleSheet("QPushButton { "
                          "background-color: rgba(0, 0, 0, 60); "
                          "border: none; "
                          "font-size: 16pt;"
                          "} "
                          "QPushButton:hover { "
                          "background-color: rgba(0, 0, 0, 30); "
                          "font-size: 20pt;"
                          "}");

    adminBtn = new QPushButton("管理(2)",this);
    adminBtn->move(500,400);
    adminBtn->resize(150,80);
    adminBtn->setStyleSheet("QPushButton { "
                          "background-color: rgba(0, 0, 0, 60); "
                          "border: none; "
                          "font-size: 16pt;"
                          "} "
                          "QPushButton:hover { "
                          "background-color: rgba(0, 0, 0, 30); "
                          "font-size: 20pt;"
                          "}");
    connect(usrBtn,&QPushButton::clicked,this,&Widget::usrBtn_clicked);
    connect(adminBtn,&QPushButton::clicked,this,&Widget::adminBtn_clicked);

}

Widget::~Widget()
{
    delete ui;
}

void Widget::keyPressEvent(QKeyEvent *event)
{
    // 检查键盘事件
    if (event->key() == Qt::Key_1) {
     // 触发登录按钮点击
        usrBtn->click();
    } else if (event->key() == Qt::Key_2) {
     // 触发注册按钮点击
        adminBtn->click();
    }
    else {
            // 否则，调用基类的keyPressEvent处理其他按键
        QWidget::keyPressEvent(event);
    }
}

void Widget::usrBtn_clicked()
{
    this->close();
    emit usr_jump();
}

void Widget::adminBtn_clicked()
{
    this->close();
    emit admin_jump();
}
