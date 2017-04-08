/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 13:25:27 by svelhinh          #+#    #+#             */
/*   Updated: 2017/04/08 18:42:21 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemy.hpp"
#include "Game.hpp"

Enemy::Enemy(void): ACharacter(-1, -1, -1, "@")
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
	int moveX = mvX + x;
	int moveY = mvY + y;

	if (moveX < 0 || moveX > MAPH || moveY < 0 || moveY > MAPL)
	{
		//Game::_remove(this);
		return;
	}
	x = moveX;
	y = moveY;
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
	if (pv - amount <= 0)
	{
		pv = -1;
		x = -1;
		y = -1;
		return;
	}
	pv -= amount;

}

Enemy &	Enemy::operator=( Enemy const & rhs )
{
	pv = rhs.getPv();
	x = rhs.getX();
	y = rhs.getY();
	return *this;
}
