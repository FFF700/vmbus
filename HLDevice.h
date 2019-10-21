//
// Created by winxo on 2019-10-21.
//

#ifndef VMBUS_HLDEVICE_H
#define VMBUS_HLDEVICE_H
struct HLDevice{
    char name[8];
    void *device;
    struct HLFunLink *rxc;
    struct HLFunLink *txc;
    struct HLDevice *next;
};
struct HLDevice * hl_devices_get_device();
struct HLDevice* hl_devices_find(char *name);
void hl_devices_register(struct HLDevice *d);

void test();
#endif //VMBUS_HLDEVICE_H
