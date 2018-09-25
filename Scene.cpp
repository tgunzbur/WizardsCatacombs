#include "Scene.h"
using namespace std;

void	Scene::Update()
{
	setFocus();
	updateGameObjects();
	updateCharacters();
	updateSpells();
	updatePixmaps();
	updateTexts();
	if (changingRoom && int(texts.size()) == 0)
		changingRoom = false;
}

void	Scene::keyPressEvent(QKeyEvent *event)
{
	if (changingRoom)
		return ;
	switch (event->key())
	{

		case Qt::Key_Left:
			if (spellSelected == -1)
				moveGameObject(player, Vector2(-1, 0));
		break;
		case Qt::Key_Right:
			if (spellSelected == -1)
				moveGameObject(player, Vector2(1, 0));
		break;
		case Qt::Key_Up:
			if (spellSelected == -1)
				moveGameObject(player, Vector2(0, -1));
		break;
		case Qt::Key_Down:
			if (spellSelected == -1)
				moveGameObject(player, Vector2(0, 1));
		break;
		case Qt::Key_Q:
			if (spellSelected == 0)
			{
				spellSelected = -1;
			}
			else
			{
				spellSelected = 0;
			}
		break;
		case Qt::Key_W:
			if (spellSelected == 1)
			{
				spellSelected = -1;
			}
			else
			{
				spellSelected = 1;
			}
		break;
		case Qt::Key_E:
			if (spellSelected == 2)
			{
				spellSelected = -1;
			}
			else
			{
				spellSelected = 2;
			}
		break;
		case Qt::Key_R:
			if (spellSelected == 3)
			{
				spellSelected = -1;
			}
			else
			{
				spellSelected = 3;
			}
		break;
	}
}

Scene::Scene() : QGraphicsScene ()
{
	changingRoom = false;
	actionPoint = 2;
	spellSelected = -1;
	roomSize = ROOMSIZE;
	roomNumber = 0;
	endEnemyTurn = false;
}

GameObject			*Scene::createGameObject(gameObjectId id, Vector2 position)
{
	GameObject	*gameObject;

	gameObject = new GameObject(id, position);
	background.push_back(gameObject);
	addItem(gameObject);
	return (gameObject);
}

Character			*Scene::createCharacter(characterId id, Vector2 position)
{
	Character	*character;

	character = new Character(id, position);
	characters.push_back(character);
	addItem(character);
	return (character);
}

Character			*Scene::createPlayer(Vector2 position)
{
	Character	*player;

	player = new Character(PLAYER, position);
	characters.push_back(player);
	this->player = characters[0];
	addItem(player);
	return (player);
}

/*Spell*/GameObject	*Scene::createSpellGameObject(gameObjectId id, Vector2 position)
{
	/*Spell*/GameObject	*spell;

	spell = new /*Spell*/GameObject(id, position);
	spells.push_back(spell);
	addItem(spell);
	return (spell);
}

Text				*Scene::createText(std::string text, Vector2 position, int scale, GameObject *parent, int cd)
{
	Text	*myText;

	myText = new Text(text, position, scale, parent, cd);
	addItem(myText);
	texts.push_back(myText);
	return (myText);
}

Pixmap				*Scene::createPixmap(std::string image, Vector2 position, Vector2 scale, GameObject *parent, int cd)
{
	Pixmap	*pixmap;

	pixmap = new Pixmap(image, position, scale, parent, cd);
	addItem(pixmap);
	pixmaps.push_back(pixmap);
	return (pixmap);
}

