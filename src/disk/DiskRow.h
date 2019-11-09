#pragma once

#include "config.h"
#include <array>
#include <algorithm>

namespace Disk {
    class DiskRow {
    public:
        using DATA_T = RAW_ROW_T;

        DiskRow() = default;

        DiskRow(const DATA_T &data) {
            std::copy(data.begin(), data.end(), data_.begin());
        }

        FIELD_T getField(int i)const;

        DiskRow &operator=(const DiskRow &aRow) = default;

        bool operator==(const DiskRow &aRow)const;

        bool operator!=(const DiskRow&aRow)const;

        void setField(int i, FIELD_T v);

        int size() const{
            return ROW_SIZE;
        }

        DATA_T getData()const{
            return data_;
        }

    private:
        DATA_T data_;
    };
}

