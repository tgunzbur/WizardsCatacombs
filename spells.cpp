#include "Scene.h"

bool		fireBall(Scene *scene, Spell *fireBall)
{
	scene->setGameObject(fireBall, fireBall->position + fireBall->direction);
	if (directDist(fireBall->start, fireBall->position) > 3 || !scene->isInRoom(fireBall->position) || !scene->background[unsigned (fireBall->position.y)][unsigned (fireBall->position.x)]->isGround())
		return (false);
	for (size_t i = 0; i < scene->characters.size(); i++)
	{
		if (scene->characters[i]->isTouched(fireBall->position))
		{
			scene->characters[i]->changeHealth(-20);
			return (false);
		}
	}
	return (true);
}

Spell		*createFireBall(Scene *scene, Vector2 position, Vector2 direction, Character *parent)
{
	Spell		*spell;
	std::string	image;

	if (direction == Vector2(0, 1))
		image = ":/fireBallDown.png";
	else if (direction == Vector2(0, -1))
		image = ":/fireBallUp.png";
	else if (direction == Vector2(1, 0))
		image = ":/fireBallRight.png";
	else if (direction == Vector2(-1, 0))
		image = ":/fireBallLeft.png";
	spell = scene->createSpell(image, position, FIREBALL, direction, parent);
	scene->spells.push_back(spell);
	parent->changeMana(-tab[0].manaCost);
	return (spell);
}

std::vector <GameObject *>	displayFireBall(Scene *scene, Character *character)
{
	int				dir;
	unsigned long	i;
	unsigned long	j;
	Vector2			pos;
	bool			stop;

	for (dir = 0; dir < 4; dir++)
	{
		stop = false;
		for (i = 1; i <= 3 && stop == false; i++)
		{
			if (dir == 0)
				pos = character->position + Vector2(int (i), 0);
			else if (dir == 1)
				pos = character->position + Vector2(-int (i), 0);
			else if (dir == 2)
				pos = character->position + Vector2(0, int (i));
			else if (dir == 3)
				pos = character->position + Vector2(0, -int (i));
			if (scene->isInRoom(pos) &&
				scene->background[unsigned (pos.y)][unsigned (pos.x)]->isGround())
			{
				for (j = 0; j < scene->characters.size(); j++)
				{
					if (scene->characters[j]->isTouched(pos))
					{
						scene->spellDisplay.push_back(
						scene->createGameObject(":/redBorder.png", pos, 0));
						stop = true;
					}
				}
				if (!stop)
					scene->spellDisplay.push_back(
					scene->createGameObject(":/greenBorder.png", pos, 0));

			}
			else
				stop = true;
		}
	}
	return (scene->spellDisplay);
}

Spell		*createClone(Scene *scene, Vector2 position, Vector2 direction, Character *parent)
{
	Character	*spell;
	std::string	image;

	spell = scene->createCharacter(":/playerDown.png", position + direction, PLAYERCLONE, "Player Clone", 1, 0, false);
	spell->setOpacity(0.5);
	scene->characters.push_back(spell);
	parent->changeMana(-tab[1].manaCost);
	return (nullptr);
}

std::vector <GameObject *>	displayClone(Scene *scene, Character *character)
{
	bool			stop;
	unsigned long	dir;
	unsigned long	j;
	Vector2			pos;

	stop = false;
	for (dir = 0; dir < 4; dir++)
	{
		if (dir == 0)
			pos = character->position + Vector2(1, 0);
		else if (dir == 1)
			pos = character->position + Vector2(-1, 0);
		else if (dir == 2)
			pos = character->position + Vector2(0, 1);
		else if (dir == 3)
			pos = character->position + Vector2(0, -1);
		if (scene->isInRoom(pos) &&
			scene->background[unsigned (pos.y)][unsigned (pos.x)]->isGround())
		{
			pos.print();
			for (j = 0; j < scene->characters.size(); j++)
			{
				if (scene->characters[j]->isTouched(pos))
					stop = true;
			}
			if (!stop)
				scene->spellDisplay.push_back(
				scene->createGameObject(":/greenBorder.png", pos, 0));

		}
		stop = false;
	}
	return (scene->spellDisplay);
}
