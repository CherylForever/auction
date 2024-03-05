#include "head.h"

//此函数用于处理服务器发来的消息
int do_cli(int fd,sqlite3 *db)
{
    msg_info msg;
    puts("aaa");
    char usrName[20];
    while (1)
    {
        int res = recv( fd, (char *)&msg, sizeof(msg), 0);
        if(res == 0)
        {
            printf("客户端已经下线\n");
            char *errmsg;
            char sql[1024];
            bzero(sql,sizeof(sql));
            sprintf(sql,"update usr set state = 0 where name = \"%s\";",msg.name);
            if(sqlite3_exec(db, sql, NULL, NULL, &errmsg) != SQLITE_OK)
            {
                printf("%s\n", errmsg);
            }
            puts("客户端状态已经修改为离线");
            break;
        }
        int len = strlen(msg.name);
        printf("len=%d\n",len);
        if(strlen(msg.name))
        {
            strcpy(usrName,msg.name);
        }
        puts(usrName);
        switch(msg.usr.flag)
        {
        case 21:
            do_register( fd, db, &msg );
            break;
        case 22:
            do_login( fd, db, &msg );
            break;
        case 1:
            do_add( fd, db, &msg, usrName );
            break;
        case 2:
            do_update( fd, db, &msg, usrName );
            break;
        case 3:
            do_delete( fd, db, &msg, usrName );
            break;
        case 4:  //
            do_query_auctable( fd, db, &msg, usrName );  //查询可拍卖品
            break;
        case 5:
            do_sell_good( fd, db, &msg, usrName );
            break;
        case 6:
            do_bid(fd, db, &msg, usrName);
            break;
        case 11:
            do_profit(fd, db, &msg, usrName);
            break;
        case 12:
            do_allgoods(fd, db, &msg, usrName);
        }

        if(send(fd, (char *)&msg, sizeof(msg), 0) < 0 )
        {
            perror("send error");
            return -1;
        }

    }
    close(fd);

    return 0;
}

int do_register(int fd, sqlite3 *db, msg_info *msg)
{
    char *errmsg;
    char sql[1024];

    const char *message = msg->passwd;
    unsigned char hash[SHA256_DIGEST_LENGTH];
    sha256((unsigned char *)message, strlen(message), hash);

    char sha256_string[65]; 
    for (int i = 0; i < 32; i++) {
        sprintf(sha256_string + (i * 2), "%02x", hash[i]);
    }

    sprintf(sql,"insert into usr values(\"%s\",\"%s\",%d);",msg->name,sha256_string,msg->state);
    if(sqlite3_exec(db, sql, NULL, NULL, &errmsg) != SQLITE_OK)
	{
		printf("%s\n", errmsg);
		msg->usr.ok = 0;
	}
    else
	{
		printf("register success\n");
		msg->usr.ok = 1;
	}
    printf("%d\n",msg->usr.ok);

    return 0;

}

int do_login(int fd, sqlite3 *db, msg_info *msg)
{
    char *errmsg;
    char sql[1024];

    int nrow;
	int ncloumn;    
    char **resultp;

    const char *message = msg->passwd;
    unsigned char hash[SHA256_DIGEST_LENGTH];
    sha256((unsigned char *)message, strlen(message), hash);

    char sha256_string[65]; 
    for (int i = 0; i < 32; i++) {
        sprintf(sha256_string + (i * 2), "%02x", hash[i]);
    }

    sprintf(sql, "select * from usr where name = \"%s\" and passwd = \"%s\" and state = 0;", msg->name, sha256_string);
    if(sqlite3_get_table(db,sql,&resultp,&nrow,&ncloumn, &errmsg)!= SQLITE_OK)
	{ 
		printf("%s\n", errmsg);
		return -1;
	}
    else
	{
		printf("get_table ok!\n");
	}
    if(nrow == 1)
	{
		msg->usr.ok = 1;
        bzero(sql,sizeof(sql));
        sprintf(sql,"update usr set state = 1 where name = \"%s\";",msg->name);
        if(sqlite3_exec(db, sql, NULL, NULL, &errmsg) != SQLITE_OK)
	    {
		    printf("%s\n", errmsg);
	    }
        else {
            printf("login success\n");
        }
		return 1;
	}
    else if(nrow == 0) //没有找到
	{
		msg->usr.ok = 0;
	}

    return 0;
}

