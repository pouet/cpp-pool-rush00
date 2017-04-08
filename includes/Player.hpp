/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 13:24:59 by svelhinh          #+#    #+#             */
/*   Updated: 2017/04/08 14:21:05 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Player_hpp
#define Player_hpp

#include "ACharacter.hpp"

class Player : public ACharacter
{
public:
	Player();
	Player(int, int, int);
    Player(Player const & src);
    ~Player();

	Player &	operator=( Player const & rhs );

	virtual void	move(int, int);
	virtual void	shoot();
	virtual void	collide();	// Peut etre un override pour les collisions avec la scene
	virtual void	takeDamage(int);
};


#endif /* Player_hpp */
