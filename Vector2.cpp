#include <math.h>
#include "main.h"

Vector2::Vector2(int c_x, int c_y)
{
	x = c_x;
	y = c_y;
}

Vector2		Vector2::operator+=(Vector2 a)
{
	*this = *this + a;
	return (*this);
}

Vector2		Vector2::operator-=(Vector2 a)
{
	*this = *this - a;
	return (*this);
}

void		Vector2::print()
{
    std::cout << "X : " << x << std::endl << "Y : " << y << std::endl;
}

Vector2		operator+(Vector2 a, Vector2 b)
{
	Vector2 result;

	result.x = a.x + b.x;
	result.y = a.y + b.y;
	return (result);
}

Vector2		operator-(Vector2 a, Vector2 b)
{
	Vector2 result;

	result.x = a.x - b.x;
	result.y = a.y - b.y;
	return (result);
}

bool		operator==(Vector2 a, Vector2 b)
{
	return (a.x == b.x && a.y == b.y ? true : false);
}

bool		operator!=(Vector2 a, Vector2 b)
{
	return (a == b ? false : true);
}

double		directDist(Vector2 a, Vector2 b)
{
	if (a == b)
		return (0);
	int distX = abs(a.x - b.x);
	int distY = abs(a.y - b.y);
	return (sqrt(distX * distX + distY * distY));
}

int         squareDist(Vector2 a, Vector2 b)
{
    return (abs(a.x - b.x) + abs(a.y - b.y));
}

int         diagDist(Vector2 a, Vector2 b)
{
    return (int(fmax(abs(a.x - b.x), abs(a.y - b.y))));
}