void				Scene::createBackGround()
{
	vector <GameObject *>	walls;
	unsigned long			x;
	unsigned long			y;

	for (y = 0; int (y) < roomSize; y++)
	{
		for (x = 0; int (x) < roomSize; x++)
		{
			if (int (x) == roomSize - 1 && y == 0)
			{
				createGameObject(STAIR, Vector2(int (x), int (y)));
			}
			else if (rand() % 10 == 0 && !(x == 0 && int (y) == roomSize - 1))
			{
				if (walls.size() > 0 && walls[0]->myPosition() == Vector2(int (x), int (y) - 1))
					walls.erase(walls.begin());
				walls.push_back(createGameObject(WALL, Vector2(int (x), int (y))));
			}
			else
			{
				if (walls.size() > 0 && walls[0]->myPosition() == Vector2(int (x), int (y) - 1))
				{
					createGameObject(WALLGROUND, Vector2(int (x), int (y)));
					walls.erase(walls.begin());
				}
				else
					createGameObject(GROUND, Vector2(int (x), int (y)));
			}
		}
	}
}

void		Scene::changeRoom()
{
	Text	*text;

	roomNumber++;
	if (roomNumber % 10 == 0)
		roomSize++;
	setGameObject(player, Vector2(0, roomSize - 1));
	while (background.size() != 0)
	{
		removeItem(background[background.size() - 1]);
		background.pop_back();
	}
	while (characters.size() != 1)
	{
		removeItem(characters[characters.size() - 1]);
		characters.pop_back();
	}
	createBackGround();
	changingRoom = true;
	createPixmap(":/changeRoomBg.png", Vector2(0, 0), Vector2(int(width()), int(width())), nullptr, 60);
	text = createText("Room " + std::to_string(roomNumber), Vector2(int (width()) / 5, int(width()) / 4), 5, nullptr, 60);
	text->setDefaultTextColor(QColor(255, 255, 255));
	updatePixmaps();
	updateTexts();
}

Vector2		Scene::moveGameObject(GameObject *gameObject, Vector2 move)
{
	Vector2			position;
	unsigned long	count;

	position = gameObject->myPosition() + move;
	if (isInRoom(position))
	{
		for (count = 0; count < background.size(); count++)
			if (background[count]->myPosition() == position)
			{
				if (!background[count]->isGround())
					return (gameObject->myPosition());
				else
					count = background.size();
			}
		for (count = 0; count < characters.size(); count++)
			if (characters[count]->isAtPos(position))	
				return (gameObject->myPosition());
	}
	else
		return (gameObject->myPosition());
	return (gameObject->movePosition(move));
}

Vector2		Scene::moveGameObject(Character *gameObject, Vector2 move)
{
	Vector2			position;
	unsigned long	count;

	position = gameObject->myPosition() + move;
	if (isInRoom(position))
	{
		for (count = 0; count < background.size(); count++)
			if (background[count]->myPosition() == position)
			{
				if (!background[count]->isGround())
					return (gameObject->myPosition());
				else
					count = background.size();
			}
		for (count = 0; count < characters.size(); count++)
			if (characters[count]->isAtPos(position))
				return (gameObject->myPosition());
	}
	else
		return (gameObject->myPosition());
	position = gameObject->movePosition(move);
	updateCharacters();
	return (position);
}

Vector2		Scene::setGameObject(GameObject *gameObject, Vector2 position)
{
	gameObject->setPosition(position);
	return (position);
}

Vector2		Scene::setGameObject(Character *gameObject, Vector2 position)
{
	gameObject->setPosition(position);
	updateCharacters();
	return (position);
}

bool		Scene::isInRoom(Vector2 position)
{
	if (position.x >= 0 && position.y >= 0 &&
		position.x < roomSize && position.y < roomSize)
		return (true);
	else
		return (false);
}

void	Scene::updateGameObjects()
{
	Vector2			position;
	unsigned long	count;
	int				border;
	int				size;

	size = int (floor(width() / roomSize));
	border = (int (width()) - size * roomSize) / 2;
	for (count = 0; count < background.size(); count++)
	{
		removeItem(background[count]);
		position = background[count]->myPosition();
		position.x = position.x * size + border;
		position.y = position.y * size + border;
		background[count]->setPos(position.x, position.y);
		background[count]->setPixmap(background[count]->pixmap().scaled(size, size));
		addItem(background[count]);
	}
}

