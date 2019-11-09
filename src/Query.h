#pragma once
#include "config.h"
class Query
{
public:
	Query() :Query(0, 0, 0) {}
	Query(FIELD_INDEX_T aFieldIndex, FIELD_T aLow, FIELD_T aUp) :fieldIndex(fieldIndex_), up(up_), low(low_)
	{
		fieldIndex_ = aFieldIndex;
		low_ = aLow;
		up_ = aUp;
	}
	Query(const Query& rhs) :Query(rhs.fieldIndex_, rhs.up_, rhs.low_) {

	}
	const FIELD_INDEX_T& fieldIndex;
	const FIELD_T& up;
	const FIELD_T& low;
private:
	FIELD_INDEX_T fieldIndex_;
	FIELD_T up_;
	FIELD_T low_;
};


