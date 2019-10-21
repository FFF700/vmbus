#include <stdio.h>
#include <stdint.h>
#include <string.h>

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
struct HLUart{
    struct HLQueue* rxq;
    struct HLQueue* txq;
    struct HLFunLink *rxc;
    struct HLFunLink *txc;
};
struct HLSerial{
    struct HLLink *rxc;
    struct HLLink *txc;
};
struct HLDevice *_devices;
struct HLDevice{
    char name[8];
    void *device;
    struct HLDevice *next;
};
struct HLDevice* hl_devices_find(char *name)
{
    struct HLDevice *p=_devices;
    while(p)
    {
        if(strcmp(p->name,name)==0)
        {
            return p;
        }
        p=p->next;
    }
    return NULL;
}
void hl_devices_register(struct HLDevice *d)
{
    if(_devices==NULL)
    {
        _devices=d;
        return;
    }
    struct HLDevice *p=_devices;
    while(p->next!=NULL)
    {
        p=p->next;
    }
    p->next=d;
}

void hl_queue_send(void* ss,uint8_t *buf,int len)
{
    memcpy(ss,buf,len);
}
void hl_uart_set_rx_callback(struct HLUart *huart,struct HLFunLink *f)
{
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
void hl_serial_send(struct HLSerial* s,uint8_t *buf,int len)
{
    struct HLLink *p=s->txc;
    while (p)
    {
        void *h=p->q;
        hl_queue_send(h,buf,len);
        p=p->next;
    }
}
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
