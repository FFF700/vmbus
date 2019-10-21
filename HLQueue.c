//
// Created by winxo on 2019-10-21.
//

#include "HLQueue.h"
#include "string.h"
void queue_init(struct HLQueue *q,u32 length, u32 item_size, void* data)
{
    q->length = length;
    q->item_size = item_size;
    q->tail = 0;
    q->head = 0;
    q->count = 0;
    q->data = data;
}

static inline void *get_item_addr(const struct HLQueue *q, u32 index)
{
    return q->data + index * q->item_size;
}

void queue_clear(struct HLQueue *q)
{
    memset(q->data, 0, q->length * q->item_size);
    q->tail = 0;
    q->head = 0;
    q->count = 0;
}

bool queue_push(struct HLQueue *q, const void *item)
{
    memcpy(get_item_addr(q, q->tail), item, q->item_size);
    q->tail++;
    if (q->tail >= q->length)
    {
        q->tail = 0;
    }
    if (q->count == q->length)/*full*/
    {
        q->head = q->tail;
    }
    else
    {
        q->count++;
    }
    return TRUE;
}

bool queue_pop(struct HLQueue *q, void *item)
{
    if (q->count == 0)
    {
        return FALSE;
    }
    memcpy(item, get_item_addr(q, q->head), q->item_size);
    q->head++;
    if (q->head >= q->length)
    {
        q->head = 0;
    }
    q->count--;
    return TRUE;
}

bool queue_peek(const struct HLQueue *q, void *item)
{
    if (q->count == 0)
    {
        return FALSE;
    }
    memcpy(item, get_item_addr(q, q->head), q->item_size);
    return TRUE;
}
