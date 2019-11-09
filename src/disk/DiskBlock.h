#pragma once

#include "config.h"
#include "DiskRow.h"
#include <fstream>
#include "system/file.h"
#include "DiskFile.h"
#include <list>
#include "DiskRowBuffer.h"

namespace Disk {
    class DiskBlock {
    public:
        union Meta {
            char raw[ROW_SIZE];
            int num;
        };

        void flushToDisk();

        DiskBlock() = delete;

        DiskBlock(std::string path);

        std::shared_ptr<DiskRow> getRow(int i);

        bool isFull();

        int addLine(DiskRow row);

        int &freeLines;
    private:
        void readMeta();
        static const int DataOffset;
        Meta freeLineNum;
        int lastFreeLineNum_;
        DiskRowBuffer rowBuffer_;
        std::shared_ptr<DiskFile> file_;
    };
}

