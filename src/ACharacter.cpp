/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ACharacter.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 13:25:27 by svelhinh          #+#    #+#             */
/*   Updated: 2017/04/08 14:14:11 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ACharacter.hpp"

ACharacter::ACharacter(): pv(0), x(0), y(0)
{
}

ACharacter::ACharacter(int pv_, int x_, int y_): pv(pv_), x(x_), y(y_)
{
}

ACharacter::ACharacter(ACharacter const & src)
{
	*this = src;
	return;
}

ACharacter::~ACharacter()
{
}

int ACharacter::getPv() const
{
	return pv;
}

int ACharacter::getX() const
{
	return x;
}

int ACharacter::getY() const
{
	return y;
}

ACharacter &	ACharacter::operator=( ACharacter const & rhs )
{
	pv = rhs.getPv();
	x = rhs.getX();
	y = rhs.getY();
	return *this;
}
