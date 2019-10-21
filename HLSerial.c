//
// Created by winxo on 2019-10-21.
//

#include "HLSerial.h"
#include "HLBus.h"
void hl_serial_send(struct HLSerial *s, uint8_t *buf, int len) {
    struct HLLink *p=s->txc;
    while (p)
    {
        hl_bus_send(p->q,buf,len);
        p=p->next;
    }
}
