/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameObject.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 13:25:27 by svelhinh          #+#    #+#             */
/*   Updated: 2017/04/08 14:36:27 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GameObject.hpp"

GameObject::GameObject(void)
{
}

GameObject::GameObject(GameObject const & src)
{
	*this = src;
	return;
}

void    Add(Player player)
{
	// Mettre player dans player du Game
}

void    Add(Enemy enemy)
{
	// Mettre enemy dans enemy du Game
}

void    Remove(Player player)
{
	// Del le player du Game
}

void    Remove(Enemy enemy)
{
	// Del l'enemy du Game
}

void	DrawAll(/* Window */)
{

}

GameObject::~GameObject(void)
{
}

GameObject &	GameObject::operator=( GameObject const & rhs )
{
	return *this;
}
