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

Vector2	Character::movePosition(Vector2 move)
{
	position += move;
	if (move.x > 0 && move.x >= move.y)
		setPixmap(QPixmap(imageName(characters[id].name, RIGHT)));
	else if (move.x < 0 && move.x <= move.y)
		setPixmap(QPixmap(imageName(characters[id].name, LEFT)));
	else if (move.y > 0 && move.y >= move.x)
		setPixmap(QPixmap(imageName(characters[id].name, DOWN)));
	else if (move.y < 0 && move.y <= move.x)
		setPixmap(QPixmap(imageName(characters[id].name, UP)));
	return (position);
}

Vector2	Character::setPosition(Vector2 position)
{
	this->position = position;
	setPixmap(QPixmap(imageName(characters[id].name, DOWN)));
	return (position);
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
