/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   UserInterface.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 13:24:59 by svelhinh          #+#    #+#             */
/*   Updated: 2017/04/09 14:45:57 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UserInterface_hpp
#define UserInterface_hpp
#include <string>

enum e_colors
{
    C_REDBLACK = 1
};

class UserInterface
{
public:
	UserInterface(void);
    UserInterface(UserInterface const & src);
    virtual ~UserInterface(void);

	void	update(int nbLives, int score, int time) const;
    void	mvprintwColor(int x, int y, std::string str, int color) const;

private:
    void	displayInfos(int nbLives, int score, int time) const;

	UserInterface &	operator=( UserInterface const & rhs );
};


#endif /* UserInterface_hpp */
