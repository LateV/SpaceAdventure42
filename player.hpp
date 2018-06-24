#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "space_fantasy.h"
#include "bullet.hpp"

class player {
public:
	player(void);
	player(const player &copy);
	player(WINDOW * win, int y, int x);
	~player(void);
	
	int get_x_l(void) const;
	int get_y_l(void) const;
	int get_max_y(void) const;
	int get_max_x(void) const;
	int get_curr_shot(void) const;
	bullet *get_p_bull(void) const;
	WINDOW *get_curwin(void) const;

	void mvup(void);
	void mvdown(void);
	void mvleft(void);
	void mvright(void);
	void display(void);
	int get_mv(void);
	player& operator=(const player& op);
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
