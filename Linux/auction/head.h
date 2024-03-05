#ifndef __HEAD_H__
#define __HEAD_H__

#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h> 
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sqlite3.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>

#include <openssl/sha.h>

#define SER_PORT 8888
#define SER_IP "192.168.126.84"


typedef struct auction_item{
    char name[20];              //拍品名称
    int state;                  //拍品状态  0    1
    double starting_price;      //起拍价
    double cost_plus_price;     //最低加价
    double current_high;        //当前最高价
    double transaction_price;   //成交价格
    double profit;
    char seller_name[20];       //卖家
    char buyer_name[20];        //买家
}auction_item_info;

typedef struct user{
    int flag;                       //表示用户请求   1-添加商品，2-修改商品，3-删除商品，4-查询可拍卖品，5-拍卖品确认卖出
                                     //  6.买拍品
                                    //11、查询获利  12、查询历史记录  13、删除商品(3)  14、修改商品(2)
                                        //21、注册     22、登录
    int ok;                         //0-不成功   1-成功
    int count;                      //拍品个数
    auction_item_info good[128]; //拍品表
}usr_info;

typedef struct msg{
    int flag;                       //表示是管理员还是普通用户  1、admin 2、普通
    char name[20];
    char passwd[20];
    int state;                  //0-不在线  1-在线
    usr_info usr;
}msg_info;




//函数声明如下
int do_cli(int fd,sqlite3 *db);
int do_register(int fd, sqlite3 *db, msg_info *msg);
int do_login(int fd, sqlite3 *db, msg_info *msg);
int do_add( int fd, sqlite3 *db, msg_info *msg, const char *usrName);
int do_update( int fd, sqlite3 *db, msg_info *msg, const char *usrName);
int do_delete( int fd, sqlite3 *db, msg_info *msg, const char *usrName);
int do_query_auctable( int fd, sqlite3 *db, msg_info *msg, const char *usrName);
int do_sell_good( int fd, sqlite3 *db, msg_info *msg, const char *usrName);
int sell_callback(void* para,int argc,char** argv,char** argv_name);
int do_bid(int fd, sqlite3 *db, msg_info *msg, const char *usrName);
int do_profit(int fd, sqlite3 *db, msg_info *msg, const char *usrName);
int do_allgoods(int fd, sqlite3 *db, msg_info *msg, const char *usrName);
int search_usr(sqlite3 *db,msg_info *msg , const char *Name);

void sha256(const unsigned char *data, size_t len, unsigned char *hash);
#endif