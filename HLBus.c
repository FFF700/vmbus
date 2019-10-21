//
// Created by winxo on 2019-10-21.
//

#include "HLBus.h"
#include <string.h>
void hl_bus_send(void *q, char *buf, int len) {
    memcpy(q,buf,len);
}
