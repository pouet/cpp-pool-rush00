/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ACharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 13:24:59 by svelhinh          #+#    #+#             */
/*   Updated: 2017/04/08 13:51:35 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Acharacter_hpp
#define Acharacter_hpp

class ACharacter
{
protected:
	struct sPos
	{
		int x;
		int y;
	};

public:
    ACharacter();
    ACharacter(ACharacter const & src);
    ~ACharacter();

	int		getPv() const;
	sPos	getPos() const;

	ACharacter &	operator=( ACharacter const & rhs );

protected:
	int		pv;
	sPos	pos;

	virtual void	move(sPos posToMove) = 0;
	virtual void	shoot() = 0;
	virtual void	collide() = 0;	// Peut etre un override pour les collisions avec la scene
	virtual void	takeDamage() = 0;
};


#endif /* Acharacter_hpp */
