/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   UserInterface.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 13:24:59 by svelhinh          #+#    #+#             */
/*   Updated: 2017/04/08 19:06:28 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UserInterface_hpp
#define UserInterface_hpp

class UserInterface
{
public:
	UserInterface(void);
    UserInterface(UserInterface const & src);
    virtual ~UserInterface(void);

    void	update(void) const;

	UserInterface &	operator=( UserInterface const & rhs );
};


#endif /* UserInterface_hpp */
