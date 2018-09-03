#include "main.hpp"
using namespace std;
extern SDL_Renderer	*renderer;

bool	drawTexture(SDL_Texture *texture, Vector2 src, Vector2 dst,int size)
{
	int			border;
	SDL_Rect	rectSrc;
	SDL_Rect	rectDst;

	border  =  (SCREENX - (floor((SCREENX - BORDERX) / size) * size)) / 2;
	rectSrc.x = src.x * SIZE;
	rectSrc.y = src.y * SIZE;
	rectSrc.w = SIZE;
	rectSrc.h = SIZE;

	rectDst.x = border + dst.x * floor((SCREENX - BORDERX) / size);
	rectDst.y = border + dst.y * floor((SCREENX - BORDERX) / size) + BORDERY;
	rectDst.w = floor((SCREENX - BORDERX) / size);
	rectDst.h = floor((SCREENX - BORDERX) / size);

	if (SDL_RenderCopy(renderer, texture, &rectSrc, &rectDst) < 0)
		return (false);
	else
		return (true);
}

/*
bool	displayAnimation(GameObject gameObject)
{
	Vector2 src(gameObject.animation.count, 0);

	return (drawTexture(gameObject.animation.texture, src, gameObject.pos));
}
*/

bool	displayTexture(GameObject *gameObject, int size)
{
	Vector2 src(0, 0);

	return (drawTexture(gameObject->texture, src, gameObject->pos, size));
}

bool	displayLayer(vector <GameObject *> layer, int size)
{
	int count;

	for (count = 0; count < layer.size(); count++)
	{
/*		if (layer[count].animation.count >= 0)
		{
			if (!displayAnimation(layer[count], size))
				return (false);
		}
		else
		{
*/			if (!displayTexture(layer[count], size))
				return (false);
//		}
	}
	return (true);
}

bool	display(vector <GameObject *> background,
				vector <GameObject *> objects,
				vector <GameObject *> characters, int size)
{
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
	if (!displayLayer(background, size))
		return (false);
	if (!displayLayer(objects, size))
		return (false);
	if (!displayLayer(characters, size))
		return (false);
	SDL_RenderPresent(renderer);
	return (true);
}
