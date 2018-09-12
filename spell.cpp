#include "GameObject.h"

Spell::Spell(QPixmap pixmap, Vector2 c_position, int c_id, Vector2 c_direction, Character *c_parent) : GameObject(pixmap, c_position, c_id)
{
	direction = c_direction;
	start = c_position;
	parent = c_parent;
}
