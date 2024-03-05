#ifndef STRUCT
#define STRUCT
#include <QTcpSocket>
typedef struct auction_item{
    char name[20];              //拍品名称
    int state;                  //是否成交
    double starting_price;      //起拍价
    double cost_plus_price;     //最低加价
    double current_high;        //当前最高价
    double transaction_price;   //成交价格
    double profit;
    char seller_name[20];       //卖家
    char buyer_name[20];        //买家
}auction_item_info;

typedef struct user{
    int flag;   //表示用户请求   1-添加商品，2-修改商品，3-删除商品，4-查询所得，5-发出拍卖价格，6-取消拍卖，7-查询拍卖品
                           //11、查询获利  12、查询历史记录  13、删除商品(3)  14、修改商品(2)
                           //21、注册     22、登录
    int ok;     //0-不成功   1-成功
    int count;  //拍品个数
    auction_item_info good[128]; //拍品表
}usr_info;

typedef struct msg{
    int flag;   //表示是管理员还是普通用户  1、admin 2、普通
    char name[20];
    char passwd[20];
    int state;  //0-不在线  1-在线
    usr_info usr;
}msg_info;




#endif // STRUCT

