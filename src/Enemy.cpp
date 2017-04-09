/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 13:25:27 by svelhinh          #+#    #+#             */
/*   Updated: 2017/04/09 12:33:28 by nchrupal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemy.hpp"
#include "Game.hpp"

Enemy::Enemy(void)
	: ACharacter(1, 1, 1, 1, 1, "@")
{
}

Enemy::Enemy(int pv, int x, int y)
	: ACharacter(pv, x, y, 1, 1, "@")
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

void	Enemy::shoot(void)
{

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
	return *this;
}
