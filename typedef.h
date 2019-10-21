//
// Created by winxo on 2019-10-21.
//

#ifndef VMBUS_TYPEDEF_H
#define VMBUS_TYPEDEF_H
#include <stdint.h>
typedef  uint32_t u32;
typedef  uint8_t u8;
typedef  uint8_t bool;
typedef void (*pFunUart)(void*,char*,int);

#define TRUE (1)
#define FALSE (0)

struct HLFunLink{
    pFunUart callback;
    void* caller;
    struct HLFunLink *next;
};
struct HLMsg{
    char buf[80];
    u8 len;
};
#endif //VMBUS_TYPEDEF_H
