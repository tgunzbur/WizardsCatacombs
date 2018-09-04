#ifndef SPELL_H
# define SPELL_H

#include <iostream>
#include <vector>
#include "Vector2.h"

class Spell
{
    protected:
        std::string             name;
        std::vector<Vector2>    range;
        int                     manaCost;
        unsigned int            maxCooldown;
        unsigned int            currentCooldown;
        void                    (*use)(std::vector<Vector2>);

    public:
        Spell(int spellId);
        void    print();
        int     useSpell(std::vector<Vector2> squares);
};

#endif
