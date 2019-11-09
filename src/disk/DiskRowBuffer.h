//
// Created by quals on 2019-11-08.
//

#ifndef LARGETABLE_DISKROWBUFFER_H
#define LARGETABLE_DISKROWBUFFER_H

#include <list>
#include "DiskRow.h"

namespace Disk {
    class DiskRowBuffer {
    public:
        void add(const DiskRow& diskRow);

        std::shared_ptr<char> mergeBuffer();

        int size();
    private:
        std::list<DiskRow> rowList_;
    };
}


#endif //LARGETABLE_DISKROWBUFFER_H
