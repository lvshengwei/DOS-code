CC = g++ #-g -D__LINUX__ -Wall -fPIC
LIB = -lpthread -lprotobuf

all:prepare worker master client

prepare:
	protoc -I=./ --cpp_out=./ Message.proto

.cc.o:
	$(CC) -c $< -o $@

worker:worker.cc Message.pb.cc Message.pb.h
	$(CC) -o $@ $^ $(LIB)

master:master.cc Message.pb.cc Message.pb.h
	$(CC) -o $@ $^ $(LIB)

client:client.cc Message.pb.cc Message.pb.h
	$(CC) -o $@ $^ $(LIB)

clean:
	rm -f *.o
	rm -f Message.pb.*
	rm -f worker
	rm -f master
	rm -f client