int do_add( int fd, sqlite3 *db, msg_info *msg, const char *usrName)
{
    char *errmsg;
    char sql[1024];
	int nrow;
	int ncloumn;    
    char **resultp;

    sprintf(sql,"select name = \"%s\" from usr; ",msg->usr.good[0].seller_name);
    if(sqlite3_get_table(db,sql,&resultp,&nrow,&ncloumn, &errmsg)!= SQLITE_OK)
	{ 
		printf("%s\n", errmsg);
		msg->usr.ok = 0;
        puts("6");
	}
    else{
        
        for(int i = 0; i < nrow; i++)
        {
            if(*(resultp+ncloumn*(i+1)) != NULL)
            {
                msg->usr.ok = 1;
                puts("s");
                printf("%s\n",*(resultp+ncloumn*(i+1)));
                break;
            }
            else{
                msg->usr.ok = 2;
                puts("1");
                break;
            }

        }
        sprintf(sql,"insert into goods values(\"%s\",%.2lf,%.2lf,%.2lf,\"%s\",\"%s\",%d);",\
        msg->usr.good[0].name,\
        msg->usr.good[0].starting_price,\
        msg->usr.good[0].current_high,\
        msg->usr.good[0].transaction_price,\
        msg->usr.good[0].seller_name,\
        msg->usr.good[0].buyer_name,\
        msg->usr.good[0].state\
        );
        if(sqlite3_exec(db, sql, NULL, NULL, &errmsg) != SQLITE_OK)
        {
            printf("%s\n", errmsg);
            puts("s00");
            msg->usr.ok = 0;
        }
        else{
            puts("添加商品成功");
            msg->usr.ok = 1;
            strcpy(msg->name, usrName);
        }
    }

    return 0;

}

int do_update( int fd, sqlite3 *db, msg_info *msg, const char *usrName)
{
    char *errmsg;
    char sql[1024];
    int nrow;
	int ncloumn;    
    char **resultp;

    sprintf(sql,"select sellername from goods where name = \"%s\" ;",msg->usr.good[0].name);
    if(sqlite3_get_table(db,sql,&resultp,&nrow,&ncloumn, &errmsg)!= SQLITE_OK)
	{ 
		printf("%s\n", errmsg);
		msg->usr.ok = 0;
	}
    else{
        if(strcmp(msg->usr.good[0].seller_name,"admin")==0)
        {
            sprintf(sql," UPDATE goods SET startprice = %.2lf WHERE ( name = \"%s\" and state = 0 );",\
            msg->usr.good[0].starting_price,\
            msg->usr.good[0].name\
            );
            if(sqlite3_exec(db, sql, NULL, NULL, &errmsg) != SQLITE_OK)
            {
                printf("%s\n", errmsg);
                msg->usr.ok = 0;
            }
            else{
                // 检查是否有行被更新
                int changes = sqlite3_changes(db);
                if (changes > 0)
                {
                    puts("修改商品成功");
                    msg->usr.ok = 1;
                    strcpy(msg->name, usrName);
                }
                else
                {
                    // 没有行被更新，可能是因为state不是0
                    printf("修改商品失败\n");
                    msg->usr.ok = 0;
                    strcpy(msg->name, usrName);
                }
            }
        }
        else{
            if(strcmp(*(resultp+ncloumn),msg->usr.good[0].seller_name)!= 0 )
            {
                msg->usr.ok = 2;
            }
            else{
                sprintf(sql," UPDATE goods SET startprice = %.2lf WHERE ( name = \"%s\" and state = 0 );",\
                msg->usr.good[0].starting_price,\
                msg->usr.good[0].name\
                );
                if(sqlite3_exec(db, sql, NULL, NULL, &errmsg) != SQLITE_OK)
                {
                    printf("%s\n", errmsg);
                    msg->usr.ok = 0;
                }
                else{
                    // 检查是否有行被更新
                    int changes = sqlite3_changes(db);
                    if (changes > 0)
                    {
                        puts("修改商品成功");
                        msg->usr.ok = 1;
                        strcpy(msg->name, usrName);
                    }
                    else
                    {
                        // 没有行被更新，可能是因为state不是0
                        printf("修改商品失败\n");
                        msg->usr.ok = 0;
                        strcpy(msg->name, usrName);
                    }
                }
            }
        }
    }



    return 0;
}

