#ifndef GAMEOBJECT_H
# define GAMEOBJECT_H

#include "main.h"

class GameObject
{
    private:
        QImage  image;
        Vector2 position;
        int     size;
        int     id;

    public:
        GameObject(Vector2 c_pos);
        Vector2 Move(Vector2 movement);
        void    display(QWidget *window);
        void    print();
};

#endif
