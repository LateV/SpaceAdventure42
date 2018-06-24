/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Foe.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburlach <lburlach@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/24 11:11:00 by lburlach          #+#    #+#             */
/*   Updated: 2018/06/24 18:33:05 by lburlach         ###   ########.fr       */
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

void Foe::setWinPtr(const Window *ptr, player * pl) {
	srand(clock());
	this->_yPop = 0;
	this->_curwin = ptr;
//	while ((this->_yPop < 7) || (this->_yPop > this->getPtrOnWin()->getYMax() - 7))
//		this->_yPop = (rand() % this->getPtrOnWin()->getYMax());
		this->_yPop = (rand() % (this->getPtrOnWin()->getYMax() - 7) + 7);
	this->_xPop = this->getPtrOnWin()->getXMax() - 6;
	this->_dead = true;
	this->_pl = pl;
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
	if (this->checkCollisionWithBullet())
		this->_dead= true;
	if (!this->_dead) {
		if (this->checkCollision())
			exit(1);
		mvwprintw(this->getPtrOnWin()->getWinPtr(), this->getYPop(),
				  this->getXPop(), "  \\\\");
		mvwprintw(this->getPtrOnWin()->getWinPtr(), this->getYPop() - 1,
				  this->getXPop(), " \\ /");
		mvwprintw(this->getPtrOnWin()->getWinPtr(), this->getYPop() - 2,
				  this->getXPop(), "\\  \\");
		mvwprintw(this->getPtrOnWin()->getWinPtr(), this->getYPop() - 3,
				  this->getXPop(), "/  /");
		mvwprintw(this->getPtrOnWin()->getWinPtr(), this->getYPop() - 4,
				  this->getXPop(), " / \\");
		mvwprintw(this->getPtrOnWin()->getWinPtr(), this->getYPop() - 5,
				  this->getXPop(), "  //");
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

int Foe::checkCollision(void) {
	int pos_of_foe;
	int pos_of_pl;
	int count;
	int y_p = this->_pl->get_y_l();
	int x_p  = this->_pl->get_x_l();
	int y_f = this->getYPop();
	int x_f = this->getXPop();
//	mvwprintw(this->getPtrOnWin()->getWinPtr(), 10, 10, "pl = %d foe = %d", y_p, y_f);
	wrefresh(this->getPtrOnWin()->getWinPtr());
	for (int i = 0; i < 6; i++) {
		pos_of_foe = y_f + i;
		pos_of_pl = y_p;
		count = 0;
		while (count < 4) {
			if (abs(pos_of_foe - pos_of_pl) < 5 && abs(x_f - x_p) < 4)
				return (1);
			pos_of_pl++;
			count++;
		}
	}
	return (0);
}

int Foe::checkCollisionWithBullet() {
	int pos_of_foe;
	int y_b;
	int x_b;
	bullet * buls = this->_pl->get_p_bull();

	for (int i = 0; i < 1000; i++)
	{
		y_b = buls[i].get_y_b();
		x_b = buls[i].get_x_b();
		for (int j = 0; j < 6; j++) {
			pos_of_foe = this->getYPop() + j;
			if (abs(pos_of_foe - y_b) < 2 && abs(x_b - this->getXPop()) < 2)
				return (1);
		}
	}
	return (0);
}
