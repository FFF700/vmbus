//
// Created by winxo on 2019-10-21.
//

#ifndef VMBUS_HLQUEUE_H
#define VMBUS_HLQUEUE_H

#include "typedef.h"
struct HLQueue{
    u32 head;
    u32 tail;
    u32 length;
    u32 item_size;
    u32 count;
    u8 *data; //storage
};
void queue_init( struct HLQueue *q, u32 length, u32 item_size,void* data);
void queue_clear(struct HLQueue *q);
bool queue_push(struct HLQueue *q, const void *item);
bool queue_pop(struct HLQueue *q, void *item);
bool queue_peek(const struct HLQueue *q, void *item);
#endif //VMBUS_HLQUEUE_H
