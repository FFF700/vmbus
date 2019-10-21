//
// Created by winxo on 2019-10-21.
//

#include "HLUart.h"

void hl_uart_set_rx_callback(struct HLUart *huart, struct HLFunLink *f) {
    if(huart->rxc)
    {
        huart->rxc=f;
        return;
    }
    struct HLFunLink *p=huart->rxc;
    while(p->next)
    {
        p=p->next;
    }
    p->next=f;
}
