#include "main.hpp"

GameObject::GameObject(Vector2 c_pos, int c_id)
{
	pos = c_pos;
	id = c_id;
	texture = getTexture(id);
}