int do_delete( int fd, sqlite3 *db, msg_info *msg, const char *usrName)
{
    char *errmsg;
    char sql[1024];
	int nrow;
	int ncloumn;    
    char **resultp;

    sprintf(sql,"select sellername from goods where name = \"%s\" ;",msg->usr.good[0].name);
    if(sqlite3_get_table(db,sql,&resultp,&nrow,&ncloumn, &errmsg)!= SQLITE_OK)
	{ 
		printf("%s\n", errmsg);
		msg->usr.ok = 0;
	}
    else{
        if(strcmp(msg->usr.good[0].seller_name,"admin")==0)
        { 
            sprintf(sql,"delete from goods where name = \"%s\" and state = 0 ;",msg->usr.good[0].name);
            if(sqlite3_exec(db, sql, NULL, NULL, &errmsg) != SQLITE_OK)
            {
                printf("%s\n", errmsg);
                msg->usr.ok = 0;
            }
            else
            {
                // 检查被删除的行数
                int rows_deleted = sqlite3_changes(db);
                if (rows_deleted > 0)
                {
                    puts("删除商品成功");
                    msg->usr.ok = 1;
                    strcpy(msg->name, usrName);
                }
                else
                {
                    // 没有行被删除，可能是因为没有匹配的记录
                    printf("删除商品失败\n");
                    msg->usr.ok = 0;
                    strcpy(msg->name, usrName);
                }
            }
        }
        else{
            if(strcmp(*(resultp+ncloumn),msg->usr.good[0].seller_name)!= 0 )
            {
                msg->usr.ok = 2;
            }
            else
            {
                sprintf(sql,"delete from goods where name = \"%s\" and state = 0 ;",msg->usr.good[0].name);
                if(sqlite3_exec(db, sql, NULL, NULL, &errmsg) != SQLITE_OK)
                {
                    printf("%s\n", errmsg);
                    msg->usr.ok = 0;
                }
                else
                {
                    // 检查被删除的行数
                    int rows_deleted = sqlite3_changes(db);
                    if (rows_deleted > 0)
                    {
                        puts("删除商品成功");
                        msg->usr.ok = 1;
                        strcpy(msg->name, usrName);
                    }
                    else
                    {
                        // 没有行被删除，可能是因为没有匹配的记录
                        printf("删除商品失败\n");
                        msg->usr.ok = 0;
                        strcpy(msg->name, usrName);
                    }
                }
            }
        }
        
    }
    



    return 0;

}

int do_query_auctable( int fd, sqlite3 *db, msg_info *msg, const char *usrName)
{
    char *errmsg;
    char sql[1024];
	int nrow;
	int ncloumn;    
    char **resultp;

    sprintf(sql,"select *from goods where state = 0; ");
    if(sqlite3_get_table(db,sql,&resultp,&nrow,&ncloumn, &errmsg)!= SQLITE_OK)
	{ 
		printf("%s\n", errmsg);
		msg->usr.ok = 0;
	}
    else{
        puts("获取可拍卖品成功");
        msg->usr.ok = 1;
        msg->usr.count = nrow;
        // printf("%s\n",*(resultp+ncloumn*(1+1)+1));
        for(int i = 0;i < nrow ;i++ )
        {
            strcpy(msg->usr.good[i].name,*(resultp+ncloumn*(i+1)));
            msg->usr.good[i].starting_price = atof(*(resultp+ncloumn*(i+1)+1));
            msg->usr.good[i].current_high = atof(*(resultp+ncloumn*(i+1)+2)); 
            msg->usr.good[i].state = atoi(*(resultp+ncloumn*(i+1)+6));
            printf("%.2lf\n",msg->usr.good[i].starting_price);
        }
        puts("aaa");
        sqlite3_free_table(resultp);
    }
    return 0;
}

