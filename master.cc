#include <iostream>
#include <string>
#include <ctime>
#include <vector>
//for protobuf
#include "Message.pb.h" 
//for socket
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <string.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <unistd.h>

using namespace std;
using namespace Message::protobuf ;

const int BUFFSIZE = 1024;
const int QLEN = 10 ;

//set worker struct
typedef struct
{
    int worker_id;
    string ip;
    string port;
    //int status;
}worker;

typedef std::vector<worker> WorkerVec;

WorkerVec workervec;

/*string select(WorkerVec workervec)
{
    int num=workervec.size();
    for(int i=0;i<num-1;i++)
    {	
	
    }
}*/

void *con(void * conn)
{
    int *connfd;
    connfd=(int *)conn;
    Msg rec;
char buff[BUFFSIZE];
    string sendip;
    string sendport;
    int count=0;
    worker worker;
    extern WorkerVec workervec;
    while(1){
	if(read(*connfd,buff,sizeof(buff)) <= 0)
        {
            //cout<<"recv failed ..."<<endl;
            break;
        }
        //protobuf反序列化
        rec.ParseFromArray(buff,BUFFSIZE);
        if(rec.role()==1)//client's message
        {
 	    if(rec.msgcategory()==1)//client's inquire
	    {
		char sendbuff[BUFFSIZE];
		Msg sendmsg;
		if(workervec.size()==0)//no worker
		{
		    sendmsg.set_role(3);
		    sendmsg.set_msgcategory(5);
                    sendmsg.SerializeToArray(sendbuff,BUFFSIZE);
		    send(*connfd,sendbuff,BUFFSIZE,0);
		}
		else if(count<workervec.size())
		{
 		    sendip=workervec[count].ip;
		    sendport=workervec[count].port;
		    sendmsg.set_role(3);
		    sendmsg.set_msgcategory(2);
		    sendmsg.set_ip(sendip);
		    sendmsg.set_port(sendport);
                    cout<<"send "<<sendip<<":"<<sendport<<endl;
		    sendmsg.SerializeToArray(sendbuff,BUFFSIZE);
		    send(*connfd,sendbuff ,BUFFSIZE, 0);
                    count++;
		    if(count==workervec.size())
		    {
			count=0;
 		    }
		}
		else
		{
		    cout<<"error"<<endl;
		}
		
	   }
  	    
        }
        else if(rec.role()==2)      //worker's register
        {
	    //cout<<"recieve"<<endl;
 	    if(rec.msgcategory()==6)
	    {
		//cout<<"msgcategory=0"<<endl;
                //num++;
                worker.ip=rec.ip();
		worker.port=rec.port();
		worker.worker_id=workervec.size()+1;
		workervec.push_back(worker);
		cout<<"worker "<<workervec.size()<<" registered"<<endl;
		int a=workervec.size();
		//debug
		cout<<"we have "<<a<<" workers"<<endl;
                for(int i=0;i<a;i++)
		{
		    cout<<"port="<<workervec[i].port<<endl;
		}
            }
	} 
    }
    close(*connfd);

}

int main()
{
    int *connfd;
    
    
    struct sockaddr_in seraddr ;
    //建立socket
    //AF_INET:IPv4因特网域
    //SOCK_STREAM:TCP链接
    //0:给定前两个参数，选择默认的协议
    int serverSock = socket(AF_INET,SOCK_STREAM,0);
    if(serverSock < 0 )
    {
        cout<<"socket failed"<<endl;
    }
    //地址置空
    bzero(&seraddr,sizeof(seraddr));
    //
    seraddr.sin_family = AF_INET ;
    seraddr.sin_port = htons(9999);
    seraddr.sin_addr.s_addr = htonl(INADDR_ANY);
    //关联地址和套接字
    if(bind(serverSock,(struct sockaddr *)&seraddr, sizeof(seraddr)) < 0)
    {
        cout<<"bind address with socket failed..."<<endl;
        close(serverSock);
        return -1;
    }
    //调用listen，宣告server愿意接受链接请求
    if(listen(serverSock,QLEN) == -1)
    {
        cout<<"listen on socket failed..."<<endl;
        close(serverSock);
        return -1;
    }
    
    
    //WorkerVec workervec;
    
    pthread_t threads[10];
    int thread_counnt=0;
    
    while(1)
    {
        connfd=new int; 
	//获得连接请求，并建立连接
        if( (*connfd = accept(serverSock,(struct sockaddr *)NULL,NULL)) < 0 )
        {
            cout<<"accept the request failed"<<endl;
            close(serverSock);
            return -1;
        }
        if(pthread_create(&threads[thread_counnt++],NULL,con,(void *)connfd))
	{
	    cout << "Error:unable to create thread," <<endl;
            exit(-1);
	}
    }
    close(serverSock);
    close(*connfd);
    return 0;
}



