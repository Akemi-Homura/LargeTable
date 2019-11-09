//
// Created by quals on 2019-11-08.
//

#include "DiskRowBuffer.h"
#include "system/memory.h"


void Disk::DiskRowBuffer::add(const Disk::DiskRow &diskRow) {
    rowList_.push_back(diskRow);
}

std::shared_ptr<char> Disk::DiskRowBuffer::mergeBuffer() {
    auto buffer = make_shared_array<char>(size());
    int cur_size = 0;
    for (const auto &row:rowList_) {
        DiskRow::DATA_T data = row.getData();
        memcpy(buffer.get() + cur_size, (char *) (&data),row.size());
        cur_size += row.size();
    }
    rowList_.clear();
    return buffer;
}

int Disk::DiskRowBuffer::size() {
    return rowList_.size() * ROW_SIZE;
}
