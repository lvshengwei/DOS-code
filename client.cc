#include<stdio.h>
#include <inttypes.h>
#include<cstdint>
#include<stdint.h>
#include<iostream>
#include<unistd.h>
#include<time.h>
#include<string>
//protobuf
#include"Message.pb.h"

#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include <errno.h>

using namespace std;
using namespace Message::protobuf;
const int BUFFSIZE = 1024;
const int TASKNUM = 100000;
extern int errno;

typedef struct{
    int workerid;
    string ip;
    string port;
}worker;

typedef struct{
    int flag;// 1,2,3三种结果
    int int32result;
    long long int64result;
    double dbresult;
}results;


//results* ReceiveMsg(char *buff, int BUFFSIZE, int socketfd, worker *workerinstance);
//int SendTask(string workerip, string workerport);



results* ReceiveMsg(char *buff, int BUFFSIZE, int socketfd, worker *workerinstance){
    int recvlen;
    //while((recvlen = recv(socketfd, buff, sizeof(buff), 0))<=0);
    cout<<"Receiving..."<<endl;
    while((recvlen = read(socketfd, buff, BUFFSIZE))<=0); // read and recv ??
    cout<<"Receive a message"<<endl;
    Msg msginstance;
    msginstance.ParseFromArray(buff, BUFFSIZE);
    int category = msginstance.msgcategory();

    switch(category){
        case 2:
            //master发送的worker的信息
            {
            string workerip = msginstance.ip();
            string workerport = msginstance.port();
            workerinstance->ip = workerip;
            workerinstance->port = workerport;
            break;
            }
        case 4:
            //worker发回的result, 设置results结构体指针，并返回指针
            {
            results *resultpointer = new results;
            if(msginstance.has_int32result()){
                resultpointer->int32result = msginstance.int32result();
                resultpointer->flag = 1;
            }
            else if(msginstance.has_int64result()){
                resultpointer->int64result = msginstance.int64result();
                resultpointer->flag = 2;
            }
            else if(msginstance.has_dbresult()){
                resultpointer->dbresult = msginstance.dbresult();
                resultpointer->flag = 3;
            }
            else{
                resultpointer->int32result = 0;
                resultpointer->flag = 1;
            }
            return resultpointer;
            break;
            }
        default:
            cout<<"wrong message category:"<<category<<endl;

    }
    return NULL;
}

int LinkMaster(){
    //建立socket
    int socketfd;
    struct sockaddr_in seraddr;
    string hostip = "127.0.0.1";

    //链接3次
    for(int i=0;i<3;i++){
        socketfd = socket(AF_INET, SOCK_STREAM, 0);
        if( socketfd > 0 ){
            cout<<"create socket success..."<<endl;
            break;
        }
        sleep(1);
    }

    //设置地址信息
    bzero(&seraddr, sizeof(seraddr));
    seraddr.sin_family = AF_INET;
    seraddr.sin_addr.s_addr = inet_addr(hostip.c_str());
    seraddr.sin_port = htons(9999);
    
    //连接服务器
    //int status = connect(socketfd, (struct sockaddr*)&seraddr, sizeof(seraddr));
    
    int status = connect(socketfd, (struct sockaddr*)&seraddr, sizeof(seraddr));
    if (status == 0){
        cout<<"connection is established successfully"<<endl;
    }
    else{
        cout<<"errno:"<<errno<<endl;
        cout<<"connect to master failed"<<endl;
        close(socketfd);
        return -1;
    }

    return socketfd;
}

worker * QueryMaster(int socketfd){
    
    // 向master查询
    Msg msginstance;
    msginstance.set_role(1);
    msginstance.set_msgcategory(1);
    //msginstance.set_ip("127.0.0.1");

    // protobuf的序列化方式之一
    char buff[BUFFSIZE];
    memset(buff, 0, BUFFSIZE);
    msginstance.SerializeToArray(buff, BUFFSIZE);

    if (send(socketfd, buff, strlen(buff), 0) < 0){
        cout << "send to server failed..." << endl;
        close(socketfd);
        return NULL;
        //break;
    }
    cout << "send success" << endl;
    //sleep(1);
    //worker *workerInstance = (worker *)malloc(sizeof(worker));

    // 接收worker信息
    worker *workerInstance = new worker;
    ReceiveMsg(buff, BUFFSIZE, socketfd, workerInstance);
    cout << "Worker info:" << workerInstance->ip << " " << workerInstance->port << endl;

    // 向worker发送任务，并接收返回信息
    // 先关闭与master的连接，再连接worker，
    //close(socketfd);
    return workerInstance;

}


