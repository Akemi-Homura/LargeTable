//
// Created by quals on 2019-11-08.
//

#ifndef LARGETABLE_DISKFILE_H
#define LARGETABLE_DISKFILE_H

#include <string>

namespace Disk {
    class DiskFile {
    public:
        DiskFile() = delete;

        DiskFile(std::string path, int oflag);

        DiskFile(const DiskFile &aFile) : DiskFile(aFile.path_, aFile.oflag_) {}

        ssize_t append(const void *buf, size_t nbytes);

        ssize_t read(void *buf, size_t nbytes, int offset = 0);

        ssize_t write(const void*buf, size_t nbytes, int offset=0);

        bool isExist();

        int open();

    private:
        int fd_;
        std::string path_;
        int size_;
        int oflag_;
        bool openFlag_;
    };
}


#endif //LARGETABLE_DISKFILE_H
