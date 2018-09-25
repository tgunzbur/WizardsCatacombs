#ifndef PIXMAP_H
#define PIXMAP_H

#include <QGraphicsPixmapItem>
#include "GameObject.h"
#include "Vector2.h"

class Pixmap : public QGraphicsPixmapItem
{
	public:
		Vector2		position;
		GameObject	*parent;
		int			cd;
		Vector2		scale;

		Pixmap(std::string image, Vector2 position, Vector2 scale, GameObject *parent, int cd);

		void	setScale(Vector2 scale);
};

#endif // PIXMAP_H
