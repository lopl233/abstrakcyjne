#pragma once
#include <string>
#include "PotionType.h"

class Potion
{
protected:
	std::string filename;
	PotionType potionType;
	const int val = 10;

	Potion(std::string filename, PotionType pt);

public:
	Potion();
	virtual int getVal()
	{
		return val;
	}


	virtual std::string getFilename()
	{
		return filename;
	}

	virtual ~Potion();
};

