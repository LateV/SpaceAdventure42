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

void bullet::shot(int x, int y)
{
	active = 0;
	x_b = x;
	y_b = y;
}


void bullet::p_bull_mv()
{
	x_b++;
	if(x_b > max_x)
}