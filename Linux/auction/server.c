#include "head.h"

int main(int argc, char const *argv[])
{
    //创建套接字
	int sfd  = socket(AF_INET,SOCK_STREAM,0/*IPPROTO_TCP*/);
	if(sfd==-1)
	{
		perror("socket error");
		return -1;
	}

    //将端口号快速重用
    int reuse =1;
	if(setsockopt(sfd,SOL_SOCKET,SO_REUSEADDR,&reuse,sizeof(reuse))==-1)
	{
		perror("setsockopt error");
		return -1;
	}

    //填充服务器的地址信息结构体
    struct sockaddr_in sin;
	sin.sin_family=AF_INET;
	sin.sin_port=htons(SER_PORT);
	sin.sin_addr.s_addr=inet_addr(SER_IP);

    sqlite3 *db;
    int newfd = -1;            //存放用于跟新客户端通信的文件描述符
    pid_t pid = 0;                //存放子进程的pid号


    //打开数据库
    if(sqlite3_open("./my.db",&db)!=SQLITE_OK)
    {
        printf("sqlite open error\n");
        return -1;
    }
    printf("数据库打开成功\n");

    //绑定
	if(bind(sfd,(struct sockaddr*)&sin,sizeof(sin))==-1)
	{
		perror("bind error");
		return -1;
	}

    //将套接字设置成监听状态
	if(listen(sfd,128)==-1)
	{
		perror("listen error");
		return -1;
	}
    
    signal(SIGCHLD,SIG_IGN);

    //进行相关操作
    while(1)
    {   
        newfd = accept(sfd, NULL,NULL);   
        if(newfd == -1)
        {
            perror("accept error");
            return -1;
        }
        pid = fork();           //创建子进程
        if(pid<0)
        {
            perror("fork error");
            return -1;
        }
        else if(pid==0)  //子进程
        {
            //处理客户端消息
            close(sfd);                 
            do_cli(newfd,db);
            exit(0);
        }
        else   //父进程
        {
            close(newfd);
        }
    }

    return 0;
}
