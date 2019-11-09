#pragma once

#include<array>
#include<iostream>
#include<exception>
#include"config.h"

namespace Table {
    class TableRow {
    public:
        using DATA_T = std::array<FIELD_T, FIELD_SIZE>;

        TableRow() = default;

        TableRow(const DATA_T &data) {
            std::copy(data.begin(), data.end(), data_.begin());
        }

        FIELD_T &operator[](int i) {
            if (i < 0 || i > FIELD_SIZE) {
                std::cout << "Index error: " << i << std::endl;
                throw "Index error";
            }
            return data_[i];
        }

        FIELD_T operator[](int i) const {
            if (i < 0 || i > FIELD_SIZE) {
                std::cout << "Index error: " << i << std::endl;
                throw "Index error";
            }
            return data_[i];
        }

        TableRow &operator=(const TableRow &aRow) = default;

        bool operator==(const TableRow &aRow) const {
            for (int i = 0; i < size(); i++) {
                if ((*this)[i] != aRow[i]) {
                    return false;
                }
            }
            return true;
        }

        bool operator!=(const TableRow &aRow) const {
            return !(*this == aRow);
        }

        int size() const {
            return FIELD_SIZE;
        }

    private:
        DATA_T data_;
    };
}
