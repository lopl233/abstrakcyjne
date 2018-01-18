#include "Field.h"
#include "ForestField.h"

class RandomFieldGenerator
{
public:
	static Field& GetRandomField()
	{
		auto v1 = rand() % 2;
		switch(rand() % 2)
		{
		case 0:
			return ForestField();
			break;
		case 1:
			break;
		}
	}
};
