//
// Created by winxo on 2019-10-21.
//

#ifndef VMBUS_HLBUS_H
#define VMBUS_HLBUS_H
#include "typedef.h"
#include "HLQueue.h"
void hl_bus_send(struct HLQueue * q,char*buf,int len);
void hl_bus_add_listener(struct HLFunLink ** funs,struct HLFunLink * f);
#endif //VMBUS_HLBUS_H
