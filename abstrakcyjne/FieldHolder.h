#pragma once
#include "Vector2D.h"
#include "Field.h"

class FieldHolder
{
	Vector2D<Field*>* fields;
public:
	FieldHolder(int size);
	~FieldHolder();
};

