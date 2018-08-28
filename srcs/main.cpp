#include "main.hpp"
using namespace std;

SDL_Window				*window;
SDL_Renderer			*renderer;

Events	getEvents(Events events)
{
	SDL_Event event;

	events.mouseKeys = SDL_GetMouseState(&(events.mousePos.x),
										&(events.mousePos.y));
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
			case SDL_KEYDOWN:
				events.keys[event.key.keysym.scancode] = true;
				break;
			case SDL_KEYUP:
				events.keys[event.key.keysym.scancode] = false;
				break;
		}
	}
	return (events);
}

void	game(void)
{
	Events					events;
	vector <GameObject *>	background;
	vector <GameObject *>	objects;
	vector <GameObject *>	characters;
	int						size = 100;

	background = createRoom(size);
	while (!events.keys[SDL_SCANCODE_ESCAPE])
	{
		display(background, objects, characters, size);
		events = getEvents(events);
	}
}

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
	if (!setTexture(renderer))
		return (quit());
	TTF_Init();
	game();
	return (quit());
}
