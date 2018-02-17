/**
* Unix domain sockets are inter process communication tool.
*
* Unix named pipes provide uni-derectional communication, while
* sockets provide bi-directional communication between processes.
*/

#include "ipc_sock.h"

void run_server()
{
    struct sockaddr_un  addr;
    int srv_fd , cli_fd, ret_val;
    ssize_t bytes;
    char buf[BUFFSIZE];

    srv_fd = socket(AF_UNIX, SOCK_STREAM, 0);
    if(srv_fd < 0)
    {
        err_sys(" socket error");
    }

    memset(&addr, 0, sizeof(struct sockaddr_un));

    //AF_UNIX - socket that used for local IPC.
    addr.sun_family = AF_UNIX ;

    //Socket is represented by SRV_SOCK_PATH local file.
    strncpy(addr.sun_path,
            SRV_SOCK_PATH,
            sizeof(addr.sun_path)-1);

    //Ensure that process has access permissions to socket.
    if(access (addr.sun_path, F_OK) == 0)
    {
        unlink(addr.sun_path);
    }

    if(bind(srv_fd ,(struct sockaddr*)&addr,
       sizeof(struct sockaddr_un)) < 0)
    {
       err_sys("bind error");
    }

    if(listen(srv_fd, SRV_BACKLOG ) < 0)
        err_sys("listen error");

    while(1)
    {
        if((cli_fd=accept(srv_fd, NULL, NULL)) < 0)
            err_sys("accept error");

        while((bytes=read(cli_fd, buf, BUFFSIZE)) > 0)
            if(write(STDOUT_FILENO, buf, bytes) != bytes)
                err_sys("write error");

        if(bytes < 0)
            err_sys("read error");

        if(close(cli_fd) < 0)
            err_sys("close error");
    }
}

int main()
{
    run_server();
    return 0;
}


/******************************* End Of File ******************************/
