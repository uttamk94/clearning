#include <stdio.h>
#include <stdlib.h>
#include "comm.h"
#include "parser_generator.h"

void on_conn_cb(int status, int reason) {
    printf("status: %d reason: %d\n", status, reason);
}

int main() {
    comm_t cm = NULL;
    int ret = new_comm(&cm);
    printf("%s: ret: %d\n", __func__, ret);
    ret = set_count(cm, 10);
    printf("%s: ret: %d %d\n", __func__, ret, get_count(cm));
    ret = set_conn_cb(cm, on_conn_cb);
    printf("%s: ret %d\n", __func__, ret);

    parser_a_t *parser = generate_parser(PARSER_A);
    ret = parser->base.dev_inf_parser( NULL, 0, NULL);   
    printf("%s: ret: %d\n", __func__, ret);
    return 0;
}