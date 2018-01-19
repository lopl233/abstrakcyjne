#pragma once
#include <string>

class Field
{
protected:
	std::string filename;
	bool canBeSteped;
public:
	Field();
	virtual std::string getFilename()
	{
		return filename;
	}
	virtual ~Field() = 0;
};

