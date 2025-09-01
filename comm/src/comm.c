#include "comm.h"
#include "string.h"
#include "stdlib.h"
#include "stddef.h"
#include "stdbool.h"

#define container_of(ptr, type, member) ({                      \
    const typeof(((type *)0)->member) *__mptr = (ptr);          \
    (type *)((char *)__mptr - offsetof(type, member)); })

struct comm {
    int count;
    event_cb conn_cb;
    event_cb wear_cb;
    event_cb psm_cb;
    event_cb oobe_cb;
    event_cb batt_cb;
    event_cb crdle_cb;
};

int new_comm(comm_t *cm) {
    *cm = (comm_t *) malloc(sizeof(comm_t));
    memset(*cm, 0x00, sizeof(comm_t));
    if (*cm) return 0;
    return -1;
}

int set_count(comm_t cm, int cnt) {
    cm->count = cnt;
    return cm->count;
}

int get_count(comm_t cm) {
    return ++cm->count;
}

int set_conn_cb(comm_t cm, event_cb cb) {
    cm->conn_cb = cb;
    return 0;
}
