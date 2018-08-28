/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector2.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaydont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 13:02:43 by chaydont          #+#    #+#             */
/*   Updated: 2018/08/28 16:23:14 by tgunzbur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

//using namespace std;

Vector2::Vector2(int c_x, int c_y)
{
	x = c_x;
	y = c_y;
}

Vector2 Vector2::operator+=(Vector2 a)
{
	*this = *this + a;
	return (*this);
}

Vector2 Vector2::operator-=(Vector2 a)
{
	*this = *this - a;
	return (*this);
}

void Vector2::print()
{
	std::cout << "X : " << x << "\nY : " << y << std::endl;
}

Vector2 operator+(Vector2 a, Vector2 b)
{
	Vector2 result;

	result.x = a.x + b.x;
	result.y = a.y + b.y;
	return (result);
}

Vector2 operator-(Vector2 a, Vector2 b)
{
	Vector2 result;

	result.x = a.x - b.x;
	result.y = a.y - b.y;
	return (result);
}

bool operator==(Vector2 a, Vector2 b)
{
	return (a.x == b.x && a.y == b.y ? true : false);
}

bool operator!=(Vector2 a, Vector2 b)
{
	return (a == b ? false : true);
}
