#ifndef GAMEOBJECT_H
# define GAMEOBJECT_H

#include "Vector2.h"
#include <vector>
#include <string>
#include <QApplication>
#include <QImage>
#include <QLabel>

class Spell;
class Screen;

class GameObject
{
    protected:
		std::string	name;
		Vector2		position;

	public:
        GameObject(std::string c_name, Vector2 c_pos);
        void    print();
        Vector2 Move(Vector2 movement);
        Vector2 setPosition(Vector2 newPosition);
		bool	isTouched(Vector2 pos);
		bool	isGround();
};

class Character: public GameObject
{
    protected:
		int					maxHealth;
		int					currentHealth;
		int					maxMana;
		int					currentMana;
		Spell				*spells[4];

    public:
        int     power;
        Character(std::string           c_name,
                  int                   c_power,
                  int                   c_maxHealth = 100,
                  int                   c_maxMana = 50,
                  Vector2               c_pos = Vector2 (0, 0));
        ~Character();
        void    print();
        void    changeSpell(int slot, int newSpellID);
		int     useSpell(int slot, std::vector<std::vector<GameObject*>> map, std::vector<Character> characters);
        int     changeHealth(int value);
        int     useMana(int value);
};


class Scene
{
   public:
	   std::vector<std::vector<GameObject*>> *background;
	   std::vector<Character*>               *character;
};

class Spell
{
	protected:
        long                    id;
        std::string             name;
        std::vector<Vector2>    range;
        int                     manaCost;
        unsigned int            maxCooldown;
        unsigned int            currentCooldown;
		void                    (*spell)(Vector2, int, std::vector<std::vector<GameObject*>>, std::vector<Character>);

    public:
		Spell(int spellID);
        void    print();
		int     use(int *mana, Vector2 position, int power, std::vector<std::vector<GameObject*>> map, std::vector<Character> characters);
};

#endif
