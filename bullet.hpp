#ifndef BULLET_HPP
#define BULLET_HPP

#include "space_fantasy.h"

#define GRASS_PAIR     1
#define EMPTY_PAIR     1
#define WATER_PAIR     2
#define MOUNTAIN_PAIR  3
#define PLAYER_PAIR    4

class bullet{
public:
	bullet(void);
	bullet(const bullet &copy);
	bullet(WINDOW * win, int who);
	~bullet(void);

	int get_active(void) const;
	WINDOW *get_curwin(void) const;
	int get_x_b(void) const;
	int get_y_b(void) const;
	int get_max_x(void) const;
	int get_max_y(void) const;

	void p_bull_mv(void);
	void e_bull_mv(void);
	void display(void);
	void shot(int x, int y);
	void init_bull(WINDOW * win, int who);
	bullet& operator=(const bullet& op);
private:
	int who;
	WINDOW * curwin;
	int active;
	int x_b;
	int y_b;
	int max_x;
	int max_y;
};

#endif