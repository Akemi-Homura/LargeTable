//
// Created by quals on 2019-11-08.
//
#include "gtest/gtest.h"
#include <unistd.h>
#include <system/memory.h>
#include "system/file.h"
#include "disk/DiskBlock.h"
#include "TestFactory.h"

TEST(BaseFileOperation, FileExist) {
    ASSERT_EQ(access("notexistfile", F_OK), -1);
}

TEST(BaseFileOperation, ReadWriteFile) {
    // read all and append it to file end
    const char *filename = "read_write_test.txt";
    int fd = Open(filename, O_RDWR);
    int size = FileSize(fd);
    std::array<char, 1024> msg{};
    const char nl = '\n';
    read(fd, &msg, size);
    pwrite(fd, &nl, 1, size);
    pwrite(fd, &msg, size, size + 1);
    fsync(fd);
    std::array<char, 1024> msg2{};
    pread(fd, &msg2, size, size + 1);
    ASSERT_TRUE(strcmp((char *) &msg, (char *) &msg2) == 0);
    close(fd);
}

TEST(BaseFileOperation, OpenFile) {
    // read all and append it to file end
    const char *filename = "file_not_exist";
    Open(filename, O_RDWR | O_CREAT | O_APPEND);
    remove(filename);
}

TEST(ArrayTest, SimpleTest) {
    std::array<char, 100> arr{};
    const char *msg = "hello";
    int len = strlen(msg);
    strcpy((char *) &arr, msg);
    for (int i = 0; i < len; i++) {
        ASSERT_EQ(arr[i], msg[i]);
    }
}

TEST(BaseFileOperation, UnionSize) {
    ASSERT_EQ(Disk::ROW_SIZE, sizeof(Disk::DiskBlock::Meta));
}

class DiskBlockTest : public ::testing::Test {
protected:
    const char *path = "tmp_block1";
    std::shared_ptr<Disk::DiskBlock> block;

    DiskBlockTest() {

    }

    ~DiskBlockTest() override {

    }

    void SetUp() override {
        block = std::make_shared<Disk::DiskBlock>(path);
    }

    void TearDown() override {
        block.reset();
        remove(path);
    }
};

TEST_F(DiskBlockTest, SharedArrayTest){
    Disk::DiskRow defaultRow = *CreateDefaultDiskRow();
    auto buffer = make_shared_array<char>(1024);
    auto data=defaultRow.getData();
    memcpy(buffer.get(), (char *)&data, defaultRow.size());
    ASSERT_EQ(0, memcmp(buffer.get(), (char*)&data,defaultRow.size()));
}

TEST_F(DiskBlockTest, SimpleTest) {
    Disk::DiskRow defaultRow = *CreateDefaultDiskRow();
    ASSERT_EQ(BLOCK_ROW_MAX_SIZE, block->freeLines);

    for (int i = 0; i < BLOCK_ROW_MAX_SIZE; i++) {
        block->addLine(defaultRow);
        ASSERT_EQ(BLOCK_ROW_MAX_SIZE - i - 1, block->freeLines) << "i = " << i;
        if (i != BLOCK_ROW_MAX_SIZE - 1) {
            ASSERT_FALSE(block->isFull()) << "i = " << i;
        }
    }

    ASSERT_TRUE(block->isFull());

    for (int i = 0; i < BLOCK_ROW_MAX_SIZE; i++) {
        ASSERT_EQ(defaultRow, *block->getRow(i)) << "i = " << i;
    }
}