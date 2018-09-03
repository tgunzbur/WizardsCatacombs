#include "Spell.h"

Spell::Spell(std::string c_name,
             int c_manaCost,
             int c_maxCooldown,
             std::vector<Vector2>(*range)(),
             void (*c_use)())
{
    name = c_name;
    manaCost = c_manaCost;
    maxCooldown = c_maxCooldown;
    currentCooldown = 0;
    use = c_use;
    if (range)
        squares = range();
}

void    Spell::useSpell()
{
    use();
}
