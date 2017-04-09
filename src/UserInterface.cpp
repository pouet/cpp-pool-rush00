/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   UserInterface.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 13:25:27 by svelhinh          #+#    #+#             */
/*   Updated: 2017/04/09 14:56:50 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "UserInterface.hpp"
#include "Game.hpp"

UserInterface::UserInterface(void)
{
	init_pair(C_REDBLACK, COLOR_RED, COLOR_BLACK);
}

UserInterface::UserInterface(UserInterface const & src)
{
	*this = src;
	return;
}

UserInterface::~UserInterface(void)
{
}

void	UserInterface::displayInfos(int nbLives, int score, int time) const
{
	int width = MAPL;
	int height = 2;
	float nbInfos = 3;

	mvprintwColor(MAPH + height, 0, "#", C_REDBLACK);
	for (int x = 1; x < width; x++)
		mvprintwColor(MAPH + height, x, "-", C_REDBLACK);
	mvprintwColor(MAPH + height, width, "#", C_REDBLACK);
	for (float i = nbInfos; i >= 0; i--)
		for (int y = MAPH + 1; y < MAPH + height; y++)
			mvprintwColor(y, i / 3 * width, "|", C_REDBLACK);
	mvprintwColor(MAPH, width, "#", C_REDBLACK);

	int y = MAPH + height;

	mvprintwColor(y - 1, (((nbInfos - 1) / 3 * width) + ((nbInfos / 3 * width - (nbInfos - 1) / 3 * width) / 2)) - 2.5, std::string("LIVES : ") + std::to_string(nbLives), C_REDBLACK);
	mvprintwColor(y - 1, (((nbInfos - 2) / 3 * width) + (((nbInfos - 1) / 3 * width - (nbInfos - 2) / 3 * width) / 2)) - 2.5, std::string("SCORE : ") + std::to_string(score), C_REDBLACK);
	mvprintwColor(y - 1, (((nbInfos - 3) / 3 * width) + (((nbInfos - 2) / 3 * width - (nbInfos - 3) / 3 * width) / 2)) - 2, std::string("TIME : ") + std::to_string(time), C_REDBLACK);
}

void	UserInterface::update(int nbLives, int score, int time) const
{
	mvprintwColor(0, 0, "#", C_REDBLACK);
	mvprintwColor(MAPH, 0, "#", C_REDBLACK);
	mvprintwColor(0, MAPL, "#", C_REDBLACK);
	mvprintwColor(MAPH, MAPL, "#", C_REDBLACK);
	for (int y = 1; y < MAPL; y++)
	{
		mvprintwColor(0, y, "-", C_REDBLACK);
		mvprintwColor(MAPH, y, "-", C_REDBLACK);
	}
	for (int x = 1; x < MAPH; x++)
	{
		mvprintwColor(x, 0, "|", C_REDBLACK);
		mvprintwColor(x, MAPL, "|", C_REDBLACK);
	}
	displayInfos(nbLives, score, time);
}

void	UserInterface::mvprintwColor(int x, int y, std::string str, int color) const
{
	//attron(COLOR_PAIR(color));
	mvprintw(x, y, str.c_str());
	//attroff(COLOR_PAIR(color));
}

UserInterface &	UserInterface::operator=( UserInterface const & rhs )
{
	(void)rhs;
	return *this;
}
