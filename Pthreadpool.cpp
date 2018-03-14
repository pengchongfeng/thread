#include "Pthreadpool.h"
#include "Status.h"
#include "Eventloop.h"
#include <errno.h>
#include <unistd.h>

Pthreadpool *Pthreadpool::obj = NULL;


Pthreadpool::Pthreadpool()
{
    _maxnum = MAXPTHREAD;
}

void *callback(void *)
{
    status->lock();
    ++pthreadpool->_usable;
    status->unlock();

    while(true)
    {
        FUNC func = NULL;
        void *param = NULL;
        status->lock();
        eventloop->GetEvent(func, param);
        if(NULL == func)
        {
            if(ETIMEDOUT == status->timedwait())
            {
                printf("tid[] = %lu timedwait.\n", pthread_self());
                --pthreadpool->_maxnum;
                --pthreadpool->_usable;
                status->unlock();
                if(pthreadpool->_maxnum == 0)
                    pthreadpool->stop = true;
                break;
            }
        }
        else
        {
            --pthreadpool->_usable;
            ++pthreadpool->_using;
        }
        status->unlock();
        if(NULL != func)
        {
            func(param);
        }
    }
    pthread_detach(pthread_self());
    printf("tid[] = %lu detach and quit.\n", pthread_self());
    if(pthreadpool->stop)
    {
        printf("I'm %lu,the last pthread,then I will send a signal.\n", pthread_self());
        status->signal();
    }

    return NULL;
}


Pthreadpool::~Pthreadpool()
{
}

int Pthreadpool::init()
{
    _usable = 0;
    _using = 0;
    stop = true;
    return 0;
}

int Pthreadpool::addFunc(FUNC func, void *param)
{
    eventloop->AddEvent(func, param);
    return 0;
}

int Pthreadpool::run()
{
    stop = false;
    unsigned int i = 0;
    unsigned int num = _maxnum;
    for(;i < num; ++i)
    {
        int fail = pthread_create(&tid[i], NULL, callback, NULL);
        if(!fail)
        {
            printf("tid[%u] = %lu create successfully.\n", i, tid[i]);
        }
        else
        {
            printf("tid[%u]  create failed.\n", i);
        }
    }
    printf("_maxnum == %u\n", _maxnum);
    printf("i == %u\n", i);
    return 0;
}

bool Pthreadpool::destory()
{
    if(pthreadpool->stop = true) return false;
    status->lock();
    printf("wait pthread over.\n");
    status->wait();
    printf("pthread over!\n");
    status->unlock();

    if(NULL != status)
    {
        deletestatus;
    }

    return true;
}
