/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 13:24:59 by svelhinh          #+#    #+#             */
/*   Updated: 2017/04/09 17:28:25 by svelhinh         ###   ########.fr       */
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
	Enemy(int pv, int x, int y, int givenScore);
    Enemy(Enemy const & src);
    virtual ~Enemy(void);

	int			getGivenScore(void) const;

	Enemy &	operator=( Enemy const & rhs );

	virtual void	shoot(void);
	virtual void	takeDamage(int);
	virtual void	update(void);

private:
	int _elapsedTicks;
	int	_givenScore;
};


#endif /* Enemy_hpp */
