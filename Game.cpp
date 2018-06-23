/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburlach <lburlach@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 16:29:00 by lburlach          #+#    #+#             */
/*   Updated: 2018/06/23 18:32:55 by lburlach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Game.h"

Game::Game(void) : _win(NULL) {
	return;
}

Game::Game(const Window *win) : _win(win) {
	return ;
}

Game::~Game(void) {
	return;
}

Game::Game(Game const &src) {
	*this = src;
	return;
}

Game &Game::operator=(Game const &rhs) {
	if (this != &rhs) {
		this->_win = rhs.getPtrOnWin();
	}
	return *this;
}

const Window* Game::getPtrOnWin() const {
	return this->_win;
}

void Game::background() {
	wprintw(this->getPtrOnWin()->getWinPtr(), "ok");
	wrefresh(this->getPtrOnWin()->getWinPtr());
	char tmp[10000];
	wprintw(this->getPtrOnWin()->getWinPtr(), "ok");
	wrefresh(this->getPtrOnWin()->getWinPtr());
	srand(clock());
	for (int i = 0; i < 10000; i++) {
		if (rand() % 100 < 5)
			tmp[i] = '*';
		else
			tmp[i] = ' ';
	}
	wprintw(this->getPtrOnWin()->getWinPtr(), "ok");
	wrefresh(this->getPtrOnWin()->getWinPtr());
	for (int j = 0; j < this->getPtrOnWin()->getYMax(); j++)
	{
		mvwprintw(this->getPtrOnWin()->getWinPtr(), j, rand() % (this->getPtrOnWin()->getXMax()), tmp);
	}
	wrefresh(this->getPtrOnWin()->getWinPtr());
	getch();
}