#include "parser_generator.h"

parser_a_t parser_a;
void *generate_parser(int type) {
    void *prsr = 0;
    if (type == PARSER_A) {
        create_parser_a(&parser_a);
        prsr = &parser_a;
        }
    return &prsr;
}