int SendOneTask(string workerip, string workerport, int taskId){
    //12种操作
    string ops[] = {"int32+", "int32-", "int32*", "int32/", "int64+", "int64-", "int64*", "int64/", "db+", "db-", "db*", "db/"};

    int int32op1;
    int int32op2;
    long long op1int64;
    long long int64op2;
    double dbop1;
    double dbop2;
    string operation;

    //worker给client返回的任务结果
    int int32result; 
    long long int64result;
    double dbresult;

    //建立与worker的连接
    int workersocketfd;
    for(int i=0;i<3;i++){
        workersocketfd = socket(AF_INET, SOCK_STREAM, 0);
        if(workersocketfd>0){
            cout<<"create socket to worker success.."<<endl;
            break;
        }
        sleep(1);
    }

    struct sockaddr_in seraddr;
    bzero(&seraddr, sizeof(seraddr));
    seraddr.sin_family = AF_INET;
    seraddr.sin_addr.s_addr = inet_addr(workerip.c_str());
    seraddr.sin_port = htons(stoi(workerport));;

    // 连接worker
    int status = connect(workersocketfd, (struct sockaddr*)&seraddr, sizeof(seraddr));
    if(status == 0){ cout<<"connect to worker success.."<<endl; }
    else{ 
        cout<<"errno:"<<errno<<endl;
        cout<<"connect to worker failed..."<<endl;
        close(workersocketfd);
        return -1;
    }

    //发送一个任务
    cout << "task ID =" << taskId << endl;

    Msg msginstance;
    msginstance.set_role(1);
    msginstance.set_msgcategory(3);
    char buff[BUFFSIZE];
    msginstance.set_operation(ops[taskId % 12]);

    if (0 <= taskId % 12 && taskId % 12 <= 3)
    {
        //cout<<"case: "<<0<<endl;
        msginstance.set_int32op1(47);
        msginstance.set_int32op2(5);
    }
    else if (4 <= taskId % 12 && taskId % 12 <= 7)
    {
        msginstance.set_int64op1((long long)(159));
        msginstance.set_int64op2((long long)(36));
    }
    else if (8 <= taskId % 12 && taskId % 12 <= 11)
    {
        msginstance.set_dbop1(15.6);
        msginstance.set_dbop2(6.7);
    }

    // 发送task
    memset(buff, 0, BUFFSIZE);
    msginstance.SerializeToArray(buff, BUFFSIZE);
    if (send(workersocketfd, buff, strlen(buff), 0) < 0)
    {
        cout << "send task to worker failed..." << endl;
        close(workersocketfd);
        return -1;
    }
    cout << "send task success" << endl;

    // 接收结果
    worker *temp = new worker;
    results *resultpointer = ReceiveMsg(buff, BUFFSIZE, workersocketfd, temp);
    if (resultpointer != NULL)
    {
        switch (resultpointer->flag)
        {
        case 1:
            cout << "int32 result:" << resultpointer->int32result << endl;
            break;
        case 2:
            cout << "int64 result:" << resultpointer->int64result << endl;
            break;
        case 3:
            cout << "double result:" << resultpointer->dbresult << endl;
            break;
        default:
            cout << "error result!" << endl;
            break;
        }
    }


    // 关闭与worker的socket
    close(workersocketfd);
    

}


int main(int argc, char const *argv[])
{
    
    //sleep(1);
    int mastersocketfd = LinkMaster();

    for(int i=0;i<TASKNUM;i++){
        worker *workerInstance = QueryMaster(mastersocketfd);
        SendOneTask(workerInstance->ip, workerInstance->port, i);

    }
    
    cout<<"client has finished all tasks..."<<endl;

    close(mastersocketfd);

    return 0;
}



