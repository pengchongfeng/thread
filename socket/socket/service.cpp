#include "service.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <errno.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <fcntl.h>

void Service::Init()
{
    fd = socket(AF_INET, SOCK_STREAM, 0);
    if(-1 == fd)
    {
        perror("fd");
    }
}

void Service::BindListen()
{
    int flags = fcntl(fd, F_GETFL, 0);
    flags = flags & (~O_NONBLOCK);
    fcntl(fd,F_SETFL, flags);

    struct sockaddr_in addr;
//    memset(&addr, 0, sizeof(addr));
    bzero(&addr, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(8002);
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    printf("bind...\n");
    if(0 > bind(fd, (struct sockaddr *) &addr, sizeof(addr)))
    {
        perror("bind");
        exit(-1);
    }

    printf("listen...\n");
    listen(fd,1024);
}

void Service::Accept()
{
    struct sockaddr_in addr2;
    memset(&addr2, 0, sizeof(addr2));
//    bzero(&addr, sizeof(addr));
    socklen_t len = sizeof(struct sockaddr);

    printf("accept...\n");
    clientfd = accept(fd, (struct sockaddr *)&addr2, &len);
}

void Service::Send()
{
    printf("send...\n");
    send(clientfd, "hello client!", strlen("hello client!") + 1, 0);
    fflush(stdout);
}

void Service::Recv()
{
    char buf[1024] = {0};

    printf("recv...\n");
    recv(clientfd, buf, sizeof(buf), 0);
    printf("client:%s\n", buf);
}

void Service::Close()
{
    printf("close...\n");
    close(clientfd);

    close(fd);
}
