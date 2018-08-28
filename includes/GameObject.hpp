/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameObject.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaydont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 14:57:49 by chaydont          #+#    #+#             */
/*   Updated: 2018/08/28 16:23:49 by tgunzbur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAMEOBJECT_HPP
# define GAMEOBJECT_HPP

#include "main.hpp"

class GameObject {
	public:
	Vector2 pos;
	SDL_Texture *texture;
	GameObject(Vector2 c_pos, int c_id);

	private:
	int id;
};

#endif
