/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 13:25:27 by svelhinh          #+#    #+#             */
/*   Updated: 2017/04/09 10:43:10 by nchrupal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemy.hpp"
#include "Game.hpp"

Enemy::Enemy(void): ACharacter(1, 1, 1, "@")
{
}

Enemy::Enemy(int pv_, int x_, int y_): ACharacter(pv_, x_, y_, "@")
{
}

Enemy::Enemy(Enemy const & src)
{
	*this = src;
	return;
}

Enemy::~Enemy(void)
{
}

void	Enemy::move(int mvX, int mvY)
{
	int moveX = mvX + _x;
	int moveY = mvY + _y;

	if (moveX < 0 || moveX > MAPH || moveY < 0 || moveY > MAPL)
	{
		_pv = 0;
		return;
	}
	_x = moveX;
	_y = moveY;
}

void	Enemy::shoot(void)
{

}

void	Enemy::collide(ACharacter * character)
{
	(void)character;
}

void	Enemy::takeDamage(int amount)
{
	if (_pv - amount <= 0)
	{
		_pv = -1;
		_x = -1;
		_y = -1;
		return;
	}
	_pv -= amount;

}

Enemy &	Enemy::operator=( Enemy const & rhs )
{
	_pv = rhs.getPv();
	_x = rhs.getX();
	_y = rhs.getY();
	return *this;
}
