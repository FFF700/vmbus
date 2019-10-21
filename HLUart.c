//
// Created by winxo on 2019-10-21.
//

#include "HLUart.h"
#include "HLQueue.h"

#define QSZ 3
struct HLMsg uart1_rx_buf[QSZ];
struct HLMsg uart1_tx_buf[QSZ];
struct HLMsg uart2_rx_buf[QSZ];
struct HLMsg uart2_tx_buf[QSZ];
struct HLQueue uart1_rx,uart1_tx,uart2_rx,uart2_tx;
struct HLUart uart1={&uart1_rx,&uart1_tx},uart2={&uart2_rx,&uart2_tx};
void hl_uart_init()
{
    queue_init(&uart1_rx,QSZ, sizeof(struct HLMsg),&uart1_rx_buf);
    queue_init(&uart1_tx,QSZ, sizeof(struct HLMsg),&uart1_tx_buf);
    queue_init(&uart2_rx,QSZ, sizeof(struct HLMsg),&uart2_rx_buf);
    queue_init(&uart2_tx,QSZ, sizeof(struct HLMsg),&uart2_tx_buf);
}
