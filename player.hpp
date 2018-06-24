#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <ncurses.h>
#include <locale>
#include <string>
#include <iostream>

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
private:
	WINDOW * curwin;
	int x_l;
	int y_l;
	int max_y; //max size of win.
	int max_x; //
	int min_y;
	int min_x;
	int body [4][10];
};

#endif