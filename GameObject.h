#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QImage>
#include <vector>
#include <QObject>

#include "define.h"
#include "Vector2.h"

class GameObject : public QGraphicsPixmapItem
{
    public:
		Vector2		position;
		std::string	name;
		int			id;

		GameObject(QPixmap pixmap, Vector2 c_position, int c_id);
		GameObject(QPixmap pixmap, Vector2 c_position, int c_id, std::string c_name);
		Vector2 movePosition(Vector2 move);
		Vector2 setPosition(Vector2 position);
		Vector2	movePxPosition(Vector2 move);
		Vector2	setPxPosition(Vector2 position);
		int		setImageSize(int size);
		bool	isTouched(Vector2 pos);
		bool	isGround();
		void    print();
};

class Character: public GameObject
{
    public:
		int					currentHealth;
		int					currentMana;
		int					maxHealth;
		int					maxMana;
		int					text;
		int					cdText;
		int					spells[4];

		Character(QPixmap pixmap, Vector2 c_position, int c_id,
				  std::string c_name, int c_maxHealth, int c_maxMana);
        int     changeHealth(int value);
		int     changeMana(int value);
		void    print();
};

class Spell: public GameObject
{
	public:
		Character	*parent;
		Vector2		direction;
		Vector2		start;

		Spell(QPixmap pixmap, Vector2 c_position, int c_id, Vector2 c_direction, Character *c_parent);

};

#endif
