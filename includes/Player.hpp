/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 13:24:59 by svelhinh          #+#    #+#             */
/*   Updated: 2017/04/09 12:49:51 by nchrupal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Player_hpp
#define Player_hpp

#include "ACharacter.hpp"
#include <string>

class Player : public ACharacter
{
public:
	Player(void);
	Player(int, int, int);
    Player(Player const & src);
    virtual ~Player(void);

	std::string	getShape(void) const;

	Player &	operator=( Player const & rhs );

	virtual void	shoot(void);
	virtual void	takeDamage(int);
};


#endif /* Player_hpp */
