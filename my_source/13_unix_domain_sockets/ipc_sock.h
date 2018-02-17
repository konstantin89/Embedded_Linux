#include <sys/un.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdio.h>

#define SRV_SOCK_PATH "/tmp/ux_socket"

#define BUFFSIZE 1024

#define SRV_BACKLOG 100

#define err_sys(msg) do{printf("ERROR: %s", msg);}while(0) 
