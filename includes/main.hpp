#ifndef MAIN_HPP
# define MAIN_HPP

# include "SDL.h"
# include "Vector2.hpp"
# include "GameObject.hpp"
# include "Events.hpp"
# include <vector>
# include <iostream>
# include <fstream>
# include <string>

# define SCREENX 1600
# define SCREENY 900
# define SIZE 64
# define DIRT 0

bool						setTexture(SDL_Renderer *renderer);
SDL_Texture					*getTexture(int id);
std::vector <GameObject *>	createRoom(int size);
bool						display(
		std::vector <GameObject *> background,
		std::vector <GameObject *> objects,
		std::vector <GameObject *> characters);

#endif
