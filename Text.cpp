#include "Text.h"

Text::Text(std::string _text, Vector2 _position, int _scale, GameObject *_parent, int _cd) : QGraphicsTextItem ()
{
	setPlainText(QString::fromStdString(_text));
	position = _position;
	scale = _scale;
	parent = _parent;
	cd = _cd;
}
