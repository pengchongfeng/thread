#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
    int fd = socket(AF_INET, SOCK_STREAM, 0);

//    int flags = fcntl(fd, F_GETFL, 0);
//    flags |= O_NONBLOCK;
//    fcntl(fd, F_SETFL, flags);

    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(8002);
    addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    printf("connect...\n");
    if(-1 == connect(fd, (struct sockaddr *)&addr, sizeof(struct sockaddr)))
    {
        perror("fd");
        exit(0);
    }
    char buf[1024] = {0};

    printf("recv:\n");
    int len = recv(fd, buf, sizeof(buf), 0);
    fflush(stdout);
    buf[len] = '\0';
    printf("service:%s",buf);

    char *arr = "hi service!";
    printf("send...\n");
    send(fd, arr,strlen(arr) + 1, 0);

    printf("close...\n");
    close(fd);
}