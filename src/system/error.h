//
// Created by quals on 2019-11-08.
//

#ifndef LARGETABLE_ERROR_H
#define LARGETABLE_ERROR_H

#include <errno.h>
#include <cstdarg>

void print_system_error_msg(int err_code, const char *format, va_list vaList);

void print_app_error_msg(const char *format, va_list vaList);

void system_error(const char *format, va_list vaList);

void system_error(const char *format, ...);

void app_error(const char *format, va_list vaList);

void app_error(const char *format, ...);
#endif //LARGETABLE_ERROR_H
