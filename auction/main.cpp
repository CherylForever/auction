#include "widget.h"
#include "usrlogin.h"
#include "adminlogin.h"
#include "adminwidget.h"
#include "usrregister.h"
#include "usrwidget.h"
#include "usrinsertdate.h"
#include "usrdeletedate.h"
#include "usrupdatedate.h"
#include "usrauctable.h"
#include "usrbuygoods.h"
#include "adminprofit.h"
#include "usrsellgood.h"
#include "adminupdate.h"
#include "admindelete.h"
#include "adminallgood.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();

    //连接到用户登录
    usrLogin usrlog;
    QObject::connect(&w,&Widget::usr_jump,&usrlog,&usrLogin::my_jump_slots);

    //连接到管理登录
    adminLogin adminlog;
    QObject::connect(&w,&Widget::admin_jump,&adminlog,&adminLogin::my_jump_slots);

    //连接到管理界面
    adminWidget adWidget;
    QObject::connect(&adminlog,&adminLogin::adminlogin_jump,&adWidget,&adminWidget::my_jump_slots);

    //管理更新界面
    adminUpdate adupdate;
    QObject::connect(&adWidget,&adminWidget::update_signal,&adupdate,&adminUpdate::my_jump_slots);

    //管理删除界面
    adminDelete addelete;
    QObject::connect(&adWidget,&adminWidget::delete_signal,&addelete,&adminDelete::my_jump_slots);

    //管理查询所有商品信息
    adminAllgood adallgood;
    QObject::connect(&adWidget,&adminWidget::queryHistory_signal,&adallgood,&adminAllgood::my_jump_slots);

    //用户注册界面
    usrRegister usrregi;
    QObject::connect(&usrlog,&usrLogin::regi_jump,&usrregi,&usrRegister::my_jump_slots);

    //用户界面
    usrWidget usrwid;
    QObject::connect(&usrlog,&usrLogin::usr_jump,&usrwid,&usrWidget::my_jump_slots);

    //用户新增拍品
    usrInsertDate usrinsert;
    QObject::connect(&usrwid,&usrWidget::insert_signal,&usrinsert,&usrInsertDate::my_jump_slots);

    //用户删除拍品界面
    usrDeleteDate usrdelete;
    QObject::connect(&usrwid,&usrWidget::delete_signal,&usrdelete,&usrDeleteDate::my_jump_slots);

    //用户更新拍品界面
    usrUpdateDate usrupdate;
    QObject::connect(&usrwid,&usrWidget::update_signal,&usrupdate,&usrUpdateDate::my_jump_slots);

    //用户显示可拍卖物品界面
    usrAuctable usrauct;
    QObject::connect(&usrwid,&usrWidget::auctable_signal,&usrauct,&usrAuctable::my_jump_slots);

    //用户确定卖出拍品界面
    usrSellGood usrsellgood;
    QObject::connect(&usrwid,&usrWidget::sellgood_signal,&usrsellgood,&usrSellGood::my_jump_slots);


    //用户出价界面
    usrBuyGoods usrbuy;
    QObject::connect(&usrwid,&usrWidget::auctionrecord_signal,&usrbuy,&usrBuyGoods::my_jump_slots);

    //管理员查利润界面
    adminProfit adminpro;
    QObject::connect(&adWidget,&adminWidget::queryProfitBtn_signal,&adminpro,&adminProfit::my_jump_slots);

    //当用户新增完商品后,回到用户界面
    QObject::connect(&usrinsert,&usrInsertDate::inserttowidget_signal,&usrwid,&usrWidget::my_jump_slots);

    //当用户修改完商品之后,回到用户界面
    QObject::connect(&usrupdate,&usrUpdateDate::updatetowidget_signal,&usrwid,&usrWidget::my_jump_slots);

    //当用户删除完商品之后,回到用户界面
    QObject::connect(&usrdelete,&usrDeleteDate::deletetowidget_signal,&usrwid,&usrWidget::my_jump_slots);

    //当用户确定卖出商品时，回到用户界面
    QObject::connect(&usrsellgood,&usrSellGood::sell_signal,&usrwid,&usrWidget::my_jump_slots);

    //当用户出价之后,回到用户界面
    QObject::connect(&usrbuy,&usrBuyGoods::buytoWidget_signal,&usrwid,&usrWidget::my_jump_slots);

    //用户退出查询界面时，跳转到用户界面
    QObject::connect(&usrauct,&usrAuctable::Btn1_signal,&usrwid,&usrWidget::my_jump_slots);

    //当管理员退出查询利润界面时，跳转到管理界面
    QObject::connect(&adminpro,&adminProfit::adprofittoWidget_signal,&adWidget,&adminWidget::my_jump_slots);

    //当管理员退出修改界面时，跳转到管理界面
    QObject::connect(&adupdate,&adminUpdate::updatetowidget_signal,&adWidget,&adminWidget::my_jump_slots);

    //当管理员退出删除界面时，跳转到管理界面
    QObject::connect(&addelete,&adminDelete::deletetowidget_signal,&adWidget,&adminWidget::my_jump_slots);

    //当管理员退出查询总界面时，跳转到管理界面
    QObject::connect(&adallgood,&adminAllgood::Btn1_signal,&adWidget,&adminWidget::my_jump_slots);

    return a.exec();
}
