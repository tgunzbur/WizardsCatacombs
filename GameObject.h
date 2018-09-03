#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "main.h"
class GameObject
{
    private:
        QImage  image;
        QLabel  *label;
        Vector2 position;
        int     size;
        int     id;

    public:
        GameObject(QImage c_img, Vector2 c_pos, int c_size);
        Vector2 Move(Vector2 movement);
        void    display(QWidget *window);
        void    print();
};

#endif
