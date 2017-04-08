/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 13:25:27 by svelhinh          #+#    #+#             */
/*   Updated: 2017/04/08 14:23:51 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemy.hpp"

Enemy::Enemy(): ACharacter(0, 0, 0)
{
}

Enemy::Enemy(int pv_, int x_, int y_): ACharacter(pv_, x_, y_)
{
}

Enemy::Enemy(Enemy const & src)
{
	*this = src;
	return;
}

Enemy::~Enemy()
{
}

void	Enemy::move(int mvX, int mvY)
{
	(void)mvX;
	(void)mvY;
}

void	Enemy::shoot()
{

}

void	Enemy::collide()
{

}

void	Enemy::takeDamage(int amount)
{
	(void)amount;
}

Enemy &	Enemy::operator=( Enemy const & rhs )
{
	pv = rhs.getPv();
	x = rhs.getX();
	y = rhs.getY();
	return *this;
}
