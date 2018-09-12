#ifndef VECTOR2_H
#define VECTOR2_H

#include <math.h>
#include <vector>
#include <iostream>

class Vector2 {
    public:
        int x;
        int y;

        Vector2(int c_x = 0, int c_y = 0);
        Vector2 operator+=(Vector2 a);
        Vector2 operator-=(Vector2 a);
        void	print();
};

	Vector2 operator+(Vector2 a, Vector2 b);
	Vector2 operator-(Vector2 a, Vector2 b);
	Vector2	operator*(Vector2 a, int b);
	Vector2	operator/(Vector2 a, int b);
	bool	operator==(Vector2 a, Vector2 b);
	bool	operator!=(Vector2 a, Vector2 b);
    double	directDist(Vector2 a, Vector2 b);
    int     squareDist(Vector2 a, Vector2 b);
    int     diagDist(Vector2 a, Vector2 b);
#endif
