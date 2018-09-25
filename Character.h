#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>

#include "GameObject.h"
#include "Vector2.h"
#include "Spell.h"
#include "define.h"

class Character: public GameObject
{
	private:
		int		life;
		int		mana;
		int		maxLife;
		int		maxMana;
		Spell	*spells[4];

	public:
		Character(characterId _id, Vector2 _position);

		int     changeHealth(int value);
		int     changeMana(int value);

		bool	isAtPos(Vector2 position);
};

#endif // CHARACTER_H
