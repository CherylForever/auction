#include "adminwidget.h"
#include "ui_adminwidget.h"

adminWidget::adminWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::adminWidget)
{
    ui->setupUi(this);
    this->resize(800,550);
    this->setFixedSize(800,550);
    this->setWindowTitle("管理界面");

    QLabel *back = new QLabel(this);
    back->resize(800,550);
    back->setPixmap(QPixmap(":/Logo/f.jpg"));
    back->setScaledContents(true);

    queryHistoryBtn = new QPushButton("查询历史(1)",this);
    queryHistoryBtn->resize(250,100);
    queryHistoryBtn->move(110,120);
    queryHistoryBtn->setStyleSheet("QPushButton { "
                          "background-color: rgba(0, 0, 0, 60); "
                          "border: none; "
                          "font-size: 16pt;"
                          "} "
                          "QPushButton:hover { "
                          "background-color: rgba(0, 0, 0, 30); "
                          "font-size: 20pt;"
                          "}");

    queryProfitBtn = new QPushButton("查询利润(2)",this);
    queryProfitBtn->resize(250,100);
    queryProfitBtn->move(450,120);
    queryProfitBtn->setStyleSheet("QPushButton { "
                          "background-color: rgba(0, 0, 0, 60); "
                          "border: none; "
                          "font-size: 16pt;"
                          "} "
                          "QPushButton:hover { "
                          "background-color: rgba(0, 0, 0, 30); "
                          "font-size: 20pt;"
                          "}");

    updateBtn = new QPushButton("修改拍品信息(3)",this);
    updateBtn->resize(250,100);
    updateBtn->move(110,300);
    updateBtn->setStyleSheet("QPushButton { "
                          "background-color: rgba(0, 0, 0, 60); "
                          "border: none; "
                          "font-size: 16pt;"
                          "} "
                          "QPushButton:hover { "
                          "background-color: rgba(0, 0, 0, 30); "
                          "font-size: 20pt;"
                          "}");

    deleteBtn = new QPushButton("删除拍品信息(4)",this);
    deleteBtn->resize(250,100);
    deleteBtn->move(450,300);
    deleteBtn->setStyleSheet("QPushButton { "
                          "background-color: rgba(0, 0, 0, 60); "
                          "border: none; "
                          "font-size: 16pt;"
                          "} "
                          "QPushButton:hover { "
                          "background-color: rgba(0, 0, 0, 30); "
                          "font-size: 20pt;"
                          "}");

//    QLineEdit *updateEdit = new QLineEdit(this);
//    updateEdit->resize(150,50);
//    updateEdit->move(160,410);
//    updateEdit->setPlaceholderText("拍品");
//    updateEdit->setStyleSheet("background-color: rgba(255, 255, 255, 90);"
//                           "border: none;");

//    QLineEdit *deleteEdit = new QLineEdit(this);
//    deleteEdit->resize(150,50);
//    deleteEdit->move(500,410);
//    deleteEdit->setPlaceholderText("拍品");
//    deleteEdit->setStyleSheet("background-color: rgba(255, 255, 255, 90);"
//                              "border: none;");


    connect(queryProfitBtn,&QPushButton::clicked,this,&adminWidget::queryProfitBtn_slot);

    connect(updateBtn,&QPushButton::clicked,this,&adminWidget::updateBtn_slot);

    connect(deleteBtn,&QPushButton::clicked,this,&adminWidget::deleteBtn_slot);

    connect(queryHistoryBtn,&QPushButton::clicked,this,&adminWidget::queryHistory_slot);

}

adminWidget::~adminWidget()
{
    delete ui;
}

void adminWidget::keyPressEvent(QKeyEvent *event)
{
    // 检查键盘事件
    if (event->key() == Qt::Key_1)
    {
        // 触发查询按钮点击
        queryHistoryBtn->click();
    }
    else if (event->key() == Qt::Key_2)
    {
        // 触发查询利润按钮点击
        queryProfitBtn->click();
    }
    else if (event->key() == Qt::Key_3)
    {
        // 触发更新按钮点击
        updateBtn->click();
    }
    else if (event->key() == Qt::Key_4)
    {
        // 触发查询可拍品按钮点击
        deleteBtn->click();
    }
    else
    {
        // 否则，调用基类的keyPressEvent处理其他按键
        QWidget::keyPressEvent(event);
    }
}

void adminWidget::my_jump_slots()
{
    this->show();
}

void adminWidget::queryProfitBtn_slot()
{
    emit queryProfitBtn_signal();
}

void adminWidget::updateBtn_slot()
{
    emit update_signal();
}

void adminWidget::deleteBtn_slot()
{
    emit delete_signal();
}

void adminWidget::queryHistory_slot()
{
    emit queryHistory_signal();
}
