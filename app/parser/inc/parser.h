#pragma once

typedef enum {
    PARSER_A,
    PARSER_B,
    PARSER_C,
    INVLIAD
} parser_type_t;

typedef struct {
    unsigned char msg_id;
    unsigned char num_param;
    unsigned short seq_number;
} msg_header_t;

typedef struct {
    unsigned int last_update_time;
} device_info_t;

typedef struct {
    unsigned char status;
    unsigned char resp;
} wmsg_t;

typedef struct parser {
    unsigned short (*header_parser)(void *buf, unsigned short len, msg_header_t *header);
    unsigned short (*dev_inf_parser)(void *buf, unsigned short len, device_info_t *dev);
    unsigned short (*wmsg_parser)(void *buf, unsigned short len, wmsg_t *msg);
} parser_t;

int create_parser(parser_t *p);