#include "bullet.hpp"

bullet::bullet()
{

}

bullet::bullet(WINDOW * win)
{
	active = 0;
	x_b = 0;
	y_b = 0;
	getmaxyx(win, max_y, max_x);
}

bullet::~bullet()
{

}

void bullet::init_bull(WINDOW * win)
{
	active = 0;
	x_b = 0;
	y_b = 0;
	curwin = win;
	getmaxyx(curwin, max_y, max_x);
}

int bullet::get_active(void)
{
	return(this->active);
}

void bullet::shot(int x, int y)
{
	active = 1;
	x_b = x;
	y_b = y;
	getmaxyx(curwin, max_y, max_x);
}

void bullet::p_bull_mv()
{
	mvwaddch(curwin, x_b , y_b , ' ');
	x_b++;
	if(x_b > max_x)
		active = 0;
}
void bullet::e_bull_mv()
{
	x_b--;
	if(x_b < 0)
		active = 0;
}
void bullet::display(void)
{
	if(active == 1)
	{
		mvwaddch(curwin, y_b, x_b - 1, ' ');
		mvwaddch(curwin, y_b, x_b , 'o');
	}
}
