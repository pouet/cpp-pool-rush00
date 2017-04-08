/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameObject.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 13:24:59 by svelhinh          #+#    #+#             */
/*   Updated: 2017/04/08 14:35:04 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GameObject_hpp
#define GameObject_hpp

#include "Player.hpp"
#include "Enemy.hpp"

class GameObject
{
public:
    GameObject(void);
    GameObject(GameObject const & src);
    ~GameObject(void);

	void    Add(Player player);
    void    Add(Enemy enemy);
	void    Remove(Player player);
    void    Remove(Enemy enemy);

	void	DrawAll(/* Window */);

	GameObject &	operator=( GameObject const & rhs );
};


#endif /* GameObject_hpp */
