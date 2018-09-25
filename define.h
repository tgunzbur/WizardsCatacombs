#ifndef DEFINE_H
#define DEFINE_H

#include <string>

#define ROOMSIZE 5

typedef enum	e_directionId
{
	UP,
	DOWN,
	LEFT,
	RIGHT
}				directionId;

typedef enum	e_gameObjectId
{
	NOGAMEOBJECT,
	GROUND,
	WALLGROUND,
	WALL,
	STAIR
}				gameObjectId;

typedef enum	e_characterId
{
	NOCHARACTER,
	PLAYER,
	SKELETON
}				characterId;

typedef enum	e_spellId
{
	NOSPELL,
	FIREBALL,
	HEAL
}				spellId;

static std::string	gameObjects[5] =
{
	"",
	":/ground.png",
	":/groundWithWall.png",
	":/wall.png",
	":/stairDown.png"
};

typedef struct	s_characters
{
	std::string	name;
	int			life;
	int			mana;
}				t_characters;

static t_characters	characters[3] =
{
	{"", 0, 0},
	{"player", 100, 100},
	{"skeleton", 100, 100}
};

typedef struct	s_spells
{
	std::string	image;
	int			coolDown;
	int			manaCost;
}				t_spells;


static t_spells		spells[3] =
{
	{"", 0, 0},
	{":/fireball.png", 1, 10},
	{":/heal.png", 2, 25}
};

const char	*imageName(std::string name, directionId direction);

#endif // DEFINE_H
