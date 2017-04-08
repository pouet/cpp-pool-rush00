/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ACharacter.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 13:25:27 by svelhinh          #+#    #+#             */
/*   Updated: 2017/04/08 14:29:13 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ACharacter.hpp"

ACharacter::ACharacter(void): pv(0), x(0), y(0)
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

ACharacter &	ACharacter::operator=( ACharacter const & rhs )
{
	pv = rhs.getPv();
	x = rhs.getX();
	y = rhs.getY();
	return *this;
}
