#pragma once
#include "Field.h"

class RandomFieldGenerator
{
public:
	RandomFieldGenerator();
	static Field* GetRandomField();
	~RandomFieldGenerator();
};
