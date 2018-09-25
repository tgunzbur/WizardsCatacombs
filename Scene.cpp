#include "Scene.h"
using namespace std;

void	Scene::Update()
{
	setFocus();
	updateGameObjects(background);
	updateCharacters(characters);
	updateSpells(spells);
	updatePixmaps(pixmaps);
	updateTexts(texts);
}

void	Scene::keyPressEvent(QKeyEvent *event)
{
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
	actionPoint = 2;
	spellSelected = -1;
	roomSize = ROOMSIZE;
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
			if (rand() % 10 == 0)
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

Vector2		Scene::moveGameObject(GameObject *gameObject, Vector2 move)
{
	Vector2			position;
	unsigned long	count;

	position = gameObject->myPosition() + move;
	if (isInRoom(position) && background[unsigned (position.y * roomSize + position.x)]->isGround())
	{
		for (count = 0; count < characters.size(); count++)
			if (characters[count]->isAtPos(position))	
				return (gameObject->myPosition());
	}
	else
		return (gameObject->myPosition());
	return (gameObject->movePosition(move));
}

Vector2		Scene::setGameObject(GameObject *gameObject, Vector2 position)
{
	gameObject->setPosition(position);
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

void	Scene::updateGameObjects(vector <GameObject*> myVector)
{
	Vector2			position;
	unsigned long	count;
	int				border;
	int				size;

	size = int (floor(width() / roomSize));
	border = (int (width()) - size * roomSize) / 2;
	for (count = 0; count < myVector.size(); count++)
	{
		removeItem(myVector[count]);
		position = myVector[count]->myPosition();
		position.x = position.x * size + border;
		position.y = position.y * size + border;
		myVector[count]->setPos(position.x, position.y);
		myVector[count]->setPixmap(myVector[count]->pixmap().scaled(size, size));
		addItem(myVector[count]);
	}
}

void	Scene::updateCharacters(vector <Character*> myVector)
{
	Vector2			position;
	unsigned long	count;
	int				border;
	int				size;

	size = int (floor(width() / roomSize));
	border = (int (width()) - size * roomSize) / 2;
	if (player)
	{
		removeItem(player);
		position = player->myPosition();
		position.x = position.x * size + border;
		position.y = position.y * size + border;
		player->setPos(position.x, position.y);
		player->setPixmap(player->pixmap().scaled(size, size));
		addItem(player);
	}
	for (count = 0; count < myVector.size(); count++)
	{
		removeItem(myVector[count]);
		position = myVector[count]->myPosition();
		position.x = position.x * size + border;
		position.y = position.y * size + border;
		myVector[count]->setPos(position.x, position.y);
		myVector[count]->setPixmap(myVector[count]->pixmap().scaled(size, size));
		addItem(myVector[count]);
	}
}

void	Scene::updateSpells(vector </*spell*/GameObject*> myVector)
{
	Vector2			position;
	unsigned long	count;
	int				border;
	int				size;

	size = int (floor(width() / roomSize));
	border = (int (width()) - size * roomSize) / 2;
	for (count = 0; count < myVector.size(); count++)
	{
<<<<<<< HEAD
		removeItem(myVector[count]);
		position = myVector[count]->myPosition();
		position.x = position.x * size + border;
		position.y = position.y * size + border;
		myVector[count]->setPos(position.x, position.y);
		myVector[count]->setPixmap(myVector[count]->pixmap().scaled(size, size));
		addItem(myVector[count]);
=======
		case Qt::Key_Up:
			if (spellSelect < 0)
				moveGameObject(characters[0], Vector2(0, -1));
			else
			{
				tab[unsigned (characters[0]->spells[spellSelect])].create(this, characters[0]->position, Vector2(0, -1), characters[0]);
				characters[0]->spellsCd[spellSelect] = int (tab[characters[0]->spells[spellSelect]].maxCooldown);
			}
			pa--;
			spellSelect = -1;
			deleteSpellDisplay();
			break;

		case Qt::Key_Down:
			if (spellSelect < 0)
				moveGameObject(characters[0], Vector2(0, 1));
			else
			{
				tab[unsigned (characters[0]->spells[spellSelect])].create(this, characters[0]->position, Vector2(0, 1), characters[0]);
				characters[0]->spellsCd[spellSelect] = int (tab[characters[0]->spells[spellSelect]].maxCooldown);
			}
			pa--;
			spellSelect = -1;
			deleteSpellDisplay();
			break;

		case Qt::Key_Left:
			if (spellSelect < 0)
				moveGameObject(characters[0], Vector2(-1, 0));
			else
			{
				tab[unsigned (characters[0]->spells[spellSelect])].create(this, characters[0]->position, Vector2(-1, 0), characters[0]);
				characters[0]->spellsCd[spellSelect] = int (tab[characters[0]->spells[spellSelect]].maxCooldown);
			}
			pa--;
			spellSelect = -1;
			deleteSpellDisplay();
			break;

		case Qt::Key_Right:
			if (spellSelect < 0)
				moveGameObject(characters[0], Vector2(1, 0));
			else
			{
				tab[unsigned (characters[0]->spells[spellSelect])].create(this, characters[0]->position, Vector2(1, 0), characters[0]);
				characters[0]->spellsCd[spellSelect] = int (tab[characters[0]->spells[spellSelect]].maxCooldown);
			}
			pa--;
			spellSelect = -1;
			deleteSpellDisplay();
			break;

		case Qt::Key_Q:
			deleteSpellDisplay();
			if (spellSelect != 0)
			{
				if (characters[0]->spellsCd[0] <= 0 && characters[0]->currentMana >= tab[characters[0]->spells[0]].manaCost)
				{
					spellSelect = 0;
					spellDisplay = tab[unsigned (characters[0]->spells[spellSelect])].display(this, characters[0]);
				}
			}
			else
				spellSelect = -1;
			break;

		case Qt::Key_W:
			deleteSpellDisplay();
			if (spellSelect != 1)
			{
				if (characters[0]->spellsCd[1] <= 0 && characters[0]->currentMana >= tab[characters[0]->spells[1]].manaCost)
				{
					spellSelect = 1;
					spellDisplay = tab[unsigned (characters[0]->spells[spellSelect])].display(this, characters[0]);
				}
			}
			else
				spellSelect = -1;
			break;

		case Qt::Key_E:
			deleteSpellDisplay();
			if (spellSelect != 2)
			{
				if (characters[0]->spellsCd[2] <= 0 && characters[0]->currentMana >= tab[characters[0]->spells[2]].manaCost)
				{
					spellSelect = 2;
					spellDisplay = tab[unsigned (characters[0]->spells[spellSelect])].display(this, characters[0]);
				}
			}
			else
				spellSelect = -1;
			break;

		case Qt::Key_R:
			deleteSpellDisplay();
			if (spellSelect != 3)
			{
				if (characters[0]->spellsCd[3] <= 0 && characters[0]->currentMana >= tab[characters[0]->spells[3]].manaCost)
				{
					spellSelect = 3;
					spellDisplay = tab[unsigned (characters[0]->spells[spellSelect])].display(this, characters[0]);
				}
			}
			else
				spellSelect = -1;
			break;
>>>>>>> 697009d9aabe194a6158e511d8b3211a1529e987
	}
}

void	Scene::updateTexts(vector <Text*> myVector)
{
	Vector2			position;
	unsigned long	count;
	int				border;
	int				size;

	size = int (floor(width() / roomSize));
	border = (int (width()) - size * roomSize) / 2;
	for (count = 0; count < myVector.size(); count++)
	{
		removeItem(myVector[count]);
		myVector[count]->setScale(myVector[count]->scale);
		position = myVector[count]->parent->myPosition();
		if (myVector[count]->parent != nullptr)
		{
			position.x = position.x * size + border;
			position.y = position.y * size + border;
			myVector[count]->setPos(position.x, position.y);
		}
		else
		{
			myVector[count]->setPos(position.x + border, position.y + border);
		}
		addItem(myVector[count]);
		if (myVector[count]->cd > 0)
			myVector[count]->cd--;
		if (myVector[count]->cd == 0)
		{
<<<<<<< HEAD
			removeItem(myVector[count]);
			myVector.erase(myVector.begin() + int (count));
			count--;
=======
			if (characters[i]->id == PLAYERCLONE)
				characters[0]->changeMana(40);
			removeItem(texts[0]);
			texts.erase(texts.begin());
			removeItem(characters[i]);
			characters.erase(characters.begin() + int (i));
			i--;
>>>>>>> 697009d9aabe194a6158e511d8b3211a1529e987
		}
	}
}

void	Scene::updatePixmaps(vector <Pixmap*> myVector)
{
	Vector2			position;
	unsigned long	count;
	int				border;
	int				size;

	size = int (floor(width() / roomSize));
	border = (int (width()) - size * roomSize) / 2;
	for (count = 0; count < myVector.size(); count++)
	{
		removeItem(myVector[count]);
		myVector[count]->setPixmap(myVector[count]->pixmap().scaled(size * myVector[count]->scale.x, size * myVector[count]->scale.y));
		if (myVector[count]->parent != nullptr)
		{
			position = myVector[count]->parent->myPosition();
			position.x = position.x * size + border;
			position.y = position.y * size + border;
			myVector[count]->setPos(position.x, position.y);
		}
		addItem(myVector[count]);
		if (myVector[count]->cd > 0)
			myVector[count]->cd--;
		if (myVector[count]->cd == 0)
		{
			removeItem(myVector[count]);
			myVector.erase(myVector.begin() + int (count));
			count--;
		}
	}
}
