#pragma once

typedef void (*event_cb) (int status, int reason);
typedef struct {
    event_cb conn_cb;
    event_cb wom_cb;
    event_cb oobe_cb;
    event_cb batt_cb;
} twcc_t;

int reg_twcc(twcc_t *tc);
int unreg_twcc(twcc_t *tc);

int init_twc_handler();
int start_twcc_handler();