void	Scene::updateCharacters()
{
	Vector2			position;
	unsigned long	count;
	int				border;
	int				size;

	size = int (floor(width() / roomSize));
	border = (int (width()) - size * roomSize) / 2;
	if (player)
	{
		for (count = 0; count < background.size(); count++)
		{
			if (player->myPosition() == background[count]->myPosition())
			{
				if (background[count]->isStair())
				{
					changeRoom();
					return ;
				}
				count = background.size();
			}
		}
		removeItem(player);
		position = player->myPosition();
		position.x = position.x * size + border;
		position.y = position.y * size + border;
		player->setPos(position.x, position.y);
		player->setPixmap(player->pixmap().scaled(size, size));
		addItem(player);
	}
	for (count = 0; count < characters.size(); count++)
	{
		removeItem(characters[count]);
		position = characters[count]->myPosition();
		position.x = position.x * size + border;
		position.y = position.y * size + border;
		characters[count]->setPos(position.x, position.y);
		characters[count]->setPixmap(characters[count]->pixmap().scaled(size, size));
		addItem(characters[count]);
	}
}

void	Scene::updateSpells()
{
	Vector2			position;
	unsigned long	count;
	int				border;
	int				size;

	size = int (floor(width() / roomSize));
	border = (int (width()) - size * roomSize) / 2;
	for (count = 0; count < spells.size(); count++)
	{
		removeItem(spells[count]);
		position = spells[count]->myPosition();
		position.x = position.x * size + border;
		position.y = position.y * size + border;
		spells[count]->setPos(position.x, position.y);
		spells[count]->setPixmap(spells[count]->pixmap().scaled(size, size));
		addItem(spells[count]);
	}
}

void	Scene::updateTexts()
{
	Vector2			position;
	unsigned long	count;
	int				border;
	int				size;

	size = int (floor(width() / roomSize));
	border = (int (width()) - size * roomSize) / 2;
	for (count = 0; count < texts.size(); count++)
	{
		removeItem(texts[count]);
		texts[count]->setScale(texts[count]->scale);
		position = texts[count]->position;
		if (texts[count]->parent != nullptr)
		{
			position += texts[count]->parent->myPosition();
			position.x = position.x * size + border;
			position.y = position.y * size + border;
			texts[count]->setPos(position.x, position.y);
		}
		else
		{
			texts[count]->setPos(position.x + border, position.y + border);
		}
		addItem(texts[count]);
		if (texts[count]->cd > 0)
			texts[count]->cd--;
		if (texts[count]->cd == 0)
		{
			removeItem(texts[count]);
			texts.erase(texts.begin() + int (count));
			count--;
		}
	}
}

void	Scene::updatePixmaps()
{
	Vector2			position;
	unsigned long	count;
	int				border;
	int				size;

	size = int (floor(width() / roomSize));
	border = (int (width()) - size * roomSize) / 2;
	for (count = 0; count < pixmaps.size(); count++)
	{
		removeItem(pixmaps[count]);
		pixmaps[count]->setPixmap(pixmaps[count]->pixmap().scaled(pixmaps[count]->scale.x,pixmaps[count]->scale.y));
		position = pixmaps[count]->position;
		if (pixmaps[count]->parent != nullptr)
		{
			position += pixmaps[count]->parent->myPosition();
			position.x = position.x * size + border;
			position.y = position.y * size + border;
			pixmaps[count]->setPos(position.x, position.y);
		}
		else
		{
			pixmaps[count]->setPos(position.x + border, position.y + border);
		}
		addItem(pixmaps[count]);
		if (pixmaps[count]->cd > 0)
			pixmaps[count]->cd--;
		if (pixmaps[count]->cd == 0)
		{
			removeItem(pixmaps[count]);
			pixmaps.erase(pixmaps.begin() + int (count));
			count--;
		}
	}
}
