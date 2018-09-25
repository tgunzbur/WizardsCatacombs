#include "Pixmap.h"

Pixmap::Pixmap(std::string _image, Vector2 _position, Vector2 _scale, GameObject *_parent, int _cd) : QGraphicsPixmapItem ()
{
	setPixmap(QPixmap(_image.c_str()));
	position = _position;
	scale = _scale;
	parent = _parent;
	cd = _cd;
}

void	Pixmap::setScale(Vector2 _scale)
{
	scale = _scale;
}
