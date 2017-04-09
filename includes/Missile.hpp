/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Missile.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 13:24:59 by svelhinh          #+#    #+#             */
/*   Updated: 2017/04/09 14:19:01 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Missile_hpp
#define Missile_hpp

#include "AHitBox.hpp"
#include <string>

class Missile : public AHitBox
{
public:
	Missile(void);
	Missile(int x, int y);
    Missile(Missile const & src);
    virtual ~Missile(void);

//	void	shoot(void);
//	void	takeDamage(int amount);

	Missile &	operator=( Missile const & rhs );
};


#endif /* Missile_hpp */
