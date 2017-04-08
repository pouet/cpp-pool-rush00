/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ACharacter.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 13:25:27 by svelhinh          #+#    #+#             */
/*   Updated: 2017/04/08 17:09:23 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ACharacter.hpp"

ACharacter::ACharacter(void): pv(0), x(0), y(0), shape(".")
{
}

ACharacter::ACharacter(int pv_, int x_, int y_, const std::string shape_): pv(pv_), x(x_), y(y_), shape(shape_)
{
}

ACharacter::ACharacter(ACharacter const & src)
{
	*this = src;
	return;
}

ACharacter::~ACharacter(void)
{
}

int ACharacter::getPv(void) const
{
	return pv;
}

int ACharacter::getX(void) const
{
	return x;
}

int ACharacter::getY(void) const
{
	return y;
}

std::string const ACharacter::getShape(void) const
{
	return shape;
}

void ACharacter::setPv(int pv_)
{
	pv = pv_;
}

void ACharacter::setX(int x_)
{
	x = x_;
}

void ACharacter::setY(int y_)
{
	y = y_;
}

void	ACharacter::update(void)
{
	mvprintw(x, y, shape.c_str());
}

ACharacter &	ACharacter::operator=( ACharacter const & rhs )
{
	pv = rhs.getPv();
	x = rhs.getX();
	y = rhs.getY();
	return *this;
}
