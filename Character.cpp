#include "GameObject.h"

using namespace std;

Character::Character(string         c_name,
                     int            c_power,
                     int            c_maxHealth,
                     Vector2        c_pos,
                     vector<Spell*>  c_spells) : GameObject (c_name, c_pos)
{
    power = c_power;
    maxHealth = c_maxHealth;
    currentHealth = maxHealth;
    spells = c_spells;
}

Character::~Character()
{
    for (size_t i = 0; i < spells.size(); i++)
        delete (spells[i]);
    spells.clear();
}

void    Character::print()
{
    GameObject::print();
    cout << "Power : "  << power << endl <<
            "Health : " << currentHealth <<
            " / "       << maxHealth << endl;
    for (size_t i = 0; i < spells.size(); i++)
    {
        cout << endl << "Spell " << i + 1 << " :" << endl;
        spells[i]->print();
    }
    cout << endl << endl;
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
