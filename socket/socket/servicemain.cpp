#include "service.h"

int main(void)
{
    Service service;
    service.Init();
    service.BindListen();
    service.Accept();
    service.Recv();
    service.Send();
    service.Close();

    return 0;
}
