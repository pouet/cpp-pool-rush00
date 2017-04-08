/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 13:25:27 by svelhinh          #+#    #+#             */
/*   Updated: 2017/04/08 14:30:50 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Player.hpp"

Player::Player(void): ACharacter(0, 0, 0)
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

Player::~Player(void)
{
}

void	Player::move(int mvX, int mvY)
{
	(void)mvX;
	(void)mvY;
}

void	Player::shoot(void)
{

}

void	Player::collide(ACharacter * character)
{
	(void)character;
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
