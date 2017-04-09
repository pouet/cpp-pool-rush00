/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ACharacter.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 13:25:27 by svelhinh          #+#    #+#             */
/*   Updated: 2017/04/09 09:49:05 by nchrupal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ACharacter.hpp"

ACharacter::ACharacter(void): _pv(10), _x(0), _y(0), _shape(".")
{
}

ACharacter::ACharacter(int pv_, int x_, int y_, const std::string shape_): _pv(pv_), _x(x_), _y(y_), _shape(shape_)
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
	return _pv;
}

int ACharacter::getX(void) const
{
	return _x;
}

int ACharacter::getY(void) const
{
	return _y;
}

std::string const ACharacter::getShape(void) const
{
	return _shape;
}

void ACharacter::setPv(int pv_)
{
	_pv = pv_;
}

void ACharacter::setX(int x_)
{
	_x = x_;
}

void ACharacter::setY(int y_)
{
	_y = y_;
}

void	ACharacter::update(void)
{
	mvprintw(_x, _y, _shape.c_str());
}

bool	ACharacter::isAlive(void) const
{
	return _pv <= 0;
}

ACharacter &	ACharacter::operator=( ACharacter const & rhs )
{
	_pv = rhs.getPv();
	_x = rhs.getX();
	_y = rhs.getY();
	return *this;
}
