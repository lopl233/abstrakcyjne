
#include "FieldHolder.h"
#include "RandomFieldGenerator.h"
#include "WallField.h"

FieldHolder::FieldHolder(const int size)
{
	fields = new Vector2D<Field*>(size, size);
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if(i < 5 || j < 5 || i > size - 5 || j > size - 5)
			{
				(*fields)[i][j] = new WallField();
			}
			else
			{
				(*fields)[i][j] = RandomFieldGenerator::GetRandomField();
			}
		}
	}
}

FieldHolder::~FieldHolder()
{
	for (auto it = (*fields).getVector()->begin(); it < (*fields).getVector()->end(); ++it)
	{
		for (auto it2 = it->begin(); it2 < it->end(); ++it2)
		{
			delete *it2;
		}
	}
}
