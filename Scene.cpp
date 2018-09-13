#include "Scene.h"

Scene::Scene(int c_roomSize) : QGraphicsScene ()
{
	spellSelect = -1;
	aiLaunch = false;
	pa = 2;
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

Character	*Scene::createCharacter(std::string image, Vector2 position, int id, std::string name, int maxHealth, int maxMana, bool gotLifeBar)
{
	Character	*character;
	GameObject	*lifeBar = nullptr;
	int	gameObjectWidth = int (floor(int (width()) / roomSize));
	int	screenBorder = (int (width()) - gameObjectWidth * roomSize) / 2;

	if (gotLifeBar)
	{
		lifeBar = new GameObject(QPixmap(":/healthBar.png"), position, 0);
		lifeBar->setPos(screenBorder + position.x * gameObjectWidth + gameObjectWidth / 4, screenBorder + position.y * gameObjectWidth);
		lifeBar->setPixmap(lifeBar->pixmap().scaled(gameObjectWidth / 2, 5, Qt::IgnoreAspectRatio));
		addItem(lifeBar);
	}
	character = new Character(QPixmap(image.c_str()), position, id, name, maxHealth, maxMana, lifeBar);
	addItem(character);
	updateGameObject(character);
	return (character);
}

Spell		*Scene::createSpell(std::string image, Vector2 position, int id, Vector2 direction, Character *parent)
{
	Spell	*spell;

	spell = new Spell(QPixmap(image.c_str()), position, id, direction, parent);
	addItem(spell);
	updateGameObject(spell);
	return (spell);
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
		for (unsigned long j = 0; j < characters.size(); j++)
		{
			if (characters[j]->isTouched(gameObject->position + move))
				return (gameObject->position);
		}
		gameObject->movePosition(move);
		gameObject->movePxPosition(move * gameObjectWidth);
	}
	return (gameObject->position);
}