int do_sell_good( int fd, sqlite3 *db, msg_info *msg, const char *usrName)
{
    char *errmsg;
    char sql[1024];
    int nrow;
	int ncloumn;    
    char **resultp;
    double transaction_price;

    sprintf(sql,"select sellername,currenthigh from goods where name = \"%s\" ;",msg->usr.good[0].name);
    if(sqlite3_get_table(db,sql,&resultp,&nrow,&ncloumn, &errmsg)!= SQLITE_OK)
	{ 
		printf("%s\n", errmsg);
		msg->usr.ok = 0;
	}
    else{
        if(strcmp(*(resultp+ncloumn),msg->usr.good[0].seller_name)!= 0 )
        {
            msg->usr.ok = 2;
        }
        else if(atof(*(resultp+ncloumn+1)) == 0.0)
        {
            msg->usr.ok = 3;
        }
        else{
            sprintf(sql,"select currenthigh from goods where name = \"%s\";",msg->usr.good[0].name);
            if(sqlite3_get_table(db,sql,&resultp,&nrow,&ncloumn, &errmsg)!= SQLITE_OK)
            { 
                printf("%s\n", errmsg);
                msg->usr.ok = 0;
            }
            else{
                transaction_price = atof(*(resultp+ncloumn));
                sprintf(sql,"update goods set state = 1,transactionprice = %.2lf where name = \"%s\" and state = 0;",transaction_price,msg->usr.good[0].name);
                if(sqlite3_exec(db, sql, NULL, NULL, &errmsg) != SQLITE_OK)
                {
                    printf("%s\n", errmsg);
                    msg->usr.ok = 0;
                }
                else{
                    // 检查是否有行被更新
                    int changes = sqlite3_changes(db);
                    if (changes > 0)
                    {
                        puts("成功卖出");
                        msg->usr.ok = 1;
                        strcpy(msg->name, usrName);
                        
                        //插入到利益表
                        char sql1[1024];
                        char *errmsg1;

                        double t_price;

                        sprintf(sql,"select * from goods where name = \"%s\" ;",msg->usr.good[0].name);
                        if(sqlite3_exec(db, sql, sell_callback, (void *)db, &errmsg) != SQLITE_OK)
                        {
                            printf("%s\n", errmsg);     
                        }
                        changes = sqlite3_changes(db);
                        if (changes > 0)
                        {
                            puts("成功查询");
                            msg->usr.ok = 1;
                            strcpy(msg->name, usrName);

                        }
                        else{
                            printf("失败查询\n");
                            msg->usr.ok = 0;
                            strcpy(msg->name, usrName);
                        }
                    }
                    else
                    {
                        // 没有行被更新，可能是因为state不是0
                        printf("卖出失败\n");
                        msg->usr.ok = 0;
                        strcpy(msg->name, usrName);
                    }

                }
            }
        }
    }

    return 0;
}

int sell_callback(void* para,int argc,char** argv,char** argv_name)
{
	sqlite3 *db1;
    db1 = (sqlite3 *)para;
    char name[20];
    strcpy(name,argv[0]);

    double price = atof(argv[3]);
    printf("%.2f\n",price);
    puts(name);

    double profit = price*0.1;
    
    char *errmsg;
    char sql[1024];
    sprintf(sql,"insert into profit values(\"%s\",%.2lf);",name,profit);
    if(sqlite3_exec(db1, sql, NULL, NULL, &errmsg) != SQLITE_OK)
    {
        puts("插入利润表失败");
        printf("%s\n", errmsg);
    }
    else{
        puts("插入利润表成功");
    }

    return 0;
}

