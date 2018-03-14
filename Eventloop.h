#ifndef EVENTLOOP_H
#define EVENTLOOP_H
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef void *(*FUNC)(void *);
typedef struct Events
{
    FUNC func;
    void *param;
    Events *next;
}Events;

class Eventloop
{
public:
    static Eventloop *&construction()
    {
        if(NULL == obj)
        {
            obj = new Eventloop();
        }
        return obj;
    }

    ~Eventloop();

    void AddEvent(FUNC func, void *param);

    void GetEvent(FUNC &func, void *&param);

    static Eventloop *obj;

private:
    Eventloop();

    unsigned int _eventnum;
    Events *_begin;
    Events *_end;
};
#define eventloop (Eventloop::obj->construction())
#endif // EVENTLOOP_H
