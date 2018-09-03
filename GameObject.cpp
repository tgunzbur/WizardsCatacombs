#include "GameObject.h"

GameObject::GameObject(QImage c_img, Vector2 c_pos, int c_size)
{
    label = new QLabel;
    image = c_img;
    position = c_pos;
    size = c_size;
}

Vector2 GameObject::Move(Vector2 movement)
{
    position += movement;
    return (position);
}

void    GameObject::print()
{
    std::cout << "Object id: " << id << std::endl;
    std::cout << "Position: ";
    position.print();
}

void    GameObject::display(QWidget *window)
{
    QImage  newImg;

    newImg = image.scaled(size, size, Qt::KeepAspectRatio);
    label->setPixmap(QPixmap::fromImage(newImg));
    label->setGeometry(position.x, position.y, size, size);
    label->setParent(window);
}