int do_bid(int fd, sqlite3 *db, msg_info *msg, const char *usrName)
{
    char *errmsg;
    char sql[1024];
    int nrow;
	int ncloumn;    
    char **resultp;


    sprintf(sql,"select startprice,currenthigh from goods where name = \"%s\";",msg->usr.good[0].name);
    if(sqlite3_get_table(db,sql,&resultp,&nrow,&ncloumn, &errmsg)!= SQLITE_OK)
	{ 
		printf("%s\n", errmsg);
		msg->usr.ok = 0;
	}
    else{
        if(atof(*(resultp+ncloumn)) > msg->usr.good[0].current_high || atof(*(resultp+ncloumn+1)) >= msg->usr.good[0].current_high )
        {
            msg->usr.ok = 2;
        }
        else
        {
            sprintf(sql,"update goods set buyername = \"%s\" , currenthigh = %.2lf where name = \"%s\" and state = 0 ;",
            msg->usr.good[0].buyer_name,
            msg->usr.good[0].current_high,
            msg->usr.good[0].name);
            
            if(sqlite3_exec(db, sql, NULL, NULL, &errmsg) != SQLITE_OK)
            {
                printf("%s\n", errmsg);
                msg->usr.ok = 0;
            }
            else
            {
                // 检查是否有行被更新
                int changes = sqlite3_changes(db);
                if (changes > 0)
                {
                    puts("出价成功");
                    msg->usr.ok = 1;
                    strcpy(msg->name, usrName);
                }
                else
                {
                    // 没有行被更新，可能是因为state不是0
                    printf("出价失败\n");
                    msg->usr.ok = 0;
                }
            }
        }
    }



    

}

int do_profit(int fd, sqlite3 *db, msg_info *msg, const char *usrName)
{
    char *errmsg;
    char sql[1024];
	int nrow;
	int ncloumn;    
    char **resultp;
    sprintf(sql,"select *from profit; ");
    if(sqlite3_get_table(db,sql,&resultp,&nrow,&ncloumn, &errmsg)!= SQLITE_OK)
	{ 
		printf("%s\n", errmsg);
		msg->usr.ok = 0;
	}
    else{
        puts("获取利润成功");
        msg->usr.ok = 1;
        msg->usr.count = nrow;
        // printf("%s\n",*(resultp+ncloumn*(1+1)+1));
        for(int i = 0;i < nrow ;i++ )
        {
            strcpy(msg->usr.good[i].name,*(resultp+ncloumn*(i+1)));
            msg->usr.good[i].profit = atof(*(resultp+ncloumn*(i+1)+1));
        }
        puts("aaa");
        sqlite3_free_table(resultp);
    }
    return 0;
}

int do_allgoods(int fd, sqlite3 *db, msg_info *msg, const char *usrName)
{
    char *errmsg;
    char sql[1024];
	int nrow;
	int ncloumn;    
    char **resultp;

    sprintf(sql,"select *from goods; ");
    if(sqlite3_get_table(db,sql,&resultp,&nrow,&ncloumn, &errmsg)!= SQLITE_OK)
	{ 
		printf("%s\n", errmsg);
		msg->usr.ok = 0;
	}
    else{
        puts("获取所有拍卖品成功");
        msg->usr.ok = 1;
        msg->usr.count = nrow;
        // printf("%s\n",*(resultp+ncloumn*(1+1)+1));
        for(int i = 0;i < nrow ;i++ )
        {
            strcpy(msg->usr.good[i].name,*(resultp+ncloumn*(i+1)));
            msg->usr.good[i].starting_price = atof(*(resultp+ncloumn*(i+1)+1));
            msg->usr.good[i].current_high = atof(*(resultp+ncloumn*(i+1)+2)); 
            msg->usr.good[i].transaction_price = atof(*(resultp+ncloumn*(i+1)+3));
            strcpy(msg->usr.good[i].seller_name,*(resultp+ncloumn*(i+1)+4));
            strcpy(msg->usr.good[i].buyer_name,*(resultp+ncloumn*(i+1)+5));
            msg->usr.good[i].state = atoi(*(resultp+ncloumn*(i+1)+6));
            // printf("%.2lf\n",msg->usr.good[i].starting_price);
        }
        puts("aaa");
        sqlite3_free_table(resultp);
    }
    return 0;
}

int search_usr(sqlite3 *db,msg_info *msg , const char *Name)
{

}

void sha256(const unsigned char *data, size_t len, unsigned char *hash) 
{
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, data, len);
    SHA256_Final(hash, &sha256);
}