#include "GameObject.h"

using namespace std;

struct s_spell{
    long             id;
    string          name;
    unsigned int    maxCooldown;
    int             manaCost;
	void            (*f)(Vector2, int, vector<vector<GameObject*>>, vector<Character>);
};

void    FireBall(Vector2 position, int power,
				 vector<vector<GameObject*>> map,
				 vector<Character> characters)
{
	Vector2 fireball(position);

	for (int j = 0; j < 5; j++)
	{
		fireball.x++;
		if (!map[unsigned(fireball.y)][unsigned(fireball.x)]->isGround())
			return ;
		for (size_t i = 0; i < characters.size(); i++)
		{
			if (characters[i].isTouched(fireball))
			{
				characters[i].changeHealth(power);
				return ;
			}
		}
	}
}

static s_spell tab[10] =
{
	{0,"FireBall",		3,	10,	FireBall},
	{1,"FireBall",		3,	10,	FireBall},
	{2,"FireBall",		3,	10,	FireBall},
	{3,"FireBall",		3,	10,	FireBall},
	{4,"FireBall",		3,	10,	FireBall},
	{5,"FireBall",		3,	10,	FireBall},
	{6,"FireBall",		3,	10,	FireBall},
	{7,"FireBall",		3,	10,	FireBall},
	{8,"FireBall",		3,	10,	FireBall},
	{9,"FireBall",		3,	10,	FireBall}
};

Spell::Spell(int spellID)
{
	id =            tab[spellID].id;
	name =          tab[spellID].name;
	maxCooldown =   tab[spellID].maxCooldown;
	manaCost =      tab[spellID].manaCost;
	spell =         tab[spellID].f;
    currentCooldown = 0;
}

void    Spell::print()
{
    cout << "Name: "      << name << endl <<
            "Mana Cost: " << manaCost << endl <<
            "Cooldown: "  << currentCooldown <<
            " / "         << maxCooldown << endl << endl;
}

int    Spell::use(int *mana,
				  Vector2 position, int power,
				  vector<vector<GameObject*>> map,
				  vector<Character> characters)
{
	if (currentCooldown > 0 || *mana - manaCost < 0)
        return (0);
	*mana -= manaCost;
    currentCooldown = maxCooldown;
	spell(position, power, map, characters);
    return (1);
}
