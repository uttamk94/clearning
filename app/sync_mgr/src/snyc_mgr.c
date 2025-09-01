#include "sync_mgr.h"
#include "sync_mgr_a.h"

void on_data_received(void *buf, unsigned short len) {
    unsigned char *data = buf;
    if (!data) return;
    switch (data[0]) {
        case 0: {
            handle_sync_a(data+1, len -1);
        } break;
        default:
            break;
    }
    
}