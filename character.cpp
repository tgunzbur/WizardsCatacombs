#include "character.h"

Character::Character(int c_maxHealth, Vector2 c_pos) : GameObject (c_pos)
{
    maxHealth = c_maxHealth;
    currentHealth = maxHealth;
}

int     Character::ChangeHealth(int value)
{
    currentHealth += value;
    if (currentHealth > maxHealth)
        currentHealth = maxHealth;
    else if (currentHealth < 0)
        currentHealth = 0;
    return (currentHealth);
}
