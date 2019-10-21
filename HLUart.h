//
// Created by winxo on 2019-10-21.
//

#ifndef VMBUS_HLUART_H
#define VMBUS_HLUART_H
#include "typedef.h"
struct HLUart{
    struct HLQueue* rxq;
    struct HLQueue* txq;
};
void hl_uart_set_rx_callback(struct HLUart *huart,struct HLFunLink *f);
void hl_uart_init();

extern struct HLUart uart1;
extern struct HLUart uart2;
#endif //VMBUS_HLUART_H
