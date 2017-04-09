/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 13:25:27 by svelhinh          #+#    #+#             */
/*   Updated: 2017/04/09 14:08:55 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Player.hpp"
#include "Game.hpp"

Player::Player(void)
	: ACharacter(1, 1, 1, 2, 1, "=>"), _lifes(3)
{
}

Player::Player(int pv, int x, int y, int lifes_)
	: ACharacter(pv, x, y, 2, 1, "=>"), _lifes(lifes_)
{
}

Player::Player(Player const & src)
{
	*this = src;
	return;
}

Player::~Player(void)
{
}

int	Player::getLifes(void) const
{
	return _lifes;
}

void	Player::shoot(void)
{
	// TODO
}

void	Player::takeDamage(int amount)
{
	(void)amount;
}

Player &	Player::operator=( Player const & rhs )
{
	_pv = rhs.getPv();
	return *this;
}
