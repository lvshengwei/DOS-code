#include <iostream>
#include <string>
#include <ctime>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <pthread.h>
#include <signal.h>
#include "Message.pb.h"

using namespace std;
using namespace Message::protobuf;

const int BUFFSIZE = 1024;
const int QLEN = 10;
const string WORKER_IP = "127.0.0.1";
const string MASTER_IP = "127.0.0.1";
const int MASTER_PORT = 9999;
const int WORKER_NUM = 3;

void *task(void *fdptr){
	//detach the thread
	pthread_detach(pthread_self());

	int connfd = *(int *)fdptr;
	Msg recmsg, sendmsg;
	char recbuf[BUFFSIZE], sendbuf[BUFFSIZE];
	//receive message
	if (recv(connfd,recbuf,sizeof(recbuf),0) < 0){
		cout << "recv failed" << endl;
		close(connfd);
		pthread_exit(NULL);
	}
	recmsg.ParseFromArray(recbuf,BUFFSIZE);
	//do the task
	if (recmsg.role() == 1 && recmsg.msgcategory() == 3){
		cout << "receive from client" << endl;
		string opr = recmsg.operation();
		cout << "operation: " << opr << endl;
		if (opr == "int32+"){
			//cout << "receive int32+" << endl;
			int result = recmsg.int32op1() + recmsg.int32op2();
			//send result
			sendmsg.set_role(2);
			sendmsg.set_msgcategory(4);
			sendmsg.set_int32result(result);
			sendmsg.SerializeToArray(sendbuf,BUFFSIZE);
			if (send(connfd,sendbuf,strlen(sendbuf),0) < 0){
				cout << "send failed" << endl;
				close(connfd);
				pthread_exit(NULL);
			}
		}
		else if (opr == "int32-"){
			int result = recmsg.int32op1() - recmsg.int32op2();
			//send result
			sendmsg.set_role(2);
			sendmsg.set_msgcategory(4);
			sendmsg.set_int32result(result);
			sendmsg.SerializeToArray(sendbuf,BUFFSIZE);
			if (send(connfd,sendbuf,strlen(sendbuf),0) < 0){
				cout << "send failed" << endl;
				close(connfd);
				pthread_exit(NULL);
			}
		}
		else if (opr == "int32*"){
			int result = recmsg.int32op1() * recmsg.int32op2();
			//send result
			sendmsg.set_role(2);
			sendmsg.set_msgcategory(4);
			sendmsg.set_int32result(result);
			sendmsg.SerializeToArray(sendbuf,BUFFSIZE);
			if (send(connfd,sendbuf,strlen(sendbuf),0) < 0){
				cout << "send failed" << endl;
				close(connfd);
				pthread_exit(NULL);
			}
		}
		else if (opr == "int32/"){
			int result = recmsg.int32op1() / recmsg.int32op2();
			//send result
			sendmsg.set_role(2);
			sendmsg.set_msgcategory(4);
			sendmsg.set_int32result(result);
			sendmsg.SerializeToArray(sendbuf,BUFFSIZE);
			if (send(connfd,sendbuf,strlen(sendbuf),0) < 0){
				cout << "send failed" << endl;
				close(connfd);
				pthread_exit(NULL);
			}
		}
		else if (opr == "int64+"){
			long long result = recmsg.int64op1() + recmsg.int64op2();
			//send result
			sendmsg.set_role(2);
			sendmsg.set_msgcategory(4);
			sendmsg.set_int64result(result);
			sendmsg.SerializeToArray(sendbuf,BUFFSIZE);
			if (send(connfd,sendbuf,strlen(sendbuf),0) < 0){
				cout << "send failed" << endl;
				close(connfd);
				pthread_exit(NULL);
			}
		}
		else if (opr == "int64-"){
			long long result = recmsg.int64op1() - recmsg.int64op2();
			//send result
			sendmsg.set_role(2);
			sendmsg.set_msgcategory(4);
			sendmsg.set_int64result(result);
			sendmsg.SerializeToArray(sendbuf,BUFFSIZE);
			if (send(connfd,sendbuf,strlen(sendbuf),0) < 0){
				cout << "send failed" << endl;
				close(connfd);
				pthread_exit(NULL);
			}
		}
		else if (opr == "int64*"){
			long long result = recmsg.int64op1() * recmsg.int64op2();
			//send result
			sendmsg.set_role(2);
			sendmsg.set_msgcategory(4);
			sendmsg.set_int64result(result);
			sendmsg.SerializeToArray(sendbuf,BUFFSIZE);
			if (send(connfd,sendbuf,strlen(sendbuf),0) < 0){
				cout << "send failed" << endl;
				close(connfd);
				pthread_exit(NULL);
			}
		}
		else if (opr == "int64/"){
			long long result = recmsg.int64op1() / recmsg.int64op2();
			//send result
			sendmsg.set_role(2);
			sendmsg.set_msgcategory(4);
			sendmsg.set_int64result(result);
			sendmsg.SerializeToArray(sendbuf,BUFFSIZE);
			if (send(connfd,sendbuf,strlen(sendbuf),0) < 0){
				cout << "send failed" << endl;
				close(connfd);
				pthread_exit(NULL);
			}
		}
		else if (opr == "db+"){
			double result = recmsg.dbop1() + recmsg.dbop2();
			//double dif = result - int(result);
			//if (abs(dif) < 0.01)
			//	result += 0.01;
			//cout << result << endl;
			//send result
			sendmsg.set_role(2);
			sendmsg.set_msgcategory(4);
			sendmsg.set_dbresult(result);
			sendmsg.SerializeToArray(sendbuf,BUFFSIZE);
			if (send(connfd,sendbuf,strlen(sendbuf),0) < 0){
				cout << "send failed" << endl;
				close(connfd);
				pthread_exit(NULL);
			}
		}
		else if (opr == "db-"){
			double result = recmsg.dbop1() - recmsg.dbop2();
			//double dif = result - int(result);
			//if (abs(dif) < 0.01)
			//	result += 0.01;
			//cout << result << endl;
			//send result
			sendmsg.set_role(2);
			sendmsg.set_msgcategory(4);
			sendmsg.set_dbresult(result);
			sendmsg.SerializeToArray(sendbuf,BUFFSIZE);
			if (send(connfd,sendbuf,strlen(sendbuf),0) < 0){
				cout << "send failed" << endl;
				close(connfd);
				pthread_exit(NULL);
			}
		}
		else if (opr == "db*"){
			double result = recmsg.dbop1() * recmsg.dbop2();
			//double dif = result - int(result);
			//if (abs(dif) < 0.01)
			//	result += 0.01;
			//cout << result << endl;
			//send result
			sendmsg.set_role(2);
			sendmsg.set_msgcategory(4);
			sendmsg.set_dbresult(result);
			sendmsg.SerializeToArray(sendbuf,BUFFSIZE);
			if (send(connfd,sendbuf,strlen(sendbuf),0) < 0){
				cout << "send failed" << endl;
				close(connfd);
				pthread_exit(NULL);
			}
		}
		else if (opr == "db/"){
			double result = recmsg.dbop1() / recmsg.dbop2();
			//double dif = result - int(result);
			//if (abs(dif) < 0.01)
			//	result += 0.01;
			//cout << result << endl;
			//send result
			sendmsg.set_role(2);
			sendmsg.set_msgcategory(4);
			sendmsg.set_dbresult(result);
			sendmsg.SerializeToArray(sendbuf,BUFFSIZE);
			if (send(connfd,sendbuf,strlen(sendbuf),0) < 0){
				cout << "send failed" << endl;
				close(connfd);
				pthread_exit(NULL);
			}
		}
	}
	else{
		cout << "message error" << endl;
		close(connfd);
		pthread_exit(NULL);
	}
	close(connfd);
	delete (int *)fdptr;
}



