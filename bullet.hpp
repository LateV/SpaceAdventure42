#ifndef BULLET_HPP
#define BULLET_HPP

#include <ncurses.h>
#include <locale>
#include <string>
#include <iostream>

class bullet {
public:
	bullet(WINDOW * win, int y, int x);
	~bullet();
	void p_bull_mv();
	void e_bull_mv();
	void shot(int x, int y);
private:
	int active;
	int x_b;
	int y_b;
	int max_x;
	int max_y;
};

#endif