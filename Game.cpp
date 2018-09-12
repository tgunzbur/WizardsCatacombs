#include "GameObject.h"

Game::Game(QGraphicsScene *c_scene, GameObject *c_player) : QObject(), QGraphicsPixmapItem ()
{
	player = c_player;
	scene = c_scene;
	bossRoom = false;
}

void    Game::update()
{
	this->setFocus();
	if (background[unsigned (player->position.y)][unsigned (player->position.x)]->id == 4)
	{
		deleteBackGround();
		if (bossRoom)
		{
			createBackGround(player->width + 1);
			player->setPosition(0, player->width);
			player->setParam(scene, int (scene->width()), player->width + 1);
		}
		else
		{
			createBackGround(player->width);
			player->setPosition(0, player->width - 1);
			player->setParam(scene, int (scene->width()), player->width);
		}
	}
}

void    Game::createBackGround(int size)
{
	std::vector	<Vector2>		walls;
	std::vector <GameObject *>  vector;
	QPixmap                     groundSprite(":/ground.png");
	QPixmap						groundWithWallSprite(":/groundWithWall.png");
	QPixmap                     wallSprite(":/wall.png");
	QPixmap                     endSprite(":/stairDown.png");
	unsigned long               x;
	unsigned long               y;
	unsigned long				i;
	bool						changeWall;

	for (y = 0; int (y) < size; y++)
	{
		background.push_back(vector);
		for (x = 0; int (x) < size; x++)
		{
			if (int(x) == size - 1 && y == 0)
			{
				background[y].push_back(new GameObject(&endSprite, int (x), int (y), 4));
				background[y][x]->setParam(scene, int (scene->width()), size);
			}
			else
			{
				changeWall = false;
				for (i = 0; i < walls.size(); i++)
				{
					if (int (x) == walls[i].x && int (y) == walls[i].y + 1)
					{
						background[y].push_back(new GameObject(&groundWithWallSprite, int (x), int (y), 2));
						background[y][x]->setParam(scene, int (scene->width()), size);
						changeWall = true;
					}
				}
				if (!changeWall && !(int(x) == 0 && int (y) == size - 1) && rand() % 5 == 0)
				{
					walls.push_back(Vector2(int(x), int (y)));
					background[y].push_back(new GameObject(&wallSprite, int (x), int (y), 3));
					background[y][x]->setParam(scene, int (scene->width()), size);
				}
				else if (!changeWall)
				{
					background[y].push_back(new GameObject(&groundSprite, int (x), int (y), 2));
					background[y][x]->setParam(scene, int (scene->width()), size);
				} 
			}
		}
	}
}

void    Game::deleteBackGround()
{
	unsigned long   x;
	unsigned long   y;
	int             size;

	size = int (background.size());
	for (y = 0; int (y) < size; y++)
	{
		for (x = 0; int (x) < size; x++)
		{
			background[y].pop_back();
		}
		background.pop_back();
	}
}

void    Game::keyPressEvent(QKeyEvent *event)
{
	switch (event->key())
	{
		case Qt::Key_W:
			player->move(0, -1, this);
			break;
		case Qt::Key_S:
			player->move(0, 1, this);
			break;
		case Qt::Key_A:
			player->move(-1, 0, this);
			break;
		case Qt::Key_D:
			player->move(1, 0, this);
			break;
	}
}
