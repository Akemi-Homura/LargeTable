#include "DiskBlock.h"
#include "Utils.h"

namespace Disk {
    const int DiskBlock::DataOffset = sizeof(DiskBlock::Meta);

    void DiskBlock::readMeta() {
        if (!file_->isExist()) {
            freeLineNum.num = BLOCK_ROW_MAX_SIZE;
            file_->open();
            lastFreeLineNum_ = freeLines;
            return;
        }
        file_->open();
        file_->read(&freeLineNum, sizeof(freeLineNum));
        lastFreeLineNum_ = freeLines;
    }

    void DiskBlock::flushToDisk() {
        if (lastFreeLineNum_ != freeLines) {
            file_->write(&freeLineNum, sizeof(freeLineNum));
            int size = rowBuffer_.size();
            auto buffer = rowBuffer_.mergeBuffer();
            int offset = DataOffset + (BLOCK_ROW_MAX_SIZE - lastFreeLineNum_) * ROW_SIZE;
            file_->write(buffer.get(), size, offset);
            lastFreeLineNum_ = freeLines;
        }
    }

    int DiskBlock::addLine(DiskRow row) {
        static int MAX_BUFFER_SIZE = 4096;
        if (freeLines > 0) {
            rowBuffer_.add(row);
            freeLines--;
            if (rowBuffer_.size() > MAX_BUFFER_SIZE) {
                flushToDisk();
            }
            return 0;
        }
        throw "Block is full";
    }

    bool DiskBlock::isFull() {
        return freeLines == 0;
    }

    DiskBlock::DiskBlock(std::string path) : freeLines(freeLineNum.num), lastFreeLineNum_(0) {
        file_ = std::make_shared<DiskFile>(path, O_RDWR | O_CREAT | O_APPEND);
        readMeta();
    }

    std::shared_ptr<DiskRow> DiskBlock::getRow(int i) {
        if (rowBuffer_.size() > 0) {
            flushToDisk();
        }
        DiskRow::DATA_T data;
        int offset = DataOffset + i * ROW_SIZE;
        file_->read((char *) &data, ROW_SIZE, offset);
        return std::make_shared<DiskRow>(data);
    }

}