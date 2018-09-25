#ifndef SPELL_H
#define SPELL_H

#include "define.h"

class Spell
{
	private:
		spellId	id;
		int		coolDown;
		int		manaCost;

	public:
		Spell(spellId _id);
};

#endif // SPELL_H
