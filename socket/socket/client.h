#ifndef CLIENT_H
#define CLIENT_H

class Client
{
public:
    void Init();
    void Connect();
    void Send();
    void Recv();
    void Close();

private:
    int fd;
    bool noblock;
};

#endif // CLIENT_H
