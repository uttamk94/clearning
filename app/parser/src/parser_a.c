#include "parser_a.h"

typedef enum {
   SPO2_STIME,
   SPO2_ETIME,
   SPO2_OFFSET,
   SPO2_SPO2
} spo2_key_t;

int parse_spo2(void *buf, unsigned short len, spo2_data_t *spo2) {
   unsigned char *data = (unsigned char *)buf;
   if (!data) return 0;
   unsigned short indx = 0;
   while (indx < len) {
      switch (data[indx++]) {
         case SPO2_STIME: {
            spo2->start_time = data[indx++];
            spo2->start_time |= data[indx++] << 8;
            spo2->start_time |= data[indx++] << 16;
            spo2->start_time |= data[indx++] << 24;
         } break;
         
         default:
            break;
      }
   }
   return indx;
}

int create_parser_a(parser_a_t *p) {
   int ret = create_parser(&p->base);
   p->spo2_parser = parse_spo2;
   return ret;
}