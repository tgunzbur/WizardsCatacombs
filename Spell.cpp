#include "Spell.h"

using namespace std;

void    FireBall(vector<Vector2> squares)
{
    (void)squares;
    cout << "PAF" << endl;
}


Spell::Spell(int spellId)
{
    string  c_name[4] = {
        "salut",
        "J'ai du mal",
        "a trouver",
        "des noms"
    };
    void    (*f[4])(vector<Vector2>) = {
        &FireBall,
        &FireBall,
        &FireBall,
        &FireBall
    };
    unsigned int     c_maxCooldown[4] = {
        0,
        1,
        4,
        171
    };
    int     c_manaCost[4] = {
        2,
        1,
        5,
        80
    };
    vector<Vector2> c_range[4] = {
        {Vector2 (1, 0)},
        {Vector2 (1, 0), Vector2 (2, 0)},
        {Vector2 (1, 0), Vector2 (-1, 0), Vector2 (0, -1),Vector2 (0, 1)},
        {}
    };
    name = c_name[spellId];
    maxCooldown = c_maxCooldown[spellId];
    manaCost = c_manaCost[spellId];
    use = f[spellId];
    range = c_range[spellId];
    currentCooldown = 0;
}

void    Spell::print()
{
    cout << "Name: "      << name << endl <<
            "Mana Cost: " << manaCost << endl <<
            "Cooldown: "  << currentCooldown <<
            " / "         << maxCooldown << endl;
}

int    Spell::useSpell(vector<Vector2> squares)
{
    if (currentCooldown > 0)
        return (0);
    currentCooldown = maxCooldown;
    use(squares);
    return (1);
}
