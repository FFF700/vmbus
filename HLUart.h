//
// Created by winxo on 2019-10-21.
//

#ifndef VMBUS_HLUART_H
#define VMBUS_HLUART_H
#include "typedef.h"
struct HLUart{
    struct HLQueue* rxq;
    struct HLQueue* txq;
    struct HLFunLink *rxc;
    struct HLFunLink *txc;
};
void hl_uart_set_rx_callback(struct HLUart *huart,struct HLFunLink *f);
#endif //VMBUS_HLUART_H
