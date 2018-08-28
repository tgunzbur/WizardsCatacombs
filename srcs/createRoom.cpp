#include "main.hpp"
using namespace std;

vector <GameObject *>	createRoom(int size)
{
	vector <GameObject *> background;
	Vector2	count;

	for (count.y = 0; count.y < size; count.y++)
	{
		for (count.x = 0; count.x < size; count.x++)
		{
			background.push_back(new GameObject(count, DIRT));
		}
	}
	return (background);
}
