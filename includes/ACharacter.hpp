/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ACharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 13:24:59 by svelhinh          #+#    #+#             */
/*   Updated: 2017/04/09 14:07:07 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Acharacter_hpp
#define Acharacter_hpp

#include <string>
#include <ncurses.h>
#include "AHitBox.hpp"

class ACharacter : public AHitBox
{
public:
    ACharacter(void);
	ACharacter(int pv, int y, int x, int w, int h, const std::string shape);
    ACharacter(ACharacter const & src);
    virtual ~ACharacter(void);

	int					getPv(void) const;
	std::string const	getShape(void) const;

	void	setPv(int pv_);

	void	update(void);
	void	move(int x, int y);

	bool	isAlive(void) const;

	ACharacter &	operator=( ACharacter const & rhs );

protected:
	int					_pv;
	std::string const	_shape;

	virtual void	shoot(void) = 0;
	virtual void	takeDamage(int) = 0;
};


#endif /* Acharacter_hpp */
