#ifndef SCENE_H
#define SCENE_H

#include <QGraphicsScene>
#include <QKeyEvent>

#include "GameObject.h"
#include "Character.h"
#include "Vector2.h"
#include "Text.h"
#include "Pixmap.h"

class	Scene: public QGraphicsScene
{
	Q_OBJECT

	private:
		int		actionPoint;
		int		spellSelected;
		int		roomSize;
		bool	endEnemyTurn;

		Character							*player;
		std::vector <GameObject*>			background;
		std::vector <Character*>			characters;
		std::vector	</*Spell*/GameObject*>	spells;
		std::vector <Text*>					texts;
		std::vector <Pixmap*>				pixmaps;

	public:
		Scene();

		GameObject			*createGameObject(gameObjectId id, Vector2 position);
		Character			*createPlayer(Vector2 position);
		Character			*createCharacter(characterId id, Vector2 position);
		/*Spell*/GameObject	*createSpellGameObject(gameObjectId id, Vector2 position);
		Text				*createText(std::string text, Vector2 position, int scale, GameObject *parent, int cd);
		Pixmap				*createPixmap(std::string image, Vector2 position, Vector2 scale, GameObject *parent, int cd);

		Vector2		moveGameObject(GameObject *gameObject, Vector2 move);
		Vector2		setGameObject(GameObject *gameObject, Vector2 position);
		void		createBackGround();
		void		updateGameObjects(std::vector <GameObject*> myVector);
		void		updateCharacters(std::vector <Character*> myVector);
		void		updateSpells(std::vector </*spell*/GameObject*> myVector);
		void		updateTexts(std::vector <Text*> myVector);
		void		updatePixmaps(std::vector <Pixmap*> myVector);
		void		keyPressEvent(QKeyEvent *event);

		bool		isInRoom(Vector2 position);

	public slots:
		void		Update();
};

#endif // SCENE_H
