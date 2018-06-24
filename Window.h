/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburlach <lburlach@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 13:35:00 by lburlach          #+#    #+#             */
/*   Updated: 2018/06/24 20:18:40 by lburlach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef D04_WINDOW_H
#define D04_WINDOW_H
#include <iostream>
#include "space_fantasy.h"

class Window {
public:
	Window(void);
	Window(Window const &src);
	~Window(void);
	Window &operator=(Window const &rhs);
	int getXMax() const;
	int getYMax() const;
	WINDOW * getWinPtr(void) const;
	void setXMax(int par);
	void setYMax(int par);
	void setWinPtr(WINDOW * ptr);
	void introduct(void);
	int startButton(void);
	void clearWindow(void);
	int getScore(void) const;
	void setScore(int par);
	int getHp(void) const;
	void setHp(int hp);

private:
	int _xMax;
	int _yMax;
	bool _err;
	int _score;
	int _hp;
	WINDOW * _winPtr;
};


#endif //D04_WINDOW_H
