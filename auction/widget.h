#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QKeyEvent>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    void keyPressEvent(QKeyEvent *event) override;
signals:
    void usr_jump();
    void admin_jump();

public slots:
    void usrBtn_clicked();
    void adminBtn_clicked();

private:
    Ui::Widget *ui;

    QPushButton *usrBtn;
    QPushButton *adminBtn;
};

#endif // WIDGET_H
