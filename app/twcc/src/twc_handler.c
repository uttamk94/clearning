#include "twc_handler.h"
#include "loggers.h"

#define MX_ENTRY    10
#define NOTIFY(cb, status, reason) for (int i = 0; i < MX_ENTRY; i++) if (tables[i]->cb) tables[i]->cb(status, reason)

typedef enum {
    EVT_CON,
    EVT_WOM,
    EVT_OOBE,
    EVT_BAT,
    EVT_MAX
} evt_type_t;

twcc_t *tables[MX_ENTRY];

int reg_twcc(twcc_t *tc) {
    for (int i = 0; i < MX_ENTRY; i++) {
        if (!tables[i]) {
            tables[i] = tc;
            return 0;
        }
    }
    return -1;
}

int unreg_twcc(twcc_t *tc) {
    for (int i = 0; i < MX_ENTRY; i++) {
        if (tables[i] == tc) {
            tables[i]= 0; 
            return 0;
        }
    }
    return -1;
}

void notify_event(int event, int status, int reason) {
    switch (event) {
        case EVT_CON: {
            NOTIFY(conn_cb, status, reason);
        }
        break;
        case EVT_WOM:{
            NOTIFY(wom_cb, status, reason);
        } break;
        default:
        break;
    }
}

int init_twc_handler() {
    return 0;
}

int start_twcc_handler() {
    return 0;
}