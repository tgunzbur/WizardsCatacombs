#ifndef SCENE_H
#define SCENE_H

#include <QGraphicsScene>
#include <QWidget>
#include <QKeyEvent>
#include <QPixmap>
#include <string>

#include "Vector2.h"
#include "GameObject.h"

class	Scene: public QGraphicsScene
{
	Q_OBJECT

	public:
		int	roomSize;
		std::vector <std::vector <GameObject *>>    background;
		GameObject									*player;

		Scene(int c_roomSize);

		GameObject	*createGameObject(std::string image, Vector2 position, int id);
		GameObject	*createCharacter(std::string image, Vector2 position, int id);
		GameObject	*updateGameObject(GameObject *gameObject);
		GameObject	*updateCharacter(GameObject *gameObject);
		Vector2		moveGameObject(GameObject *gameObject, Vector2 move);
		Vector2		setGameObject(GameObject *gameObject, Vector2 position);
		void		createBackGround();
		void		deleteBackGround();
		bool		isInRoom(Vector2 position);
		bool		isUnderWall(Vector2 position);
		void		keyPressEvent(QKeyEvent *event);

	public slots:
		void	game();
};

#endif // SCENE_H
