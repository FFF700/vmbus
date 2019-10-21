//
// Created by winxo on 2019-10-21.
//

#include "HLBus.h"
#include <string.h>
#include "HLQueue.h"
void hl_bus_send(struct HLQueue *q, char *buf, int len) {
    struct HLMsg t={.len=len};
    memcpy(t.buf,buf,len);
    queue_push(q,&t);
}

void hl_bus_add_listener(struct HLFunLink **funs, struct HLFunLink *f) {
    if(*funs==NULL)
    {
        *funs=f;
        return;
    }
    struct HLFunLink *p=*funs;
    while(p->next)
    {
        p=p->next;
    }
    p->next=f;
}
