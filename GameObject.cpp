#include "GameObject.h"

GameObject::GameObject(Vector2 c_pos)
{
    position = c_pos;
}

Vector2 GameObject::Move(Vector2 movement)
{
    position += movement;
    return (position);
}

void    GameObject::print()
{
    std::cout << "Object id: " << id << std::endl;
    std::cout << "Position: " << std::endl;
    position.print();
}

void    GameObject::display(QWidget *window)
{
    QLabel  label(window);
    QImage  newImg;

    newImg = image.scaled(this->size, this->size, Qt::KeepAspectRatio);
    label.setGeometry(this->position.x, this->position.y, this->size, this->size);
    label.setPixmap(QPixmap::fromImage(newImg));
}
