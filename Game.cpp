/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburlach <lburlach@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 16:29:00 by lburlach          #+#    #+#             */
/*   Updated: 2018/06/23 21:12:10 by lburlach         ###   ########.fr       */
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
	delete this->_hm;
	delete this->_tmp;
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
	static bool flag = false;
	static char tmp[1000];
	srand(clock());
	if (!flag) {
		this->_hm = new std::string[this->getPtrOnWin()->getYMax()]; //for moving background around, we'd save indexes of spray string.
		for (int i = 0; i < 1000; i++) {
			if (rand() % 100 < 3)
				tmp[i] = '*';
			else
				tmp[i] = ' ';
		}
		for (int j = 0; j < this->getPtrOnWin()->getYMax(); j++) {
			this->_hm[j] = std::to_string(rand() % 100);
		}
	}
	for (int j = 1; j < this->getPtrOnWin()->getYMax() - 1; j++) {
		mvwprintw(this->getPtrOnWin()->getWinPtr(), j, 1, tmp + atoi(this->_hm[j].c_str()));
		if (atoi(this->_hm[j].c_str()) + 1 > 999) {
			for (int z = 0; z < this->getPtrOnWin()->getYMax(); z++) {
				this->_hm[z] = std::to_string(rand() % 100);
			}
		}
		this->_hm[j] = std::to_string(atoi(this->_hm[j].c_str()) + 1);
	}
	flag = true;
	mvwprintw(this->getPtrOnWin()->getWinPtr(), 5, this->getPtrOnWin()->getXMax() - 70, "               ____");
	mvwprintw(this->getPtrOnWin()->getWinPtr(), 6, this->getPtrOnWin()->getXMax() - 70, "          .-'\"\"p 8o\"\"`-");
	mvwprintw(this->getPtrOnWin()->getWinPtr(), 7, this->getPtrOnWin()->getXMax() - 70, "       .-'8888P'Y.`Y[ ' `-");
	mvwprintw(this->getPtrOnWin()->getWinPtr(), 8, this->getPtrOnWin()->getXMax() - 70, "     ,']88888b.J8oo_      '`");
	mvwprintw(this->getPtrOnWin()->getWinPtr(), 9, this->getPtrOnWin()->getXMax() - 70, "   ,' ,88888888888[\"        Y`");
	mvwprintw(this->getPtrOnWin()->getWinPtr(), 10, this->getPtrOnWin()->getXMax() - 70, "  /   8888888888P            Y8\\");
	mvwprintw(this->getPtrOnWin()->getWinPtr(), 11, this->getPtrOnWin()->getXMax() - 70, " /    Y8888888P'             ]88\\");
	mvwprintw(this->getPtrOnWin()->getWinPtr(), 12, this->getPtrOnWin()->getXMax() - 70, ":     `Y88'   P              `888:");
	mvwprintw(this->getPtrOnWin()->getWinPtr(), 13, this->getPtrOnWin()->getXMax() - 70, ":       Y8.oP '- >            Y88:");
	mvwprintw(this->getPtrOnWin()->getWinPtr(), 14, this->getPtrOnWin()->getXMax() - 70, "|          `Yb  __             `'|");
	mvwprintw(this->getPtrOnWin()->getWinPtr(), 15, this->getPtrOnWin()->getXMax() - 70, ":            `'d8888bo.          :");
	mvwprintw(this->getPtrOnWin()->getWinPtr(), 16, this->getPtrOnWin()->getXMax() - 70, ":             d88888888ooo.      ;");
	mvwprintw(this->getPtrOnWin()->getWinPtr(), 17, this->getPtrOnWin()->getXMax() - 70, " \\            Y88888888888P     /");
	mvwprintw(this->getPtrOnWin()->getWinPtr(), 18, this->getPtrOnWin()->getXMax() - 70, "  \\            `Y88888888P     /");
	mvwprintw(this->getPtrOnWin()->getWinPtr(), 19, this->getPtrOnWin()->getXMax() - 70, "   `.            d88888P'    ,'");
	mvwprintw(this->getPtrOnWin()->getWinPtr(), 20, this->getPtrOnWin()->getXMax() - 70, "     `.          888PP'    ,'");
	mvwprintw(this->getPtrOnWin()->getWinPtr(), 21, this->getPtrOnWin()->getXMax() - 70, "       `-.      d8P'    ,-'   ");
	mvwprintw(this->getPtrOnWin()->getWinPtr(), 22, this->getPtrOnWin()->getXMax() - 70, "          `-.,,_'__,,.-'");
}

