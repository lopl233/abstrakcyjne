#include "FieldHolder.h"
#include "WallField.h"
#include "RandomGenerator.h"
#include "ForestField.h"
#include "SandField.h"
#include "Griffin.h"
#include "Ladybug.h"
#include "HPPotion.h"
#include "MPPotion.h"

FieldHolder::FieldHolder(const int size)
{
	fields = new Vector2D<Field*>(size, size);
	const GetRandom<Field, SandField, ForestField> getRandomField{};
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (i < 6 || j < 6 || i >= size - 6 || j >= size - 6)
			{
				(*fields)[i][j] = new WallField();
			}
			else
			{
				(*fields)[i][j] = getRandomField();

			}
		}
	}
}

FieldHolder::FieldHolder(const int size, const double prob) : FieldHolder(size)
{
	GetRandom<Monster, Ladybug, Griffin> getRandomMonster(prob);
	GetRandom<Potion, HPPotion, MPPotion> getRandomPotion(prob / 2);

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			(*fields)[i][j]->AddMonster(getRandomMonster());
			if ((*fields)[i][j]->GetMonster() == nullptr)
			{
				(*fields)[i][j]->AddPotion(getRandomPotion());
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
