#ifndef BULLET_HPP
#define BULLET_HPP

#include <ncurses.h>
#include <locale>
#include <string>
#include <iostream>

class bullet{
public:
	bullet(WINDOW * win, int y, int x);
	bullet();
	~bullet();
	void p_bull_mv(void);
	void e_bull_mv(void);
	void display(void);
	int get_active(void);
	void shot(WINDOW * win, int x, int y);
	void init_bull(WINDOW * win, int y, int x);
private:
	WINDOW * curwin;
	int active;
	int x_b;
	int y_b;
	int max_x;
	int max_y;
};

#endif