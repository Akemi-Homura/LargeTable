//
// Created by quals on 2019-11-08.
//

#ifndef LARGETABLE_TESTFACTORY_H
#define LARGETABLE_TESTFACTORY_H

#include "disk/DiskRow.h"

std::shared_ptr<Disk::DiskRow> CreateDefaultDiskRow() {
    std::shared_ptr<Disk::DiskRow> pDiskRow = std::make_shared<Disk::DiskRow>();
    for (int i = 0; i < pDiskRow->size(); i++) {
        pDiskRow->setField(i, static_cast<int64_t>(i));
    }
    return pDiskRow;
}

#endif //LARGETABLE_TESTFACTORY_H
