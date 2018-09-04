#ifndef VECTOR2_HPP
# define VECTOR2_HPP

#include "iostream"
#include <math.h>
#include <vector>

class Vector2 {
    public:
        int x;
        int y;

        Vector2(int c_x = 0, int c_y = 0);
        Vector2 operator+=(Vector2 a);
        Vector2 operator-=(Vector2 a);
        void	print();
};

    Vector2 operator+   (Vector2 a, Vector2 b);
    Vector2 operator-   (Vector2 a, Vector2 b);
    bool	operator==  (Vector2 a, Vector2 b);
    bool	operator!=  (Vector2 a, Vector2 b);
    double	directDist  (Vector2 a, Vector2 b);
    int     squareDist  (Vector2 a, Vector2 b);
    int     diagDist    (Vector2 a, Vector2 b);

#endif
