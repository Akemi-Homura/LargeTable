#include "Utils.h"
#include <fstream>
#include <unistd.h>

Disk::DiskRow Utils::TableRow2DiskRow(Table::TableRow row) {
    Disk::DiskRow diskRow{};
    for (int i = 0; i < row.size(); i++) {
        diskRow.setField(i, row[i]);
    }
    return diskRow;
}

Table::TableQueryResult Utils::DiskResult2TableResult(Disk::DiskQueryResult diskResult) {
    std::vector<Table::TableQueryResult::ROW_T> lines(diskResult.size());
    for (int i = 0; i < diskResult.size(); i++) {
        lines[i] = DiskRow2TableRow(diskResult.results[i]);
    }
    return Table::TableQueryResult(lines, diskResult.getStatus());
}

Disk::DiskQuery Utils::TableQuery2DiskQuery(Table::TableQuery tableQuery) {
    return tableQuery;
}

bool Utils::IsFileExist(std::string path) {
    return access(path.c_str(), F_OK) != -1;
}

Table::TableRow Utils::DiskRow2TableRow(Disk::DiskRow row) {
    Table::TableRow tableRow{};
    for (int i = 0; i < row.size(); i++) {
        tableRow[i] = row.getField(i);
    }
    return tableRow;
}
