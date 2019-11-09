//
// Created by quals on 2019-11-08.
//
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "error.h"
#include <sys/stat.h>

FILE *Fopen(const char *path, const char *mode) {
    FILE *fp = fopen(path, mode);
    if (fp == NULL) {
        //TODO log
        system_error("Open file(%s) failed: ", path);
    }
    return fp;
}

int Open(const char *path, int oflag) {
    int fd;
    if ((fd = open(path, oflag, S_IRUSR | S_IWUSR)) == -1) {
        //TODO log
        system_error("Open file(%s) failed: ", path);
    }
    return fd;
}

ssize_t PRead(int fd, void *buf, size_t nbytes, int offset) {
    ssize_t rd_bytes = 0, now_rd_bytes;
    while (rd_bytes < nbytes) {
        if ((now_rd_bytes = pread(fd, buf, nbytes, offset)) == -1) {
            system_error("Write error");
        }
        rd_bytes += now_rd_bytes;
        nbytes -= rd_bytes;
        offset += now_rd_bytes;
    }
    return rd_bytes;
}

int Fstat(int fd, struct stat *buf) {
    int res;
    if ((res = fstat(fd, buf)) == -1) {
        system_error("stat error: ");
    }
    return res;
}

int FileSize(int fd) {
    struct stat statbuf;
    Fstat(fd, &statbuf);
    return statbuf.st_size;
}

ssize_t PWrite(int fd, const void *buf, size_t nbytes, int offset) {
    ssize_t wr_bytes = 0, now_wr_bytes;
    while (wr_bytes < nbytes) {
        if ((now_wr_bytes = pwrite(fd, buf, nbytes, offset)) == -1) {
            system_error("Write error");
        }
        wr_bytes += now_wr_bytes;
        nbytes -= wr_bytes;
        offset += now_wr_bytes;
    }
    return wr_bytes;
}
