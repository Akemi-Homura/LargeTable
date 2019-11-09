#pragma once
#include"disk/DiskRow.h"
#include"table/TableRow.h"
#include"table/TableQueryResult.h"
#include "disk/DiskQueryResult.h"
#include "table/TableQuery.h"
#include <string>
class Utils
{
public:
	static Disk::DiskRow TableRow2DiskRow(Table::TableRow row);
	static Table::TableRow DiskRow2TableRow(Disk::DiskRow row);
	static Table::TableQueryResult DiskResult2TableResult(Disk::DiskQueryResult diskResult);
	static Disk::DiskQuery TableQuery2DiskQuery(Table::TableQuery tableQuery);
	static bool IsFileExist(std::string path);
};

