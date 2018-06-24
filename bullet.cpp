#include "bullet.cpp"

bullet::bullet()
{
	active = 0;
	x_b = 0;
	y_b = 0;
	getmaxyx(curwin, max_y, max_x);
}

bullet::~bullet()
{

}

void bullet::shot(WINDOW * win int x, int y)
{
	active = 1;
	curwin = win;
	x_b = x;
	y_b = y;
}

void bullet::p_bull_mv()
{
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
	mvwaddch(curwin, y_l + 2, x_l + 9, '>');
}
