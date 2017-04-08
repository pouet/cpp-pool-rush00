/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 13:25:27 by svelhinh          #+#    #+#             */
/*   Updated: 2017/04/08 17:30:32 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Player.hpp"
#include "Game.hpp"

Player::Player(void): ACharacter(-1, -1, -1, "=>")
{
}

Player::Player(int pv_, int x_, int y_): ACharacter(pv_, x_, y_, "=>")
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
	int moveX = mvX + x;
	int moveY = mvY + y;

	if (moveX < 0 || moveX > MAPH || moveY < 0 || moveY > MAPL)
		return;
	x = moveX;
	y = moveY;
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
