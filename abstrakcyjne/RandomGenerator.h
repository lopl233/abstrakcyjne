#pragma once
#include <random>

class RandomH
{
public:
	static bool random_bool_with_prob(const double prob)
	{
		std::random_device rd;
		std::mt19937 gen(rd());
		const std::discrete_distribution<> distrib({ 1 - prob, prob });
		return distrib(gen);
	}
};

template<typename T, typename K1, typename K2>
struct GetRandom
{
	std::shared_ptr<T> operator()(const double prob)
	{
		if (RandomH::random_bool_with_prob(prob))
			switch (rand() % 2)
			{
			case 0:
				return std::shared_ptr<T>(new K1());
			case 1:
				return std::shared_ptr<T>(new K2());
			default:
				return nullptr;
			}
		return nullptr;
	}
};

template<typename K1, typename K2>
struct GetRandom<Field, K1, K2>
{
	Field* operator()(const double prob = 1.0) const
	{
		switch (rand() % 2)
		{
		case 0:
			return new K1();
		case 1:
			return new K2();
		default:
			return nullptr;
		}
	}
};