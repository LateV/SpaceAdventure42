/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Foe.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburlach <lburlach@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/24 11:11:00 by lburlach          #+#    #+#             */
/*   Updated: 2018/06/24 17:24:44 by lburlach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef D04_FOE_H
#define D04_FOE_H

#include "space_fantasy.h"
#include "Window.h"
#include "player.hpp"

class Foe {
public:
	Foe(void);
	Foe(Foe const &src);
	~Foe(void);
	Foe &operator=(Foe const &rhs);
	const Window * getPtrOnWin(void) const;
	int getXPop(void) const;
	int getYPop(void) const;
	void display(void);
	void setWinPtr(const Window * pt, player * pl);
	void setDead(bool mean);
	int checkCollision(void);
private:
	static const bool _body[6][4];
	const Window * _curwin;
	int _xPop;
	int _yPop;
	bool _dead;
	player * _pl;
};

#endif //D04_FOE_H

