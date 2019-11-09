//
// Created by quals on 2019-11-08.
//

#ifndef LARGETABLE_FILE_H
#define LARGETABLE_FILE_H

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "error.h"
#include <sys/stat.h>

FILE *Fopen(const char *path, const char *mode);

int Open(const char *path, int oflag);

ssize_t PRead(int fd, void *buf, size_t nbytes, int offset = 0);

int Fstat(int fd, struct stat* buf);

int FileSize(int fd);



ssize_t PWrite(int fd, const void *buf, size_t nbytes, int offset);

#endif //LARGETABLE_FILE_H
