#include "RandomFieldGenerator.h"
#include "ForestField.h"
#include "SandField.h"


RandomFieldGenerator::RandomFieldGenerator()
{
}

Field* RandomFieldGenerator::GetRandomField()
{
	switch (rand() % 2)
	{
	case 0:
		return new ForestField();
	case 1:
		return new SandField();
	default:
		return nullptr;
	}
}


RandomFieldGenerator::~RandomFieldGenerator()
{
}
