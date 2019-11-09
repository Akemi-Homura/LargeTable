#include "table/TableRow.h"
#include "disk/DiskRow.h"
#include "Utils.h"
#include "disk/DiskQuery.h"
#include "QueryResult.h"
#include "gtest/gtest.h"

TEST(TestRow, SimpleTest) {
    Table::TableRow tableRow;
    Disk::DiskRow diskRow;
    for (int i = 0; i < FIELD_SIZE; i++) {
        tableRow[i] = static_cast<int64_t>(i);
        diskRow.setField(i, static_cast<int64_t>(i));
    }
    for (int i = 0; i < FIELD_SIZE; i++) {
        ASSERT_EQ(tableRow[i], static_cast<int64_t>(i));
        ASSERT_EQ(diskRow.getField(i), static_cast<int64_t>(i));
    }

    diskRow = Utils::TableRow2DiskRow(tableRow);
    for (int i = 0; i < FIELD_SIZE; i++) {
        ASSERT_EQ(tableRow[i], static_cast<int64_t>(i));
        ASSERT_EQ(diskRow.getField(i), static_cast<int64_t>(i));
        ASSERT_EQ(tableRow[i], diskRow.getField(i));
    }
}

TEST(TestQuery, SimpleTest) {
    Disk::DiskQuery query(1, 1, 100);
    ASSERT_EQ(query.fieldIndex, 1);
    ASSERT_EQ(query.low, 1);
    ASSERT_EQ(query.up, 100);
}

TEST(TestQueryResult, SimpleTest) {
    Table::TableQueryResult table_qr_empty;
    ASSERT_EQ(table_qr_empty.size(), 0);
    ASSERT_EQ(table_qr_empty.isSuccess(), true);

    std::array<Table::TableQueryResult::ROW_T, 10> lines;
    for (int j = 0; j < 10; j++) {
        Table::TableRow tableRow;
        for (int i = 0; i < FIELD_SIZE; i++) {
            tableRow[i] = static_cast<int64_t>(i);
        }
        lines[j] = tableRow;
    }
    Table::TableQueryResult table_qr(lines, 1);
    for (const auto &line : table_qr.results) {
        for (int i = 0; i < FIELD_SIZE; i++) {
            ASSERT_EQ(line[i], static_cast<int64_t>(i));
        }
    }
}