/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 13:25:27 by svelhinh          #+#    #+#             */
/*   Updated: 2017/04/09 09:59:27 by nchrupal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Player.hpp"
#include "Game.hpp"

Player::Player(void): ACharacter(1, 1, 1, "=>")
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
	int moveX = mvX + _x;
	int moveY = mvY + _y;

	if (moveX < 1 || moveX > MAPH - 1 || moveY < 1 || moveY > MAPL - 2)		// J'ai mis les valeurs en dur, mais faudra modifier si on veut faire plusieurs gabarits de vaisseaux
		return;
	_x = moveX;
	_y = moveY;
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
	_pv = rhs.getPv();
	_x = rhs.getX();
	_y = rhs.getY();
	return *this;
}
