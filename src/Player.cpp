/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 13:25:27 by svelhinh          #+#    #+#             */
/*   Updated: 2017/04/08 14:16:59 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Player.hpp"

Player::Player(): ACharacter(0, 0, 0)
{
}

Player::Player(int pv_, int x_, int y_): ACharacter(pv_, x_, y_)
{
}

Player::Player(Player const & src)
{
	*this = src;
	return;
}

Player::~Player()
{
}

void	Player::move(int mvX, int mvY)
{
	(void)mvX;
	(void)mvY;
}

void	Player::shoot()
{

}

void	Player::collide()
{

}

void	Player::takeDamage(int amount)
{
	(void)amount;
}

Player &	Player::operator=( Player const & rhs )
{
	pv = rhs.getPv();
	x = rhs.getX();
	y = rhs.getY();
	return *this;
}
