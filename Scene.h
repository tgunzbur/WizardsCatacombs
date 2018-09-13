#ifndef SCENE_H
#define SCENE_H

#include <QGraphicsScene>
#include <QWidget>
#include <QKeyEvent>
#include <QPixmap>
#include <string>
#include <QThread>

#include "Vector2.h"
#include "GameObject.h"

class	Scene: public QGraphicsScene
{
	Q_OBJECT

	public:
		bool										aiLaunch;
		int											pa;
		int											spellSelect;
		int											roomSize;
		std::vector	<GameObject *>					UI;
		std::vector <std::vector <GameObject *>>    background;
		std::vector <Character *>					characters;
		std::vector	<Spell *>						spells;
		std::vector <QGraphicsTextItem *>			texts;
		std::vector <GameObject *>					spellDisplay;

		Scene(int c_roomSize);

		GameObject	*createGameObject(std::string image, Vector2 position, int id);
		Character	*createCharacter(std::string image, Vector2 position, int id, std::string name, int maxHealth, int maxMana, bool gotLifeBar);
		Spell		*createSpell(std::string image, Vector2 position, int id, Vector2 direction, Character *parent);
		GameObject	*updateGameObject(GameObject *gameObject);
		Vector2		moveGameObject(GameObject *gameObject, Vector2 move);
		Vector2		setGameObject(GameObject *gameObject, Vector2 position);
		void		createBackGround();
		void		deleteBackGround();
		void		deleteCharacters();
		void		deleteSpells();
		void		deleteTexts();
		void		deleteSpellDisplay();
		void		deleteVectors();
		void		launchAi();
		void		createUi();
		void		changeMana(Character *player);
		void		changeLife(Character *player);
		void		updateLife(Character *character);
		bool		isInRoom(Vector2 position);
		bool		isUnderWall(Vector2 position);
		void		keyPressEvent(QKeyEvent *event);		

	public slots:
		void	game();
};


void						skeletonAi(Scene *scene, Character *skeleton);
std::vector <GameObject *>	displayFireBall(Scene *scene, Character *character);
std::vector <GameObject *>	displayClone(Scene *scene, Character *character);
Spell						*createFireBall(Scene *scene, Vector2 position, Vector2 direction, Character *parent);
Spell						*createClone(Scene *scene, Vector2 position, Vector2 direction, Character *parent);
bool						fireBall(Scene * scene, Spell *fireBall);

struct s_spell{
	long			id;
	std::string     image;
	bool			needDir;
	unsigned int    maxCooldown;
	int             manaCost;
	std::vector <GameObject *>	(*display)(Scene *, Character *);
	Spell			*(*create)(Scene *, Vector2, Vector2, Character *);
	bool            (*f)(Scene *, Spell *);
};

enum spell {
	FIREBALL,
	SHIELDWALL
};

static s_spell tab[2] =
{
	{FIREBALL, ":/fireBall.png", true, 1, 10, displayFireBall, createFireBall, fireBall},
	{SHIELDWALL, ":/player.png", true, 3, 10, displayClone, createClone, nullptr}
};

#endif // SCENE_H
