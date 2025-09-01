#include "parser.h"

typedef enum {
    MSG_ID          = 0,
    PARAM_NUMBER    = 1,
    SEQ_NUMBER      = 2,
} header_key_t;

typedef enum {
    DEV_LAST_TIME   = 0,
} dev_info_key_t;

typedef enum {
    WMSG_STATUS,
    WMSG_RESP,
} wmsg_key_t;

unsigned short parse_header(void *buf, unsigned short len, msg_header_t *header) {
    unsigned char *data = (unsigned char *) buf;
    unsigned short indx = 0;
    while (indx < len) {
        switch (data[indx++]) {
            case MSG_ID: {
                header->msg_id = data[indx++];
            } break;
            case PARAM_NUMBER:{
                header->num_param = data[indx++];
            } break;
            case SEQ_NUMBER: {
                header->seq_number = data[indx++];
                header->seq_number = (header->seq_number << 8) | data[indx++];
            } break;
            default:
                return indx;
                break; 
        }
    }
    return indx;
}

unsigned short parse_device_info(void *buf, unsigned short len, device_info_t *dev) {
    if (!buf) return 0;
    unsigned char *data = (unsigned char *) buf;
    unsigned short indx = 0;

    while (indx < len) {
        switch (data[indx++]) {
            case DEV_LAST_TIME: {
                dev->last_update_time = data[indx++];
                dev->last_update_time = (dev->last_update_time << 8) | data[indx++];
                dev->last_update_time = (dev->last_update_time << 16) | data[indx++];
                dev->last_update_time = (dev->last_update_time << 24) | data[indx++];
            } break;
            default:
                return indx;
                break; 
        }
    }
    return indx;
}

unsigned short parse_wmsg(void *buf, unsigned short len, wmsg_t *msg) {
    if (!buf) return 0;
    unsigned char *data = (unsigned char *) buf;
    unsigned short indx = 0;

    while (indx < len) {
        switch (data[indx++]) {
            case WMSG_STATUS: {
                msg->status = data[indx++];
            } break;
            case WMSG_RESP: {
                msg->resp = data[indx++];
            } break;
            default:
                return indx;
                break; 
        }
    }
    return indx;
}

int create_parser(parser_t *p) {
    p->header_parser = parse_header;
    p->dev_inf_parser = parse_device_info;
    p->wmsg_parser = parse_wmsg;
    return 0;
}