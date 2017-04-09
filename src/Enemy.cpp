/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 13:25:27 by svelhinh          #+#    #+#             */
/*   Updated: 2017/04/09 17:28:44 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemy.hpp"
#include "Game.hpp"
#include <cstdlib>

Enemy::Enemy(void)
	: ACharacter(1, 1, 1, 2, 2, "@@\n@@"), _elapsedTicks(0)
{
}

Enemy::Enemy(int pv, int x, int y, int givenScore)
	: ACharacter(pv, x, y, 2, 2, "@@\n@@"), _elapsedTicks(0), _givenScore(givenScore)
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

int			Enemy::getGivenScore(void) const
{
	return _givenScore;
}

void	Enemy::update(void)
{
	_elapsedTicks++;
	// vitesse: niveau 0 -> 0.5s : 30 ticks
	if (_elapsedTicks < 30 + rand() % 10)
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
