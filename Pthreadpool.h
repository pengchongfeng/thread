#ifndef PTHREADPOOL_H
#define PTHREADPOOL_H
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "Eventloop.h"

#define MAXPTHREAD 5

class Pthreadpool
{
    friend void *callback(void *);
public:
    ~Pthreadpool();

    static Pthreadpool *&construction()
    {
        if(NULL == obj)
        {
            obj = new Pthreadpool();
        }
        return obj;
    }

    int init();

    int addFunc(FUNC func, void *param);

    int run();

    bool destory();

    static Pthreadpool *obj;

private:
    explicit Pthreadpool();

    bool stop;
    unsigned int _maxnum;
    unsigned int _usable;
    unsigned int _using;
    pthread_t tid[MAXPTHREAD];
};

#define pthreadpool (Pthreadpool::obj->construction())

#endif // PTHREADPOOL_H
