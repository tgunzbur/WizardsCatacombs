#include "GameObject.h"

using namespace std;

Character::Character(string         c_name,
                     int            c_power,
                     int            c_maxHealth,
                     int            c_maxMana,
                     Vector2        c_pos) : GameObject (c_name, c_pos)
{
    power = c_power;
    maxHealth = c_maxHealth;
    currentHealth = maxHealth;
    maxMana = c_maxMana;
    currentMana = maxMana;
    for (int i = 0; i < 4; i++)
		spells[i] = new Spell(i);
}

Character::~Character()
{
    for (int i = 0; i < 4; i++)
        delete spells[i];
}

void    Character::print()
{
    GameObject::print();
	cout << "Power : "  << power << endl <<
            "Health : " << currentHealth <<
			" / "       << maxHealth << endl << endl;
    for (int i = 0; i < 4; i++)
    {
		cout << "Spell " << i + 1 << ":"<< endl;
        spells[i]->print();
    }
    cout << endl;
}

void    Character::changeSpell(int slot, int newSpellID)
{
    delete spells[slot];
    spells[slot] = new Spell(newSpellID);
}

int     Character::useSpell(int slot, vector<vector<GameObject*>> map, vector<Character> characters)
{
	return (spells[slot]->use(&currentMana, position, power, map, characters));
}

int     Character::changeHealth(int value)
{
    currentHealth += value;
	if (currentHealth > maxHealth)
        currentHealth = maxHealth;
    else if (currentHealth < 0)
        currentHealth = 0;
    return (currentHealth);
}

int     Character::useMana(int value)
{
    if (value > currentMana)
        return (0);
    currentMana -= value;
    return (1);
}
