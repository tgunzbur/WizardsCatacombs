#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QImage>
#include <vector>
#include <QObject>

#include "define.h"
#include "Vector2.h"

class Game;

class GameObject : public QGraphicsPixmapItem
{
    public:
        Vector2 position;
		int     id;

		GameObject(QPixmap pixmap, Vector2 c_position, int c_id);

		Vector2 movePosition(Vector2 move);
		Vector2 setPosition(Vector2 position);
		Vector2	movePxPosition(Vector2 move);
		Vector2	setPxPosition(Vector2 position);
		int		setImageSize(int size);

		bool	isGround();
        void    print();
};

#endif
