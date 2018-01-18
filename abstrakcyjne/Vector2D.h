#pragma once
#include <vector>

template <class T>
class Vector2D
{
private:
	std::vector<std::vector<T>> _vector2D;
	int r;
	int c;
public:
	Vector2D(int r, int c) : _vector2D(r, std::vector<T>(c)), r(r), c(c)
	{
	}
	~Vector2D() {}
	std::vector<T> & operator[](const int i)
	{
		return _vector2D[i];
	}

	const std::vector<T> & operator[] (const int i) const
	{
		return _vector2D[i];
	}

	int getRowSize() const
	{
		return r;

	}

	int getColSize() const
	{
		return c;

	}

	std::vector<std::vector<T>>* getVector()
	{
		return &_vector2D;
	}
};
