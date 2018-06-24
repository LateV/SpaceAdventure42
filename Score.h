/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Score.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburlach <lburlach@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/24 19:20:00 by lburlach          #+#    #+#             */
/*   Updated: 2018/06/24 19:35:18 by lburlach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef D04_SCORE_H
#define D04_SCORE_H

#include "Window.h"

class Score {
public:
	Score(void);
	Score(Score const &src);
	Score(const Window* win, int y, int x);
	~Score(void);
	Score &operator=(Score const &rhs);
	const Window * getPtrOnWin(void) const;
	WINDOW * getScWin(void) const ;
	int getXSc(void) const;
	int getYSc(void) const;
	void display(void);

private:
	const Window * _winPtr;
	WINDOW * _scoreWin;
	int _ySc;
	int _xSc;
};


#endif //D04_SCORE_H
