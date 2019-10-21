//
// Created by winxo on 2019-10-21.
//

#include "HLSerial.h"
#include "HLBus.h"
void hl_serial_send(struct HLSerial *s, uint8_t *buf, int len) {
    hl_bus_send(s->txq,buf,len);
}
