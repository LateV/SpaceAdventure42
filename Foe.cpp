/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Foe.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburlach <lburlach@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/24 11:11:00 by lburlach          #+#    #+#             */
/*   Updated: 2018/06/24 13:57:35 by lburlach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Foe.h"

Foe::Foe(void) {
	return;
}

Foe::~Foe(void) {
	return;
}

Foe::Foe(Foe const &src) {
	*this = src;
	return;
}

Foe &Foe::operator=(Foe const &rhs) {
	if (this != &rhs) {
		this->_curwin = rhs.getPtrOnWin();
		this->_xPop = rhs.getXPop();
		this->_yPop = rhs.getYPop();
	}
	return *this;
}
//setters:

void Foe::setWinPtr(const Window *ptr) {
	srand(clock());
	this->_yPop = 0;
	this->_curwin = ptr;
//	while ((this->_yPop < 7) || (this->_yPop > this->getPtrOnWin()->getYMax() - 7))
//		this->_yPop = (rand() % this->getPtrOnWin()->getYMax());
		this->_yPop = (rand() % (this->getPtrOnWin()->getYMax() - 7) + 7);
	this->_xPop = this->getPtrOnWin()->getXMax() - 6;
	this->_dead = true;
}
//getters:
const Window* Foe::getPtrOnWin() const {
	return this->_curwin;
}

int Foe::getXPop() const {
	return this->_xPop;
}

int Foe::getYPop() const {
	return this->_yPop;
}

const bool Foe::_body[6][4] = {
		{false, false, true, true},
		{false, true, false, true},
		{true, false, false, true},
		{true, false ,false, true},
		{false, true, false, true},
		{false, false, true, true}
};

void Foe::display() {
	srand(clock());
	nodelay(this->getPtrOnWin()->getWinPtr(), true);
	mvwprintw(this->getPtrOnWin()->getWinPtr(), this->getYPop() + 1,
			  this->getXPop(), "     ");
	mvwprintw(this->getPtrOnWin()->getWinPtr(), this->getYPop(),
			  this->getXPop(), "     ");
	mvwprintw(this->getPtrOnWin()->getWinPtr(), this->getYPop() - 1,
			  this->getXPop(), "     ");
	mvwprintw(this->getPtrOnWin()->getWinPtr(), this->getYPop() - 2,
			  this->getXPop(), "     ");
	mvwprintw(this->getPtrOnWin()->getWinPtr(), this->getYPop() - 3,
			  this->getXPop(), "     ");
	mvwprintw(this->getPtrOnWin()->getWinPtr(), this->getYPop() - 4,
			  this->getXPop(), "     ");
	mvwprintw(this->getPtrOnWin()->getWinPtr(), this->getYPop() - 5,
			  this->getXPop(), "     ");
	mvwprintw(this->getPtrOnWin()->getWinPtr(), this->getYPop() - 6,
			  this->getXPop(), "     ");

	if (!this->_dead) {
		mvwprintw(this->getPtrOnWin()->getWinPtr(), this->getYPop(),
				  this->getXPop(), "  /\\");
		mvwprintw(this->getPtrOnWin()->getWinPtr(), this->getYPop() - 1,
				  this->getXPop(), " / /");
		mvwprintw(this->getPtrOnWin()->getWinPtr(), this->getYPop() - 2,
				  this->getXPop(), "/  \\");
		mvwprintw(this->getPtrOnWin()->getWinPtr(), this->getYPop() - 3,
				  this->getXPop(), "\\  /");
		mvwprintw(this->getPtrOnWin()->getWinPtr(), this->getYPop() - 4,
				  this->getXPop(), " \\ \\");
		mvwprintw(this->getPtrOnWin()->getWinPtr(), this->getYPop() - 5,
				  this->getXPop(), "  \\/");
		if (rand() % 100 < 39) {
			this->_yPop = rand() % 100 > 49 ? this->_yPop + 1 : this->_yPop - 1;
		}
		else
			this->_xPop--;
		if (this->_yPop >= this->getPtrOnWin()->getYMax() - 3 ||
			this->_yPop <= 6 || this->_xPop <= 1)
			this->_dead = true;
	}
}

void Foe::setDead(bool mean) {
	this->_dead = mean;
}