//
// Created by quals on 2019-11-08.
//
#include "error.h"
#include <stdio.h>
#include <stdlib.h>

void print_system_error_msg(int err_code, const char *format, va_list vaList) {
    char *msg1;
    vasprintf(&msg1, format, vaList);
    char *msg2;
    asprintf(&msg2, "\n=========================\nError code: %d\n%s\n=========================\n", err_code, msg1);
    perror(msg2);
}

void print_app_error_msg(const char *format, va_list vaList) {
    char *msg1;
    vasprintf(&msg1, format, vaList);
    char *msg2;
    asprintf(&msg2, "\n=========================\n%s\n=========================\n", msg1);
    printf("%s\n", msg1);
}

void system_error(const char *format, va_list vaList) {
    print_system_error_msg(errno, format, vaList);
    exit(-1);
}

void system_error(const char *format, ...) {
    va_list vaList;
    va_start(vaList, format);
    system_error(format, vaList);
    va_end(vaList);
}

void app_error(const char *format, va_list vaList) {
    print_app_error_msg(format, vaList);
}

void app_error(const char *format, ...) {
    va_list vaList;
    va_start(vaList, format);
    app_error(format, vaList);
    va_end(vaList);
}
