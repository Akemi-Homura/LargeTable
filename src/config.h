#pragma once
#include <cstdint>
#include <array>

using FIELD_T = int64_t;
using FIELD_INDEX_T = int;
const int FIELD_SIZE = 100;
namespace Disk {
	const int ROW_SIZE = FIELD_SIZE * sizeof(FIELD_T);
	using RAW_ROW_T = std::array<char, ROW_SIZE>;
}
const int BLOCK_ROW_MAX_SIZE = 15625;