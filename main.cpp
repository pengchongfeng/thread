#include <iostream>
#include "Eventloop.h"
#include "Pthreadpool.h"
#include <unistd.h>

using namespace std;

void *test1(void *ptr)
{
    cout << "test:" << pthread_self() << " get ptr[10] and sleep 2s!" << endl;
    int *arr = static_cast<int *>(ptr);
    for(int i = 0; i < 10; ++i)
    {
        cout << arr[i] << "\t";
    }
    cout << endl;
    sleep(2);
}

void *test2(void *ptr)
{
    cout << "good good study day day up!" << endl;
    cout << endl;
}

int main(int /*argc*/, char */*argv*/[])
{
    printf("begin init!\n");
    pthreadpool->init();
    printf("end init!\n");
    int ptr[10] = {1,3,5,7};
    sleep(1);
    printf("begin add!\n");
    pthreadpool->addFunc(test1, &ptr);
    pthreadpool->addFunc(test2, NULL);
    printf("end add!\n");
    sleep(1);
    printf("begin run!\n");
    pthreadpool->run();
    printf("end run!\n");
    sleep(1);
    printf("begin destory!\n");
    pthreadpool->destory();
    printf("end destory!\n");
    cout << "Hello World!" << endl;
    return 0;
}
