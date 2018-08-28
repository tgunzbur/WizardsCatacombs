#include "main.hpp"
using namespace std;

vector <SDL_Texture *>	textures;

bool		setTexture(SDL_Renderer *renderer)
{
	SDL_Surface	*surface;
	ifstream	file;
	string		line;

	file.open("data/textures.data", ios::in);
	if (!file.is_open())
		return (false);
	while (getline(file, line))
	{
		if (!(surface = SDL_LoadBMP(("data/textures/" + line + ".bmp").c_str())))
			return (false);
		SDL_SetColorKey(surface, SDL_RLEACCEL | SDL_TRUE,
						SDL_MapRGB(surface->format, 0xFF, 0x00, 0xBB));
		textures.push_back(SDL_CreateTextureFromSurface(renderer, surface));
		SDL_FreeSurface(surface);
	}
	file.close();
	return (true);
}

SDL_Texture	*getTexture(int id)
{
	if (textures.size() > id)
		return (textures[id]);
	else
		return (NULL);
}
