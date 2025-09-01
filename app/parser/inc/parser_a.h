#pragma once
#include "parser.h"

typedef struct {
   int start_time;
   int end_time;
   int spo2;
   int time_offset;
} spo2_data_t;

typedef struct parser_a {
   parser_t base;
   int (*spo2_parser)(void *buf, unsigned short len, spo2_data_t *spo2);
} parser_a_t;

int create_parser_a(parser_a_t *p);