#ifndef CHARACTER_H
# define CHARACTER_H

#include "GameObject.h"

class Character: public GameObject
{
    private:
        int maxHealth;
        int currentHealth;

    public:
        Character(int c_maxHealth = 100, Vector2 c_pos = Vector2 (0, 0));
        int     ChangeHealth(int value);
};

#endif
