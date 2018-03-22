#ifndef SERVICE_H
#define SERVICE_H

class Service
{
public:
    virtual void Init() = 0;
    virtual void BindListen() = 0;
    virtual void Accept() = 0;
    virtual void Send() = 0;
    virtual void Recv() = 0;
    virtual void Close() = 0;

    virtual void Setsocketopt(){}

private:
    int fd;
    int clientfd;
    bool noblock;
};

class ServiceAccept:public Service
{
public:
    virtual void Init();
    virtual void BindListen();
    virtual void Accept();
    virtual void Send();
    virtual void Recv();
    virtual void Close();

private:
    int fd;
    int clientfd;
    bool noblock;
};


class ServiceSelect:public Service
{
    virtual void Accept();
};

class ServiceEpoll:public Service
{
    virtual void Accept();
};


#endif // SERVICE_H
