#include "Character.h"

using namespace std;

Character::Character(characterId _id, Vector2 _position) : GameObject (_id, _position)
{
	int		count;

	maxLife = characters[id].life;
	maxMana = characters[id].mana;
	life = maxLife;
	mana = maxMana;
	for (count = 0; count < 4; count++)
		spells[count] = new Spell(NOSPELL);
}

int     Character::changeHealth(int value)
{
	life += value;
	life = (life > maxLife ? maxLife : life);
	life = (life < 0 ? 0 : life);
	return (life);
}

int     Character::changeMana(int value)
{
	mana += value;
	mana = (mana > maxMana ? maxMana : mana);
	mana = (mana < 0 ? 0 : mana);
	return (mana);
}

bool	Character::isAtPos(Vector2 position)
{
	if (this->position == position)
		return (true);
	return (false);
}
