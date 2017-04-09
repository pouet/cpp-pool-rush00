/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 13:25:27 by svelhinh          #+#    #+#             */
/*   Updated: 2017/04/09 16:07:15 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemy.hpp"
#include "Game.hpp"
#include <cstdlib>

Enemy::Enemy(void)
	: ACharacter(1, 1, 1, 1, 1, "@"), _elapsedTicks(0)
{
}

Enemy::Enemy(int pv, int x, int y)
	: ACharacter(pv, x, y, 1, 1, "@"), _elapsedTicks(0)
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

void	Enemy::update(void)
{
	_elapsedTicks++;
	// vitesse: niveau 0 -> 1s : 30 ticks
	if (_elapsedTicks < 30)
		return;
	_elapsedTicks = 0;
	int y = -1 + (rand() % 3);
	while (_y + y <= 0 || _y + y >= MAPH)
		y = -1 + (rand() % 3);
	move(-1, y);
}

void	Enemy::shoot(void)
{
}

void	Enemy::takeDamage(int amount)
{
	_pv -= amount;
}

Enemy &	Enemy::operator=( Enemy const & rhs )
{
	_pv = rhs.getPv();
	return *this;
}
