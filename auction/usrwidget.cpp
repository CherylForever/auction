#include "usrwidget.h"
#include "ui_usrwidget.h"

usrWidget::usrWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::usrWidget)
{
    ui->setupUi(this);
    this->resize(600,700);
    this->setFixedSize(600,700);
    this->setWindowTitle("用户界面");

    QLabel *back = new QLabel(this);
    back->resize(600,700);
    back->setPixmap(QPixmap(":/Logo/f.jpg"));
    back->setScaledContents(true);

    insertBtn = new QPushButton("添加拍品(1)",this);
    deleteBtn = new QPushButton("删除拍品(2)",this);
    updateBtn = new QPushButton("修改拍品(3)",this);

    auctableBtn = new QPushButton("可拍物品(4)",this);
    sellgoodBtn = new QPushButton("卖出物品(5)",this);
    auctionrecordBtn = new QPushButton("拍卖物品(6)",this);

    insertBtn->resize(150,80);
    insertBtn->move(100,50);
    insertBtn->setStyleSheet("QPushButton {"
                          "background-color: rgba(255, 255, 255, 128);"
                          "border: 1px solid rgba(0, 0, 0, 128);"
                          "}");

    deleteBtn->resize(150,80);
    deleteBtn->move(100,150);
    deleteBtn->setStyleSheet("QPushButton {"
                          "background-color: rgba(255, 255, 255, 128);"
                          "border: 1px solid rgba(0, 0, 0, 128);"
                          "}");

    updateBtn->resize(150,80);
    updateBtn->move(100,250);
    updateBtn->setStyleSheet("QPushButton {"
                          "background-color: rgba(255, 255, 255, 128);"
                          "border: 1px solid rgba(0, 0, 0, 128);"
                          "}");

    auctableBtn->resize(150,80);
    auctableBtn->move(100,350);
    auctableBtn->setStyleSheet("QPushButton {"
                          "background-color: rgba(255, 255, 255, 128);"
                          "border: 1px solid rgba(0, 0, 0, 128);"
                          "}");

    sellgoodBtn->resize(150,80);
    sellgoodBtn->move(100,450);
    sellgoodBtn->setStyleSheet("QPushButton {"
                          "background-color: rgba(255, 255, 255, 128);"
                          "border: 1px solid rgba(0, 0, 0, 128);"
                          "}");

    auctionrecordBtn->resize(150,80);
    auctionrecordBtn->move(100,550);
    auctionrecordBtn->setStyleSheet("QPushButton {"
                          "background-color: rgba(255, 255, 255, 128);"
                          "border: 1px solid rgba(0, 0, 0, 128);"
                          "}");

    connect(insertBtn,&QPushButton::clicked,this,&usrWidget::insertBtn_slot);

    connect(deleteBtn,&QPushButton::clicked,this,&usrWidget::deleteBtn_slot);

    connect(updateBtn,&QPushButton::clicked,this,&usrWidget::updateBtn_slot);

    connect(auctableBtn,&QPushButton::clicked,this,&usrWidget::auctableBtn_slot);

    connect(sellgoodBtn,&QPushButton::clicked,this,&usrWidget::sellgoodBtn_slot);

    connect(auctionrecordBtn,&QPushButton::clicked,this,&usrWidget::auctionrecordBtn_slot);



}

usrWidget::~usrWidget()
{
    delete ui;
}

void usrWidget::keyPressEvent(QKeyEvent *event)
{
    // 检查键盘事件
    if (event->key() == Qt::Key_1)
    {
        // 触发新增按钮点击
        insertBtn->click();
    }
    else if (event->key() == Qt::Key_2)
    {
        // 触发删除按钮点击
        deleteBtn->click();
    }
    else if (event->key() == Qt::Key_3)
    {
        // 触发更新按钮点击
        updateBtn->click();
    }
    else if (event->key() == Qt::Key_4)
    {
        // 触发查询可拍品按钮点击
        auctableBtn->click();
    }
    else if (event->key() == Qt::Key_5)
    {
        // 触发卖出按钮点击
        sellgoodBtn->click();
    }
    else if (event->key() == Qt::Key_6)
    {
        // 触发拍卖按钮点击
        auctionrecordBtn->click();
    }
    else {
            // 否则，调用基类的keyPressEvent处理其他按键
        QWidget::keyPressEvent(event);
    }
}

void usrWidget::my_jump_slots()
{
    this->show();
}


void usrWidget::insertBtn_slot()
{
    emit insert_signal();
    this->close();
}

void usrWidget::deleteBtn_slot()
{
    emit delete_signal();
    this->close();
}

void usrWidget::updateBtn_slot()
{
    emit update_signal();
}

void usrWidget::auctableBtn_slot()
{
    emit auctable_signal();
}

void usrWidget::sellgoodBtn_slot()
{
    emit sellgood_signal();
}

void usrWidget::auctionrecordBtn_slot()
{
    emit auctionrecord_signal();
    this->close();
}
