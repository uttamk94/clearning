#include "sync_mgr_a.h"
#include "parser_generator.h"

typedef enum {
    HEADER,
    DEVICE_INFO,
    TRACKER,
} param_key_t;

void handle_sync_a(void *buf, unsigned short len) {
    if (!buf) return;
    unsigned char *data = (unsigned char *) buf;
    parser_a_t *parser = generate_parser(0);
    unsigned short indx = 0;
    while (len > indx) {
        switch (data[indx++]) {
            case HEADER: {
                msg_header_t header = {0, };
                indx += parser->base.header_parser(data + indx, sizeof(msg_header_t), &header);
            } break;
            case DEVICE_INFO: {
                device_info_t dev_info = {0, };
                indx += parser->base.dev_inf_parser(data+indx, sizeof(device_info_t), &dev_info);
            } break;
            case TRACKER: {
                spo2_data_t spo2 = {0, };
                indx += parser->spo2_parser(data + indx, sizeof(spo2_data_t), &spo2);
            } break;
            default: {
                return;
            } break;
        }
    }    
}