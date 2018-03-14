#include "Status.h"
#include <sys/time.h>

#define TIMEWAIT 3

Status *Status::obj = NULL;

Status::Status()
{
    pthread_mutex_init(&_mutex, NULL);
    pthread_cond_init(&_cond, NULL);
}

 Status::~Status()
{
    pthread_mutex_destroy(&_mutex);
    pthread_cond_destroy(&_cond);
}

 void Status::lock()
{
    pthread_mutex_lock(&_mutex);
}

 void Status::unlock()
{
    pthread_mutex_unlock(&_mutex);
}

 void Status::signal()
{
    pthread_cond_signal(&_cond);
}

 void Status::wait()
{
    pthread_cond_wait(&_cond, &_mutex);
}

 int Status::timedwait()
{
    _timeout.tv_sec = _now.tv_sec + TIMEWAIT;
    _timeout.tv_nsec = _now.tv_usec;
    gettimeofday(&_now, NULL);
    int ret = pthread_cond_timedwait(&_cond, &_mutex, &_timeout);
    return ret;
}

 void Status::broadcast()
{
    pthread_cond_broadcast(&_cond);
}
