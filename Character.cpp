#include "GameObject.h"

using namespace std;

Character::Character(QPixmap c_image, Vector2 c_pos, int id,
					 string c_name, int c_maxHealth, int c_maxMana, GameObject *c_lifeBar)
					: GameObject (c_image, c_pos, id, c_name)
{
	lifeBar = c_lifeBar;
    maxHealth = c_maxHealth;
	maxMana = c_maxMana;
    currentHealth = maxHealth;
    currentMana = maxMana;
	text = 0;
	cdText = 0;
    for (int i = 0; i < 4; i++)
	{
		spells[i] = 0;
		spellsCd[i] = 0;
	}
	spells[1] = 1;
}

int     Character::changeHealth(int value)
{
	currentHealth += value;
	text = value;
	if (currentHealth > maxHealth)
		currentHealth = maxHealth;
	else if (currentHealth < 0)
		currentHealth = 0;
	print();
	return (currentHealth);
}

int     Character::changeMana(int value)
{
	currentMana += value;
	if (currentMana > maxMana)
		currentMana = maxMana;
	else if (currentMana < 0)
		currentMana = 0;
	return (currentMana);
}

void    Character::print()
{
    GameObject::print();
	cout << "Health: " << currentHealth << "/" << maxHealth << endl;
	cout << "Mana: " << currentMana << "/" << maxMana << endl;
    cout << endl;
}
