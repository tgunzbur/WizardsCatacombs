#include "main.hpp"

SDL_Window		*window;
SDL_Renderer	*renderer;

int		quit()
{
	if (window)
		SDL_DestroyWindow(window);
	if (renderer)
		SDL_DestroyRenderer(renderer);
	SDL_Quit();
	return (0);
}

int		main(void)
{
	if (SDL_Init(SDL_INIT_VIDEO))
		return (quit());
	if (SDL_CreateWindowAndRenderer(
			SCREENX, SCREENY,
			SDL_WINDOW_SHOWN,
			&window, &renderer))
		return (quit());
	return (quit());
}
