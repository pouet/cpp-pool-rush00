/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ACharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 13:24:59 by svelhinh          #+#    #+#             */
/*   Updated: 2017/04/08 14:21:01 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Acharacter_hpp
#define Acharacter_hpp

class ACharacter
{
public:
    ACharacter();
	ACharacter(int, int, int);
    ACharacter(ACharacter const & src);
    ~ACharacter();

	int		getPv() const;
	int		getX() const;
	int		getY() const;

	ACharacter &	operator=( ACharacter const & rhs );

protected:
	int		pv;
	int		x;
	int		y;

	virtual void	move(int, int) = 0;
	virtual void	shoot() = 0;
	virtual void	collide() = 0;	// Peut etre un override pour les collisions avec la scene
	virtual void	takeDamage(int) = 0;
};


#endif /* Acharacter_hpp */
