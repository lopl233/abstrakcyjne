#pragma once
#include <string>

class Field
{
protected:
	std::string filename;
public:
	Field();
	virtual std::string getFilename() = 0;
	virtual ~Field();
};

