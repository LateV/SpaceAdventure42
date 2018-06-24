/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Window.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburlach <lburlach@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 13:35:00 by lburlach          #+#    #+#             */
/*   Updated: 2018/06/24 22:24:12 by lburlach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Window.h"

Window::Window(void) {
	initscr();
	noecho();
	cbreak();
	getmaxyx(stdscr, this->_yMax, this->_xMax);
	this->_err = false;
	this->_hp = 10000;
	this->_score = 0;
/*	std::stringstream tmp;
	tmp<<this->getYMax()<<" "<<this->getXMax();
	printw(tmp.str().c_str());
	refresh();
	getch();
 */
	if (this->getXMax() < 136) {
		printw("Sorry, but initial window should have more width\n");
		refresh();
		this->_err = true;
		Window::~Window();
		exit(1);
	}
	if (this->getYMax() < 20)
	{
		printw("Sorry, but initial window should have more height.\n");
		refresh();
		this->_err = true;
		Window::~Window();
		exit(1);
	}
	WINDOW * initial_window = newwin(this->getYMax(), this->getXMax(), 0, 0);
	this->setWinPtr(initial_window);
	//colors
/*	start_color();
	init_pair(1, COLOR_GREEN, COLOR_RED);
	wattron(this->getWinPtr(), COLOR_PAIR(1));*/
	//-colors
	box(this->getWinPtr(), 0, 0);
	wborder(this->getWinPtr(), 0 , 0 , 0, 0, '*', '*', '*', '*');
	refresh();
	wrefresh(this->getWinPtr());
	if (!has_colors())
	{
		printw("does not support colors, sorry.");
		Window::~Window();
		exit(1);
	}
}

Window::~Window(void) {
	if (this->_err == true) {
		do {
			printw("Press enter to exit.\n");
			refresh();
		} while (getch() != 10);
	}
	endwin();
	return;
}

Window::Window(Window const &src) {
	*this = src;
	return;
}

Window &Window::operator=(Window const &rhs) {
	if (this != &rhs)
	{
		this->_winPtr = rhs.getWinPtr();
		this->_yMax = rhs.getYMax();
		this->_xMax = rhs.getXMax();
		this->_score = rhs.getScore();
		this->_hp = rhs.getHp();
	}
	return *this;
}

//getters:
int Window::getXMax() const {
	return this->_xMax;
}

int Window::getYMax() const {
	return this->_yMax;
}

WINDOW* Window::getWinPtr() const {
	return this->_winPtr;
}

int Window::getScore() const {
	return this->_score;
}

int Window::getHp() const {
	return this->_hp;
}

//setters:
void Window::setXMax(int par) {
	this->_xMax = par;
}

void Window::setScore(int par) {
	this->_score = par;
}

void Window::setHp(int par) {
	this->_hp =par;
}

void Window::setYMax(int par) {
	this->_yMax = par;
}

void Window::setWinPtr(WINDOW *ptr) {
	this->_winPtr = ptr;
}

void Window::introduct() {
	mvwprintw(this->getWinPtr(), 1, 1, " #####                                       #######                                                    #     #  #        ###  ### ");
	wrefresh(this->getWinPtr());
	delay_output(150);
	mvwprintw(this->getWinPtr(), 2, 1, " #     #  #####     ##     ####   ######      #          ##    #    #  #####    ##     ####   #   #       #   #   #         #    #");
	wrefresh(this->getWinPtr());
	delay_output(150);
	mvwprintw(this->getWinPtr(), 3, 1, " #        #    #   #  #   #    #  #           #         #  #   ##   #    #     #  #   #        # #         # #    #         #    #");
	wrefresh(this->getWinPtr());
	delay_output(150);
	mvwprintw(this->getWinPtr(), 4, 1, "  #####   #    #  #    #  #       #####       #####    #    #  # #  #    #    #    #   ####     #           #     #         #    # ");
	wrefresh(this->getWinPtr());
	delay_output(150);
	mvwprintw(this->getWinPtr(), 5, 1, "       #  #####   ######  #       #           #        ######  #  # #    #    ######       #    #          # #    #         #    #");
	wrefresh(this->getWinPtr());
	delay_output(150);
	mvwprintw(this->getWinPtr(), 6, 1, " #     #  #       #    #  #    #  #           #        #    #  #   ##    #    #    #  #    #    #         #   #   #         #    #");
	wrefresh(this->getWinPtr());
	delay_output(150);
	mvwprintw(this->getWinPtr(), 7, 1, "  #####   #       #    #   ####   ######      #        #    #  #    #    #    #    #   ####     #        #     #  #######  ###  ###");
	wrefresh(this->getWinPtr());
	delay_output(150);
//	wattron(this->getWinPtr(), A);
	wrefresh(this->getWinPtr());
	delay_output(150);
	wattron(this->getWinPtr(), A_REVERSE | A_BLINK);
	mvwprintw(this->getWinPtr(), 9, 1, "lburlach");
	wrefresh(this->getWinPtr());
	delay_output(150);
	mvwprintw(this->getWinPtr(), 10, 1, "vibondar");
	wrefresh(this->getWinPtr());
	delay_output(150);
	wattroff(this->getWinPtr(), A_REVERSE);
}

int Window::startButton() {
	char s[2][6] = {"START", "EXIT!"};
	WINDOW * start_button = newwin(5, 10, this->getYMax() - 9, this->getXMax()/2 - 5);
	box(start_button, 0, 0);
	wborder(start_button, ' ', ' ' ,' ', ' ', ' ', ' ', ' ', ' ');
	int choice;
	int high = 0;
	keypad(start_button, true);
	while (1) {
		for (int i = 0; i < 2; i++) {
			if (i == high)
				wattron(start_button, A_REVERSE);
			mvwprintw(start_button, i + 1, 1, s[i]);
			wrefresh(start_button);
			wattroff(start_button, A_REVERSE);
		}
		choice = wgetch(start_button);

		switch(choice) {
			case KEY_UP:
				high--;
				if (high == -1)
					high = 0;
				break;
			case KEY_DOWN:
				high++;
				if (high == 2)
					high = 1;
				break;
			default:
				break;
		}
		if (choice == 10)
			break;
	}
	refresh();
	wrefresh(start_button);
	wclear(start_button);
	wrefresh(start_button);
	delwin(start_button);
	return (high);
}

void Window::clearWindow() {
	wclear(this->getWinPtr());
	box(this->getWinPtr(), 0, 0);
	wrefresh(this->getWinPtr());
}

