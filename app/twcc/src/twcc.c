#include "twcc.h"
#include "twcc_wom_handler.h"
#include "twcc_oobe_handler.h"
#include "loggers.h"

#define TAG "TWCC"

int init_twcc() {
    BEGIN();
    init_twc_handler();
    init_twcc_wom();
    END();
    return 0;
}

int start_twcc() {
    BEGIN();
    start_twcc_handler();
    start_twcc_wom();
    END();
    return 0;
}