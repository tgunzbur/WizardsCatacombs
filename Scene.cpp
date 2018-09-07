#include "Scene.h"

Scene::Scene(int c_roomSize) : QGraphicsScene ()
{
	roomSize = c_roomSize;
}

GameObject	*Scene::createGameObject(std::string image, Vector2 position, int id)
{
	GameObject	*gameObject;

	gameObject = new GameObject(QPixmap(image.c_str()), position, id);
	addItem(gameObject);
	updateGameObject(gameObject);
	return (gameObject);
}


GameObject	*Scene::updateGameObject(GameObject *gameObject)
{
	Vector2	position;
	int		gameObjectWidth;
	int		screenBorder;

	removeItem(gameObject);
	gameObjectWidth = int (floor(int (width()) / roomSize));
	screenBorder = (int (width()) - gameObjectWidth * roomSize) / 2;
	position.x = screenBorder + gameObject->position.x * gameObjectWidth;
	position.y = screenBorder + gameObject->position.y * gameObjectWidth;
	gameObject->setImageSize(gameObjectWidth);
	gameObject->setPxPosition(position);
	addItem(gameObject);
	return (gameObject);
}

Vector2		Scene::moveGameObject(GameObject *gameObject, Vector2 move)
{
	Vector2	newPosition;
	int	gameObjectWidth;

	gameObjectWidth = int (floor(int (width()) / roomSize));
	newPosition = gameObject->position + move;
	if (isInRoom(newPosition) && background[unsigned (newPosition.y)][unsigned (newPosition.x)]->isGround())
	{
		gameObject->movePosition(move);
		gameObject->movePxPosition(move * gameObjectWidth);
	}
	return (gameObject->position);
}

Vector2		Scene::setGameObject(GameObject *gameObject, Vector2 position)
{
	int	gameObjectWidth;

	gameObjectWidth = int (floor(int (width()) / roomSize));
	gameObject->setPosition(position);
	gameObject->setPxPosition(position * gameObjectWidth);
	return (gameObject->position);
}

void		Scene::createBackGround()
{
	std::vector <GameObject *>	vector;
	Vector2						count;

	for (count.y = 0; count.y < roomSize; count.y++)
	{
		background.push_back(vector);
		for (count.x = 0; count.x < roomSize; count.x++)
		{
			if (count == Vector2(roomSize - 1, 0))
				background[unsigned (count.y)].push_back(
					createGameObject(":/stairDown.png",count, STAIR));
			else if (count != Vector2(0, roomSize -1) && rand() % 10 == 0)
				background[unsigned (count.y)].push_back(
					createGameObject(":/wall.png",count, WALL));
			else if (isUnderWall(count))
				background[unsigned (count.y)].push_back(
					createGameObject(":/groundWithWall.png", count, GROUND));
			else
				background[unsigned (count.y)].push_back(
					createGameObject(":/ground.png", count, GROUND));
		}
	}
}

void		Scene::deleteBackGround()
{
	unsigned long x;
	unsigned long y;

	for (y = 0; int(y) < roomSize; y++)
	{
		for (x = 0; int (x) < roomSize; x++)
		{
			background[y].pop_back();
		}
		background.pop_back();
	}
}

bool		Scene::isInRoom(Vector2 position)
{
	if (position.x >= 0 && position.y >= 0 &&
		position.x < roomSize && position.y < roomSize)
		return (true);
	else
		return (false);
}

bool		Scene::isUnderWall(Vector2 position)
{
	if (position.y - 1 >= 0 &&
		background[unsigned (position.y - 1)][unsigned (position.x)]->id == WALL)
		return (true);
	else
		return (false);
}

void		Scene::keyPressEvent(QKeyEvent *event)
{
	std::cout << "Key Press" << std::endl;
	switch(event->key())
	{
		case Qt::Key_Up:
			moveGameObject(player, Vector2(0, -1));
			break;

		case Qt::Key_Down:
			moveGameObject(player, Vector2(0, 1));
			break;

		case Qt::Key_Left:
			moveGameObject(player, Vector2(-1, 0));
			break;

		case Qt::Key_Right:
			moveGameObject(player, Vector2(1, 0));
			break;
	}
}

void		Scene::game()
{
	if (background[unsigned (player->position.y)]
			[unsigned (player->position.x)]->id == STAIR)
	{
		deleteBackGround();
		createBackGround();
		setGameObject(player, Vector2(0, roomSize - 1));
		updateGameObject(player);
	}
}
