#include "RandomMonsterGenerator.h"
#include "Griffin.h"
#include "Ladybug.h"


RandomMonsterGenerator::RandomMonsterGenerator()
{
}

Monster* RandomMonsterGenerator::GetRandomMonster(const double prob)
{
	if (random_bool_with_prob(prob))
		switch (rand() % 2)
		{
		case 0:
			return new Griffin(10, 1);
		case 1:
			return new Ladybug(5, 2);
		default:
			return nullptr;
		}
	return nullptr;
}

RandomMonsterGenerator::~RandomMonsterGenerator()
{
}

