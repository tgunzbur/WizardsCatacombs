#include "GameObject.h"

Screen::Screen(MainWindow *c_window, int c_size)
{
    up = new QPushButton(c_window);
    down = new QPushButton(c_window);
    left = new QPushButton(c_window);
    right = new QPushButton(c_window);
    up->setGeometry(100,600, 50, 50);
    down->setGeometry(100,700, 50, 50);
    left->setGeometry(150,650, 50, 50);
    right->setGeometry(50,650, 50, 50);
    QPushButton::connect(up, SIGNAL (clicked()), c_window, SLOT (InputUp()));
    QPushButton::connect(down, SIGNAL (clicked()), c_window, SLOT (InputDown()));
    QPushButton::connect(left, SIGNAL (clicked()), c_window, SLOT (InputLeft()));
    QPushButton::connect(right, SIGNAL (clicked()), c_window, SLOT (InputRight()));
    background = new std::vector <std::vector <GameObject *>*>;
    characters = new std::vector <GameObject*>;
    window = c_window;
    size = c_size;
}

void    Screen::createRoom(QImage *groundImage)
{
    unsigned long   x;
    unsigned long   y;

    for (y = 0; int (y) < size; y++)
    {
        background->push_back(new std::vector <GameObject*>);
        for (x = 0; int (x) < size; x++)
        {
            (*background)[y]->push_back(new GameObject(this, groundImage, Vector2(int (x), int (y))));
        }
    }
}

void    Screen::displayBackGround()
{
    unsigned long   y;
    unsigned long   x;

    for (y = 0; int (y) < size; y++)
    {
        for (x = 0; int (x) < size; x++)
        {
            (*(*background)[y])[x]->display();
        }
    }
}
