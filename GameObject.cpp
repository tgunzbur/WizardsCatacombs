#include "GameObject.h"

GameObject::GameObject(QPixmap pixmap, Vector2 c_position, int c_id) : QGraphicsPixmapItem ()
{
	setPixmap(pixmap);
	position = c_position;
	id = c_id;
	name = "Game Object";
}

GameObject::GameObject(QPixmap pixmap, Vector2 c_position, int c_id, std::string c_name) : QGraphicsPixmapItem ()
{
	setPixmap(pixmap);
	position = c_position;
	id = c_id;
	name = c_name;
}

Vector2 GameObject::movePosition(Vector2 move)
{
	position += move;
	return (position);
}


Vector2 GameObject::setPosition(Vector2 position)
{
	this->position = position;
	return (this->position);
}

Vector2 GameObject::movePxPosition(Vector2 move)
{
	Vector2	newPosition;

	newPosition.x = int (pos().x()) + move.x;
	newPosition.y = int (pos().y()) + move.y;
	setPos(newPosition.x, newPosition.y);
	return (newPosition);
}

Vector2	GameObject::setPxPosition(Vector2 position)
{
	setPos(position.x, position.y);
	return (position);
}

int		GameObject::setImageSize(int size)
{
	setPixmap(pixmap().scaled(size, size, Qt::KeepAspectRatio));
	return (size);
}

bool	GameObject::isTouched(Vector2 position)
{
	if (this->position == position)
		return (true);
	else
		return (false);
}

bool	GameObject::isGround()
{
	if (id == GROUND || id == STAIR)
		return (true);
	else
		return (false);
}

void    GameObject::print()
{
	std::cout << "Position (in px): " << pos().x()  << ", " << pos().y() << std::endl;
	std::cout << "Position (in case): "; position.print();
}
