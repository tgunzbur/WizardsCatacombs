#ifndef EVENTS_HPP
# define EVENTS_HPP

# include "main.hpp"

class	Events {
	public :
		int		mouseKeys;
		Vector2	mousePos;
		bool	keys[SDL_NUM_SCANCODES];

		Events()
		{
			mouseKeys = 0;
			mousePos.x = 0;
			mousePos.y = 0;
		}
};

#endif
