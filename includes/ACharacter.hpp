/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ACharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 13:24:59 by svelhinh          #+#    #+#             */
/*   Updated: 2017/04/08 17:05:34 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Acharacter_hpp
#define Acharacter_hpp

#include <string>
#include <ncurses.h>

class ACharacter
{
public:
    ACharacter(void);
	ACharacter(int, int, int, const std::string);
    ACharacter(ACharacter const & src);
    virtual ~ACharacter(void);

	int		getPv(void) const;
	int		getX(void) const;
	int		getY(void) const;
	std::string const getShape(void) const;
	void	setPv(int pv_);
	void	setX(int x_);
	void	setY(int y_);
	void	update(void);

	ACharacter &	operator=( ACharacter const & rhs );

protected:
	int		pv;
	int		x;
	int		y;
	std::string const	shape;

	virtual void	move(int, int) = 0;
	virtual void	shoot(void) = 0;
	virtual void	collide(ACharacter * character) = 0;	// Peut etre un override pour les collisions avec la scene
	virtual void	takeDamage(int) = 0;
};


#endif /* Acharacter_hpp */
