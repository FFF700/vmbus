#include "HLDevice.h"
#include "HLSerial.h"
#include "HLBus.h"
#include "HLUart.h"
#include "HLQueue.h"
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void serial1_rx(void*p,char *buf,int len)
{
    printf("callback in\n");
}

struct HLDevice duart1={"uart1",&uart1};
struct HLDevice duart2={"uart2",&uart2};
struct HLSerial serial1={.rxc={serial1_rx,&serial1}};
void serial_init()
{
    struct HLDevice*p=hl_devices_find("uart2");
    serial1.txq=((struct HLUart*)p->device)->rxq;
    hl_bus_add_listener(&p->rxc,&serial1.rxc);
}
void *sys_report()
{
    for(;;)
    {
        struct HLDevice*p=hl_devices_get_device();
        while (p)
        {
            struct HLMsg t;
            if(queue_peek(((struct HLUart*)p->device)->txq,&t)==TRUE)
            {
                queue_pop(((struct HLUart*)p->device)->txq,&t);
                printf("%s out\n",p->name);
                struct HLFunLink * fp=p->txc;
                while(fp)
                {
                    fp->callback(fp->caller,t.buf,t.len);
                    fp=fp->next;
                }
            }
            if(queue_peek(((struct HLUart*)p->device)->rxq,&t)==TRUE)
            {
                queue_pop(((struct HLUart*)p->device)->rxq,&t);
                printf("%s in\n",p->name);
                struct HLFunLink * fp=p->rxc;
                while(fp)
                {
                    fp->callback(fp->caller,t.buf,t.len);
                    fp=fp->next;
                }
            }
            p=p->next;
        }
        fflush(stdout);
        usleep(10000);
    }
}
void *setup()
{
    hl_uart_init();
    hl_devices_register(&duart1);
    hl_devices_register(&duart2);
    serial_init();
    hl_serial_send(&serial1,"hello bus",8);
    for(;;)
    {

        usleep(1000000);
    }
}
int main() {
    pthread_t tid1, tid2;
    pthread_create(&tid1, NULL, setup, NULL);
    pthread_create(&tid2, NULL, sys_report, NULL);
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
    return 0;
}
