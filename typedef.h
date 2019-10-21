//
// Created by winxo on 2019-10-21.
//

#ifndef VMBUS_TYPEDEF_H
#define VMBUS_TYPEDEF_H
#include <stdint.h>
typedef void (*pFunUart)(void*,char*,int);

struct HLQueue{
    char buf[80];
};
struct HLLink{
    struct HLQueue* q;
    struct HLLink *next;
};
struct HLFunLink{
    pFunUart q;
    struct HLFunLink *next;
};
#endif //VMBUS_TYPEDEF_H
