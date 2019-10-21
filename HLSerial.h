//
// Created by winxo on 2019-10-21.
//

#ifndef VMBUS_HLSERIAL_H
#define VMBUS_HLSERIAL_H
#include "typedef.h"
struct HLSerial{
    struct HLQueue *txq;
    struct HLFunLink rxc;
};
void hl_serial_send(struct HLSerial* s,uint8_t *buf,int len);
#endif //VMBUS_HLSERIAL_H
