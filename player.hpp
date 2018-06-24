#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <ncurses.h>
#include <iostream>
#include "bullet.hpp"

class player {
public:
	player(WINDOW * win, int y, int x);
	~player();
	void mvup(void);
	void mvdown(void);
	void mvleft(void);
	void mvright(void);
	void display(void);
	int get_mv(void);
	int getXL(void);
	int getYL(void);
	static const bool body [4][10];
private:
	int curr_shot;
	bullet *p_bull;
	WINDOW * curwin;
	int x_l;
	int y_l;
	int max_y; //max size of win.
	int max_x;
};

#endif