#include "main.hpp"
using namespace std;
extern SDL_Renderer	*renderer;

bool	drawTexture(SDL_Texture *texture, Vector2 src, Vector2 dst)
{
	SDL_Rect rectSrc;
	SDL_Rect rectDst;

	rectSrc.x = src.x * SIZE;
	rectSrc.y = src.y * SIZE;
	rectSrc.w = SIZE;
	rectSrc.h = SIZE;

	rectDst.x = dst.x * SIZE;
	rectDst.y = dst.y * SIZE;
	rectDst.w = SIZE;
	rectDst.h = SIZE;

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

bool	displayTexture(GameObject *gameObject)
{
	Vector2 src(0, 0);

	return (drawTexture(gameObject->texture, src, gameObject->pos));
}

bool	displayLayer(vector <GameObject *> layer)
{
	int count;

	for (count = 0; count < layer.size(); count++)
	{
/*		if (layer[count].animation.count >= 0)
		{
			if (!displayAnimation(layer[count]))
				return (false);
		}
		else
		{
*/			if (!displayTexture(layer[count]))
				return (false);
//		}
	}
	return (true);
}

bool	display(vector <GameObject *> background,
				vector <GameObject *> objects,
				vector <GameObject *> characters)
{
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
	if (!displayLayer(background))
		return (false);
	if (!displayLayer(objects))
		return (false);
	if (!displayLayer(characters))
		return (false);
	SDL_RenderPresent(renderer);
	return (true);
}
