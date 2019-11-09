#include "DiskRow.h"

FIELD_T Disk::DiskRow::getField(int i) const {
    return *(FIELD_T *) &data_[i * sizeof(FIELD_T)];
}

void Disk::DiskRow::setField(int i, FIELD_T v) {
    *(FIELD_T *) &data_[i * sizeof(FIELD_T)] = v;
}

bool Disk::DiskRow::operator==(const Disk::DiskRow &aRow) const {
    for (int i = 0; i < FIELD_SIZE; i++) {
        if (getField(i) != aRow.getField(i)) {
            return false;
        }
    }
    return true;
}

bool Disk::DiskRow::operator!=(const Disk::DiskRow &aRow) const {
    return !(*this == aRow);
}
