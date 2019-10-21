//
// Created by winxo on 2019-10-21.
//

#ifndef VMBUS_HLDEVICE_H
#define VMBUS_HLDEVICE_H
struct HLDevice{
    char name[8];
    void *device;
    struct HLDevice *next;
};
struct HLDevice* hl_devices_find(char *name);
void hl_devices_register(struct HLDevice *d);

void test();
#endif //VMBUS_HLDEVICE_H
