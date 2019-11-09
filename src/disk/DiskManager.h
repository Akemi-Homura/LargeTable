#pragma once
#include<array>
#include <vector>
#include "DiskQueryResult.h"
#include "config.h"
#include "DiskQuery.h"
#include "DiskRow.h"
#include "QueryResult.h"
namespace Disk {
	class DiskManager
	{
	public:
		DiskQueryResult addItem(DiskRow row);
		DiskQueryResult executeQuery(DiskQuery query);
	};
}

