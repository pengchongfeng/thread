#include "Eventloop.h"
#include "Status.h"
#include <string.h>

Eventloop *Eventloop::obj = NULL;

Eventloop::Eventloop()
{
    _begin = _end = NULL;
    _eventnum = 0;
}

Eventloop::~Eventloop()
{
    Events *event;
    if(NULL != _begin)
    {
        event = _begin;
        _begin = _begin->next;
        delete event;
    }
    _eventnum = 0;
}

void Eventloop::AddEvent(FUNC func,void *param)
{
    if(NULL == func) return;

    Events *event = new Events();
    event->func = func;
    event->param = param;
    event->next = NULL;
    if(NULL == _begin)
    {
        _begin = event;
    }
    else
    {
        _end->next = event;
    }
    _end = event;
    ++_eventnum;
    printf("AddEvent : now _eventnum = %u\n",_eventnum);
}

void Eventloop::GetEvent(FUNC &func, void *&param)
{
    if(_begin == NULL) return;

    printf("get Event!\n");
    Events *event = _begin;
    if(_begin == NULL) printf("what?!\n");
    _begin = _begin->next;
    func = event->func;
    param = event->param;
    delete event;
    --_eventnum;
    printf("DeleteEvent : now _eventnum = %u\n",_eventnum);
}
