#pragma once

typedef void (*event_cb) (int status, int reason);
typedef struct comm * comm_t;

int new_comm(comm_t *cm);
int set_count(comm_t cm, int cnt);
int get_count(comm_t cm);
int set_conn_cb(comm_t cm, event_cb cb);
