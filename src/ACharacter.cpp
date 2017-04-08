/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ACharacter.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 13:25:27 by svelhinh          #+#    #+#             */
/*   Updated: 2017/04/08 13:51:20 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ACharacter.hpp"

ACharacter::ACharacter()
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

ACharacter::sPos ACharacter::getPos() const
{
	return pos;
}

ACharacter &	ACharacter::operator=( ACharacter const & rhs )
{
	pv = rhs.getPv();
	pos.x = rhs.getPos().x;
	pos.y = rhs.getPos().y;
	return *this;
}
