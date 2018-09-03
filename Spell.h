#ifndef SPELL_H
# define SPELL_H

#include "main.h"
#include <vector>

class Spell
{
    private:
        std::string name;
        std::vector<Vector2> squares;
        int     manaCost;
        int     maxCooldown;
        int     currentCooldown;
        void    (*use)();

    public:
        Spell(std::string c_name, int c_manaCost = 0, int c_maxCooldown = 0,
              std::vector<Vector2>(*range)() = nullptr, void (*c_use)() = nullptr);
        void    useSpell();

};

#endif
