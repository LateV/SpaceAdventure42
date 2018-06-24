#ifndef BULLET_HPP
#define BULLET_HPP

#include <ncurses.h>
#include <locale>
#include <string>
#include <iostream>

class bullet{
public:
	bullet(WINDOW * win);
	bullet();
	~bullet();
	void p_bull_mv(void);
	void e_bull_mv(void);
	void display(void);
	int get_active(void);
	void shot(int x, int y);
	void init_bull(WINDOW * win);
private:
	WINDOW * curwin;
	int active;
	int x_b;
	int y_b;
	int max_x;
	int max_y;
};

#endif