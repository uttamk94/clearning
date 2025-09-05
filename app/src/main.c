#include <stdio.h>
#include <stdlib.h>
#include "comm.h"
#include "parser_generator.h"
#include "loggers.h"

#define TAG     "MAIN"
void on_conn_cb(int status, int reason) {
    BEGIN();
    log_i("status: %d reason: %d", status, reason);
    END();
}

int main() {
    BEGIN();
    comm_t cm = NULL;
    int ret = new_comm(&cm);
    log_i("ret: %d", ret);
    ret = set_count(cm, 10);
    log_i("ret: %d %d", ret, get_count(cm));
    ret = set_conn_cb(cm, on_conn_cb);
    log_i("ret: %d", ret);

    parser_a_t *parser = generate_parser(PARSER_A);
    parser_t *base = (parser_t *) parser;
    ret = base->dev_inf_parser( NULL, 0, NULL);
    log_i("ret: %d", ret);
    END();
    return 0;
}