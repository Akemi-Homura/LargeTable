#include "SimpleTable.h"
#include "TableQueryResult.h"
#include "Utils.h"
#include "disk/DiskRow.h"

namespace Table {
	TableQueryResult SimpleTable::addItem(TableRow row)
	{
		Disk::DiskRow diskRow = Utils::TableRow2DiskRow(row);
		Disk::DiskQueryResult diskQueryResult = pDiskManager->addItem(diskRow);
		TableQueryResult result = Utils::DiskResult2TableResult(diskQueryResult);
		return result;
	}

	TableQueryResult SimpleTable::search(TableQuery query)
	{
		Disk::DiskQuery diskQuery = Utils::TableQuery2DiskQuery(query);
		Disk::DiskQueryResult diskQueryResult = pDiskManager->executeQuery(diskQuery);
		TableQueryResult result = Utils::DiskResult2TableResult(diskQueryResult);
		return result;
	}
}
