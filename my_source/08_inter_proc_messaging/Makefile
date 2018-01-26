all: mqueue_client mqueue_server

mqueue_client: mqueue_client.o
	gcc  mqueue_client.o -lrt -o mqueue_client
	rm mqueue_client.o

mqueue_client.o: mqueue_client.c Common.h
	gcc -c mqueue_client.c

mqueue_server: mqueue_server.o
	gcc  mqueue_server.o -lrt -o mqueue_server
	rm mqueue_server.o

mqueue_server.o: mqueue_server.c Common.h
	gcc -c mqueue_server.c

clean:
	rm -rf mqueue_client mqueue_server
