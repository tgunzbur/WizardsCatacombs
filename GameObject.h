#ifndef GAMEOBJECT_H
# define GAMEOBJECT_H

#include "Vector2.h"
#include "Spell.h"
#include <string>
#include <QApplication>
#include <QImage>
#include <QLabel>

class GameObject
{
    protected:
        std::string name;
        QImage      image;
        Vector2     position;
        int         size;

    public:
        GameObject(std::string c_name, Vector2 c_pos);
        void    print();
        Vector2 Move(Vector2 movement);
        Vector2 setPosition(Vector2 newPosition);
        void    display(QWidget *window);
};

class Character: public GameObject
{
    protected:
        int                 maxHealth;
        int                 currentHealth;
        int                 power;

    public:
        std::vector<Spell*> spells;
        Character(std::string           c_name,
                  int                   c_power,
                  int                   c_maxHealth = 100,
                  Vector2               c_pos = Vector2 (0, 0),
                  std::vector<Spell*>   c_spells = std::vector<Spell*>(0));
        ~Character();
        void    print();
        int     ChangeHealth(int value);
};


class Screen
{
   public:
       QWidget                               *window;
       std::vector<std::vector<GameObject*>> *background;
       int                                   size;
       std::vector<Character*>               *character;

       Screen(QWidget *c_window, int c_size);
       void    createRoom(QImage *groundImage);
       void    displayBackGround(Screen screen);
};

#endif
