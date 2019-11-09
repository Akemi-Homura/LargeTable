#pragma once
#include "ITable.h"
#include"disk/DiskManager.h"
#include"IndexManager.h"
namespace Table {
	class SimpleTable :
		public ITable
	{
	protected:
		Disk::DiskManager* pDiskManager;
		Index::IndexManager* pIndexManager;
	public:
		// Inherited via ITable
		virtual TableQueryResult addItem(TableRow row) override;
		virtual TableQueryResult search(TableQuery query) override;
	};
}

