#include "main.h"

using namespace std;

int    main()
{
    vector<Vector2> s = {};
    vector<Spell*> playerspell;
    vector<Spell*> monsterspell;
    monsterspell.push_back(new Spell(1));
    playerspell.push_back(new Spell(2));
    playerspell.push_back(new Spell(3));
    Character monster("Gnork", 12, 50, Vector2 (2, 3), monsterspell);
    Character player("Billy", 20, 100, Vector2(5, 5), playerspell);

    player.ChangeHealth(-20);
    player.spells[0]->useSpell(s);
    player.print();
    monster.print();
    return (0);
}
