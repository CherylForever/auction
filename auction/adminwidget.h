#ifndef ADMINWIDGET_H
#define ADMINWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QKeyEvent>

namespace Ui {
class adminWidget;
}

class adminWidget : public QWidget
{
    Q_OBJECT

public:
    explicit adminWidget(QWidget *parent = 0);
    ~adminWidget();
    void keyPressEvent(QKeyEvent *event) override;

signals:
    void queryProfitBtn_signal();

    void update_signal();

    void delete_signal();

    void queryHistory_signal();
public slots:
    void my_jump_slots();

    void queryProfitBtn_slot();

    void updateBtn_slot();

    void deleteBtn_slot();

    void queryHistory_slot();
private:
    Ui::adminWidget *ui;
    QPushButton *queryHistoryBtn;
    QPushButton *queryProfitBtn;
    QPushButton *updateBtn;
    QPushButton *deleteBtn;
};

#endif // ADMINWIDGET_H
