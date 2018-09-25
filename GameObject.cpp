#include "GameObject.h"
using namespace std;

GameObject::GameObject(gameObjectId _id, Vector2 _position) : QGraphicsPixmapItem ()
{
	id = _id;
	position = _position;
	setPixmap(QPixmap(gameObjects[id].c_str()));
}

GameObject::GameObject(characterId _id, Vector2 _position) : QGraphicsPixmapItem ()
{
	id = _id;
	position = _position;
	setPixmap(QPixmap(imageName(characters[id].name, DOWN)));
}

Vector2	GameObject::myPosition()
{
	return (position);
}

Vector2 GameObject::movePosition(Vector2 move)
{
	position += move;
	return (position);
}


Vector2 GameObject::setPosition(Vector2 newPosition)
{
	position = newPosition;
	return (newPosition);
}

Vector2 GameObject::movePxPosition(Vector2 move)
{
	Vector2	newPosition;

	newPosition.x = int (pos().x()) + move.x;
	newPosition.y = int (pos().y()) + move.y;
	setPos(newPosition.x, newPosition.y);
	return (newPosition);
}

Vector2	GameObject::setPxPosition(Vector2 newPosition)
{
	setPos(newPosition.x, newPosition.y);
	return (newPosition);
}

bool	GameObject::isGround()
{
	if (id == GROUND || id == WALLGROUND)
		return (true);
	return (false);
}
