#ifndef TEXT_H
#define TEXT_H

#include <QGraphicsTextItem>

#include "GameObject.h"
#include "Vector2.h"

class Text : public QGraphicsTextItem
{
	public:
		Vector2		position;
		GameObject	*parent;
		int			cd;
		int			scale;

		Text(std::string text, Vector2 position, int scale, GameObject *parent, int cd);
};

#endif // TEXT_H
