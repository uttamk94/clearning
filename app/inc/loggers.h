#pragma once
#include <stdio.h>

#define LOG_LEVEL_DEBUG     (0)

#define LOG_LEVEL           LOG_LEVEL_DEBUG

#if LOG_LEVEL <= LOG_LEVEL_DEBUG
    #define log_d(fmt, ...) printf("[D]:%s:%s(%d): "fmt"\n", TAG, __func__, __LINE__, ##__VA_ARGS__)
    #define log_i(fmt, ...) printf("[I]:%s:%s(%d): "fmt"\n", TAG, __func__, __LINE__, ##__VA_ARGS__)
    #define log_w(fmt, ...) printf("[W]:%s:%s(%d): "fmt"\n", TAG, __func__, __LINE__, ##__VA_ARGS__)
    #define log_e(fmt, ...) printf("[E]:%s:%s(%d): "fmt"\n", TAG, __func__, __LINE__, ##__VA_ARGS__)
#elif
    #define log_d(fmt, ...) do {} while(0)
    #define log_i(fmt, ...) do {} while(0)
    #define log_w(fmt, ...) do {} while(0)
    #define log_e(fmt, ...) do {} while(0)
#endif

#if LOG_LEVEL <= LOG_LEVEL_DEBUG
    #define BEGIN() printf("[D]:%s:%s(%d): BEGIN\n", TAG, __func__, __LINE__)
    #define END() printf("[D]:%s:%s(%d): END\n", TAG, __func__, __LINE__)
#else
    #define BEGIN()  do {} while(0)
    #define END()  do {} while(0)
#endif