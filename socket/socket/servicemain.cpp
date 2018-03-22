#include "service.h"

int main(void)
{
    ServiceAccept service;
    service.Init();
    service.BindListen();
    service.Accept();
    service.Recv();
    service.Send();
    service.Close();

    return 0;
}
