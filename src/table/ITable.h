#pragma once
#include<vector>
#include<array>
#include"TableRow.h"
#include"TableQuery.h"
#include"TableQueryResult.h"
namespace Table {
	class ITable
	{
	public:
		virtual TableQueryResult addItem(TableRow row) = 0;
		virtual TableQueryResult search(TableQuery query) = 0;
	};
}

