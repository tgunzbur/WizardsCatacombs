#include "GameObject.h"

GameObject::GameObject(std::string c_name, Vector2 c_pos)
{
    name = c_name;
    position = c_pos;
}

void    GameObject::print()
{
    std::cout << "Object name: " << name << std::endl;
    std::cout << "Position: " << std::endl;
    position.print();
}

Vector2 GameObject::Move(Vector2 movement)
{
    position += movement;
    return (position);
}

Vector2 GameObject::setPosition(Vector2 newPosition)
{
    position = newPosition;
    return (position);
}

bool	GameObject::isTouched(Vector2 pos)
{
	return (pos == position ? true : false);
}
