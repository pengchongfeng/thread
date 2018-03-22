#ifndef SERVICE_H
#define SERVICE_H

class Service
{
public:
    void Init();
    void BindListen();
    void Accept();
    void Send();
    void Recv();
    void Close();

private:
    int fd;
    int clientfd;
    bool noblock;
};
#endif // SERVICE_H
