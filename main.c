#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "HLDevice.h"
#include "HLSerial.h"
#include "HLUart.h"

struct HLQueue uart1_rx={"rx1"},uart1_tx={"tx1"},uart2_rx={"rx2"},uart2_tx={"tx2"};
struct HLUart uart1={&uart1_rx,&uart1_tx},uart2={&uart2_rx,&uart2_tx};
struct HLDevice duart1={"uart1",&uart1};
struct HLDevice duart2={"uart2",&uart2};
struct HLSerial serial1;
struct HLLink link,link2;

void serial_init()
{
    struct HLDevice*p=hl_devices_find("uart2");
    link.q=((struct HLUart*)p->device)->rxq; /*bind pipe dynamic*/
    link2.q=((struct HLUart*)p->device)->txq; /*bind pipe dynamic*/
    link.next=&link2;
    serial1.txc=&link;

}
int main() {
    hl_devices_register(&duart1);
    hl_devices_register(&duart2);
    serial_init();
    hl_serial_send(&serial1,"hello bus",8);
    return 0;
}
