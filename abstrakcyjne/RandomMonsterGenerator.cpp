#include "RandomMonsterGenerator.h"
#include "Griffin.h"
#include "Ladybug.h"
#include <memory>


RandomMonsterGenerator::RandomMonsterGenerator()
{
}

std::shared_ptr<Monster> RandomMonsterGenerator::GetRandomMonster(const double prob)
{
	if (random_bool_with_prob(prob))
		switch (rand() % 2)
		{
		case 0:
			return std::static_pointer_cast<Monster>(std::make_shared<Griffin>(10, 1));
		case 1:
			return std::static_pointer_cast<Monster>(std::make_shared<Ladybug>(5, 2));
		default:
			return nullptr;
		}
	return nullptr;
}

RandomMonsterGenerator::~RandomMonsterGenerator()
{
}

