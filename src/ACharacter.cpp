/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ACharacter.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 13:25:27 by svelhinh          #+#    #+#             */
/*   Updated: 2017/04/09 12:39:21 by nchrupal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ACharacter.hpp"

ACharacter::ACharacter(void)
	: AHitBox(0, 0, 0, 0), _pv(10), _shape(".")
{
}

ACharacter::ACharacter(int pv, int x, int y, int w, int h, const std::string shape)
	: AHitBox(x, y, w, h), _pv(pv), _shape(shape)
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

std::string const ACharacter::getShape(void) const
{
	return _shape;
}

void ACharacter::setPv(int pv_)
{
	_pv = pv_;
}

void	ACharacter::update(void)
{
	mvprintw(_y, _x, _shape.c_str());
}

void	ACharacter::move(int x, int y)
{
	_x = x + _x;
	_y = y + _y;
}

bool	ACharacter::isAlive(void) const
{
	return _pv > 0;
}

ACharacter &	ACharacter::operator=( ACharacter const & rhs )
{
	_pv = rhs.getPv();
	return *this;
}
