//
// Created by quals on 2019-11-08.
//

#include "DiskFile.h"
#include "system/file.h"
#include "Utils.h"

namespace Disk {
    DiskFile::DiskFile(std::string path, int oflag) : path_(path), oflag_(oflag), openFlag_(false) {
    }

    ssize_t DiskFile::append(const void *buf, size_t nbytes) {
        if (!openFlag_) {
            open();
        }
        return PWrite(fd_, buf, nbytes, size_);
    }

    ssize_t DiskFile::read(void *buf, size_t nbytes, int offset) {
        if (!openFlag_) {
            open();
        }
        ssize_t res = PRead(fd_, buf, nbytes, offset);
        if (res != nbytes) {
            app_error("Didn't read enough data");
        }
        return res;
    }

    bool DiskFile::isExist() {
        return Utils::IsFileExist(path_);
    }

    int DiskFile::open() {
        if (!openFlag_) {
            openFlag_ = true;
            return (fd_ = Open(path_.c_str(), oflag_));
        }
        return fd_;
    }

    ssize_t DiskFile::write(const void *buf, size_t nbytes, int offset) {
        if (!openFlag_) {
            open();
        }
        ssize_t res = PWrite(fd_, buf, nbytes, offset);
        if (res != nbytes) {
            app_error("Didn't write enough data");
        }
        fsync(fd_);
        return res;
    }


}
