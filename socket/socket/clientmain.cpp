#include "client.h"

int main(void)
{
    Client client;
    client.Init();
    client.Connect();
    client.Send();
    client.Recv();
    client.Close();

    return 0;
}
