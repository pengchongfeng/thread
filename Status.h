#ifndef STATUS_H
#define STATUS_H

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

class Status
{
public:

    static Status *&construction()
    {
        if(NULL == obj)
        {
            obj = new Status();
        }
        return obj;
    }

    virtual ~Status();

    virtual void lock();

    virtual void unlock();

    virtual void signal();

    virtual void wait();

    virtual int timedwait();

    virtual void broadcast();

public:
    static Status *obj;

private:
    Status();
    struct timeval _now;
    struct timespec _timeout;
    pthread_mutex_t _mutex;
    pthread_cond_t _cond;
};
#define status (Status::obj->construction())
#define deletestatus (delete Status::obj)

#endif // STATUS_H
