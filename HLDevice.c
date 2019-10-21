//
// Created by winxo on 2019-10-21.
//

#include "HLDevice.h"
#include <string.h>
struct HLDevice *_devices;
struct HLDevice * hl_devices_get_device()
{
    return _devices;
}

void hl_devices_register(struct HLDevice *d) {
    if(_devices==NULL)
    {
        _devices=d;
        return;
    }
    struct HLDevice *p=_devices;
    while(p->next!=NULL)
    {
        p=p->next;
    }
    p->next=d;
}

struct HLDevice *hl_devices_find(char *name) {
    struct HLDevice *p=_devices;
    while(p)
    {
        if(strcmp(p->name,name)==0)
        {
            return p;
        }
        p=p->next;
    }
    return NULL;
}
