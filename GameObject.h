#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <QGraphicsPixmapItem>
#include <string>

#include "Vector2.h"
#include "define.h"

class GameObject : public QGraphicsPixmapItem
{
	protected:
		int				id;
		Vector2			position;

	public:
		GameObject(gameObjectId _id, Vector2 _position);
		GameObject(characterId _id, Vector2 _position);

		Vector2	myPosition();
		Vector2 movePosition(Vector2 move);
		Vector2 setPosition(Vector2 position);
		Vector2	movePxPosition(Vector2 move);
		Vector2	setPxPosition(Vector2 position);
		bool	isGround();
		bool	isWall();
};

#endif
