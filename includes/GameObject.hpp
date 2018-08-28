/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameObject.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaydont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 14:57:49 by chaydont          #+#    #+#             */
/*   Updated: 2018/08/28 15:51:16 by chaydont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sdl/include/SDL2/SDL.h"
#include <iostream>
#include "Vector2.hpp"

class GameObject {
	public:
	Vector2 pos;
	SDL_Texture *texture;

	private:
	int ID;
};