void *worker(void *lsport){
	string listenPort = *(string *)lsport;
	//register
	int regfd;
	struct sockaddr_in mastaddr;
	//create socket
	regfd = socket(AF_INET,SOCK_STREAM,0);
	bzero(&mastaddr,sizeof(mastaddr));
	mastaddr.sin_family = AF_INET;
	mastaddr.sin_port = htons(MASTER_PORT);
	mastaddr.sin_addr.s_addr = inet_addr(MASTER_IP.c_str());
	//connect master
	while (connect(regfd,(struct sockaddr *)&mastaddr,sizeof(mastaddr)) < 0);
	//create message
	Msg regmsg;
	regmsg.set_role(2);
	regmsg.set_msgcategory(6);
	regmsg.set_ip(WORKER_IP);
	regmsg.set_port(listenPort);
	char buf[BUFFSIZE];
	regmsg.SerializeToArray(buf,BUFFSIZE);
	//send message
	while(1){
		if (send(regfd,buf,strlen(buf),0) > 0){
			cout << "send register message success" << endl;
			break;
		}
	}
	close(regfd);
	
	//wait for messages
	int listenfd;
	int *connfd;
	pthread_t conntid[10];//allow 10 concurrent tasks
	struct sockaddr_in workaddr;
	//create socket
	listenfd = socket(AF_INET,SOCK_STREAM,0);
	bzero(&workaddr,sizeof(workaddr));
	workaddr.sin_family = AF_INET;
	workaddr.sin_port = htons(atoi(listenPort.c_str()));
	workaddr.sin_addr.s_addr = inet_addr(WORKER_IP.c_str());
	//bind socket and address
	if (bind(listenfd,(struct sockaddr *)&workaddr,sizeof(workaddr)) < 0){
		cout << "bind address with socket failed" <<endl;
		close(listenfd);
		pthread_exit(NULL);
	}
	//listen
	if (listen(listenfd,QLEN) < 0){
		cout << "listen on socket failed" << endl;
		close(listenfd);
		pthread_exit(NULL);
	}
	int i = 0;
	int flag = 0;
	while(1){
		//wait connection
		connfd = new int;
		if ((*connfd = accept(listenfd,(struct sockaddr *)NULL,NULL)) < 0){
			delete connfd;
			continue;
		}
		//wait for previous tasks
		if (flag)
			while (pthread_kill(conntid[i],0) == 0);
		//create new task
		if (pthread_create(&conntid[i],NULL,task,(void *)connfd) != 0){
			cout << "create thread failed" << endl;
			close(*connfd);
			close(listenfd);
			pthread_exit(NULL);
		}
		i = i + 1;
		if (i == 10){
			i = 0;
			flag = 1;
		}
	}
	delete (string *)lsport;
}

int main(){
	pthread_t wtid[WORKER_NUM];
	string *lsport;
	//create workers
	for (int i = 0; i < WORKER_NUM; i++){
		lsport = new string(to_string(i+10000));
		if (pthread_create(&wtid[i],NULL,worker,(void *)lsport) != 0){
			cout << "create worker " << i << " failed" <<endl;
			return -1;
		}
	}

	for (int i = 0; i < WORKER_NUM; i++){
		pthread_join(wtid[i],NULL);
	}

	return 0;
}
