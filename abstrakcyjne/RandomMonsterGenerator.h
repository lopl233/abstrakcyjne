#pragma once
#include <random>
#include "Monster.h"

class RandomMonsterGenerator
{
private:
	static bool random_bool_with_prob(const double prob)  // probability between 0.0 and 1.0
	{
		std::random_device rd;
		std::mt19937 gen(rd());
		const std::discrete_distribution<> distrib({ 1 - prob, prob });
		return distrib(gen);
	}
public:
	RandomMonsterGenerator();
	static Monster* GetRandomMonster(double prob);
	~RandomMonsterGenerator();
};

