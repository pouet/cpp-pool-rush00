/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 13:24:59 by svelhinh          #+#    #+#             */
/*   Updated: 2017/04/08 17:01:35 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Enemy_hpp
#define Enemy_hpp

#include "ACharacter.hpp"
#include <string>

class Enemy : public ACharacter
{
public:
	Enemy(void);
	Enemy(int, int, int);
    Enemy(Enemy const & src);
    virtual ~Enemy(void);

	std::string	getShape(void) const;

	Enemy &	operator=( Enemy const & rhs );

	virtual void	move(int, int);
	virtual void	shoot(void);
	virtual void	collide(ACharacter *character);	// Peut etre un override pour les collisions avec la scene
	virtual void	takeDamage(int);
};


#endif /* Enemy_hpp */
