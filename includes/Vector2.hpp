/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector2.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaydont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 13:02:31 by chaydont          #+#    #+#             */
/*   Updated: 2018/08/28 14:47:30 by chaydont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Vector2 {
	public:
		int x;
		int y;

	Vector2(int c_x = 0, int c_y = 0);
	Vector2 operator+=(Vector2 a);
	Vector2 operator-=(Vector2 a);
	void	print();
};


	Vector2 operator+(Vector2 a, Vector2 b);
	Vector2 operator-(Vector2 a, Vector2 b);
	bool operator==(Vector2 a, Vector2 b);
	bool operator!=(Vector2 a, Vector2 b);
