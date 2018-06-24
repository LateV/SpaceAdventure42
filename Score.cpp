/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Score.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburlach <lburlach@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/24 19:20:00 by lburlach          #+#    #+#             */
/*   Updated: 2018/06/24 19:42:25 by lburlach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Score.h"

Score::Score(void) : _winPtr(NULL) {
}

Score::Score(const Window *win, int y, int x) : _winPtr(win), _ySc(y), _xSc(x)
{
	this->_scoreWin = newwin(this->_ySc, this->_xSc, getPtrOnWin()->getYMax() - 5, 3);
	box(this->getScWin(), 0, 0);
}

Score::~Score(void) {
	return;
}

WINDOW* Score::getScWin() const {
	return this->_scoreWin;
}

Score::Score(Score const &src) {
	*this = src;
	return;
}

Score &Score::operator=(Score const &rhs) {
	if (this != &rhs) {
		this->_winPtr = rhs.getPtrOnWin();
		this->_scoreWin = rhs.getScWin();
	}
	return *this;
}
//getters:
const Window* Score::getPtrOnWin() const {
	return this->_winPtr;
}

int Score::getXSc() const {
	return this->_xSc;
}

int Score::getYSc() const {
	return this->_ySc;
}

void Score::display() {
	mvwprintw(this->getScWin(), 1, 1, "%d %d", this->getPtrOnWin()->getYMax(), this->getPtrOnWin()->getYMax());
}
