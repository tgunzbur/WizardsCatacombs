#include "Spell.h"

Spell::Spell(spellId _id)
{
	id = _id;
	coolDown = spells[id].coolDown;
	manaCost = spells[id].manaCost;
}