Vector2		Scene::setGameObject(GameObject *gameObject, Vector2 position)
{
	int	gameObjectWidth;
	int	screenBorder;

	gameObjectWidth = int (floor(int (width()) / roomSize));
	screenBorder = (int (width()) - gameObjectWidth * roomSize) / 2;
	gameObject->setPosition(position);
	position.x = screenBorder + position.x * gameObjectWidth;
	position.y = screenBorder + position.y * gameObjectWidth;
	gameObject->setPxPosition(position);
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

void		Scene::createUi()
{
	Vector2	pos = Vector2(20, int (width()) + 20);
	Vector2	size = Vector2(int (width()) - 40, 20);

	GameObject	*manaBar = new GameObject(QPixmap(":/manaBar.png"), pos, 0);
	GameObject	*healthBar = new GameObject(QPixmap(":/healthBar.png"), pos - Vector2(0, 20), 1);
	manaBar->setPos(pos.x, pos.y);
	healthBar->setPos(pos.x, pos.y - 20);
	manaBar->setPixmap(manaBar->pixmap().scaled(size.x, size.y, Qt::IgnoreAspectRatio));
	healthBar->setPixmap(healthBar->pixmap().scaled(size.x, size.y, Qt::IgnoreAspectRatio));
	UI.push_back(manaBar);
	UI.push_back(healthBar);
	addItem(UI[0]);
	addItem(UI[1]);
}

void		Scene::changeMana(Character *player)
{
	Vector2	size = Vector2(int (width()) - 40, 20);

	removeItem(UI[0]);
	UI[0]->setPixmap(UI[0]->pixmap().scaled(size.x * player->currentMana / player->maxMana, size.y, Qt::IgnoreAspectRatio));
	addItem(UI[0]);
}

void		Scene::changeLife(Character	*player)
{
	Vector2	size = Vector2(int (width()) - 40, 20);

	removeItem(UI[1]);
	UI[1]->setPixmap(UI[1]->pixmap().scaled(size.x * player->currentHealth / player->maxHealth, size.y, Qt::IgnoreAspectRatio));
	addItem(UI[1]);
}

void		Scene::updateLife(Character *character)
{
	Vector2	size = Vector2(int (floor(width() / roomSize)) / 2, 5);
	int	gameObjectWidth;
	int	screenBorder;

	gameObjectWidth = int (floor(int (width()) / roomSize));
	screenBorder = (int (width()) - gameObjectWidth * roomSize) / 2;
	removeItem(character->lifeBar);
	character->lifeBar->setPos(screenBorder + character->position.x * gameObjectWidth + gameObjectWidth / 4, screenBorder + character->position.y * gameObjectWidth);
	character->lifeBar->setPixmap(character->lifeBar->pixmap().scaled(size.x * character->currentHealth / character->maxHealth, size.y, Qt::IgnoreAspectRatio));
	addItem(character->lifeBar);
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

void		Scene::deleteCharacters()
{
	unsigned long	i;

	for (i = 0; characters.size() != 1; i++)
	{
		removeItem(characters[characters.size() - 1]);
		characters.pop_back();
	}
}

void		Scene::deleteSpells()
{
	unsigned long	i;

	for (i = 0; spells.size() != 0; i++)
	{
		removeItem(spells[spells.size() - 1]);
		spells.pop_back();
	}
}

void		Scene::deleteTexts()
{
	unsigned long	i;

	for (i = 0; texts.size() != 0; i++)
	{
		removeItem(texts[texts.size() - 1]);
		texts.pop_back();
	}
}

void		Scene::deleteSpellDisplay()
{
	unsigned long	i;

	for (i = 0; spellDisplay.size() != 0; i++)
	{
		removeItem(spellDisplay[spellDisplay.size() - 1]);
		spellDisplay.pop_back();
	}
}

void		Scene::deleteVectors()
{
	deleteBackGround();
	deleteCharacters();
	deleteSpells();
	deleteTexts();
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

void		Scene::launchAi()
{
	for (unsigned long i = 1; i < characters.size(); i++)
	{
		if (characters[i]->id == SKELETON)
			skeletonAi(this, characters[i]);
	}
}

void		skeletonAi(Scene *scene, Character *skeleton)
{
	Vector2	dir;
	bool	stop;

	stop = false;
	dir = scene->characters[0]->position - skeleton->position;
	dir.x = dir.x == 0 ? 0 : dir.x / abs(dir.x);
	dir.y = dir.y == 0 ? 0 : dir.y / abs(dir.y);
	if (dir.x != 0)
		dir.y = 0;
	dir.print();
	scene->spellDisplay = displayFireBall(scene, skeleton);
	for (unsigned long i = 0; i < scene->spellDisplay.size() && stop == false; i++)
	{
		for (unsigned long j = 0; j < scene->characters.size() && stop == false; j++)
		{
			if (scene->spellDisplay[i]->isTouched(scene->characters[j]->position) &&
				(scene->characters[j]->id == PLAYER || scene->characters[j]->id == PLAYERCLONE))
			{
				createFireBall(scene, skeleton->position, dir, skeleton);
				stop = true;
			}
		}
	}
	scene->deleteSpellDisplay();
	if (skeleton->position + dir != scene->characters[0]->position && !stop)
		scene->moveGameObject(skeleton, dir);
}

void		Scene::keyPressEvent(QKeyEvent *event)
{
	if (pa <= 0)
		return ;
	switch(event->key())
	{
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
			if (spellSelect != 0)
			{
				if (characters[0]->spellsCd[0] <= 0 && characters[0]->currentMana >= tab[characters[0]->spells[0]].manaCost)
				{
					spellSelect = 0;
					spellDisplay = tab[unsigned (characters[0]->spells[spellSelect])].display(this, characters[0]);
				}
			}
			else
			{
				spellSelect = -1;
				deleteSpellDisplay();
			}
			break;

		case Qt::Key_W:
			if (spellSelect != 1)
			{
				if (characters[0]->spellsCd[1] <= 0 && characters[0]->currentMana >= tab[characters[0]->spells[1]].manaCost)
				{
					spellSelect = 1;
					spellDisplay = tab[unsigned (characters[0]->spells[spellSelect])].display(this, characters[0]);
				}
			}
			else
			{
				spellSelect = -1;
				deleteSpellDisplay();
			}
			break;

		case Qt::Key_E:
			if (spellSelect != 2)
			{
				if (characters[0]->spellsCd[2] <= 0 && characters[0]->currentMana >= tab[characters[0]->spells[2]].manaCost)
				{
					spellSelect = 2;
					spellDisplay = tab[unsigned (characters[0]->spells[spellSelect])].display(this, characters[0]);
				}
			}
			else
			{
				spellSelect = -1;
				deleteSpellDisplay();
			}
			break;

		case Qt::Key_R:
			if (spellSelect != 3)
			{
				if (characters[0]->spellsCd[3] <= 0 && characters[0]->currentMana >= tab[characters[0]->spells[3]].manaCost)
				{
					spellSelect = 3;
					spellDisplay = tab[unsigned (characters[0]->spells[spellSelect])].display(this, characters[0]);
				}
			}
			else
			{
				spellSelect = -1;
				deleteSpellDisplay();
			}
			break;
	}
}

void		Scene::game()
{
	static int	count = 0;

	if (count == 6)
	{
		for (unsigned long i = 0; i < spells.size(); i++)
		{
			if (spells[i]->id == FIREBALL)
			{
				if (!fireBall(this, spells[i]))
				{
					removeItem(spells[i]);
					spells.erase(spells.begin() + int (i));
				}
			}
		}
		for (unsigned long i = 0; i < characters.size(); i++)
		{
			if (characters[i]->text)
			{
				if (characters[i]->cdText == 0)
				{
					texts.push_back(addText(QString::number(characters[i]->text)));
					texts[texts.size() - 1]->setPos(characters[i]->pos() + QPoint(26, -30));
					if (characters[i]->text >= 0)
						texts[texts.size() - 1]->setDefaultTextColor(QColor(0, 255, 0));
					else
						texts[texts.size() - 1]->setDefaultTextColor(QColor(255, 0, 0));
					characters[i]->cdText++;
				}
				else if (characters[i]->cdText == 5)
				{
					removeItem(texts[0]);
					texts.erase(texts.begin());
					characters[i]->text = 0;
					characters[i]->cdText = 0;
				}
				else if (characters[i]->cdText < 5)
				{
					characters[i]->cdText++;
				}
			}
		}
		count = 0;
	}
	changeMana(characters[0]);
	changeLife(characters[0]);
	for (unsigned long i = 0; i < characters.size(); i++)
	{
		if (characters[i]->lifeBar)
			updateLife(characters[i]);
		if (characters[i]->currentHealth == 0)
		{
			if (characters[i]->id == PLAYERCLONE)
				characters[0]->changeMana(40);
			removeItem(characters[i]);
			characters.erase(characters.begin() + int (i));
		}
	}
	if (background[unsigned (characters[0]->position.y)]
			[unsigned (characters[0]->position.x)]->id == STAIR)
	{
		deleteVectors();
		createBackGround();
		setGameObject(characters[0], Vector2(0, roomSize - 1));
		updateGameObject(characters[0]);
	}
	if (spells.size() == 0 && texts.size() == 0 && pa <= 0)
	{
		if (!aiLaunch)
		{
			launchAi();
			aiLaunch = true;
		}
		else
		{
			for (int i = 0; unsigned (i) < characters.size(); i++)
			{
				for (unsigned long j = 0; j < 4; j++)
				{
					if (characters[unsigned (i)]->spellsCd[j] > 0)
						characters[unsigned (i)]->spellsCd[j]--;
				}
				if (characters[unsigned (i)]->id == PLAYERCLONE)
				{
					removeItem(characters[unsigned (i)]);
					characters.erase(characters.begin() + int (i));
					i--;
				}
			}
			pa = 2;
			aiLaunch = false;
		}
	}
	count++;
}
