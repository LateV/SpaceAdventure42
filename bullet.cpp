#include "bullet.hpp"

bullet::bullet(){}
bullet::bullet(WINDOW * win, int who)
{
	this->who = who;
	active = 0;
	x_b = 0;
	y_b = 0;
	getmaxyx(win, max_y, max_x);
}
bullet::~bullet(){}

WINDOW *bullet::get_curwin(void) const
{
	return(this->curwin);
}

int bullet::get_x_b(void) const
{
	return(this->x_b);
}

int bullet::get_y_b(void) const
{
	return(this->y_b);
}
int bullet::get_max_x(void) const
{
	return(max_x);
}
int bullet::get_max_y(void) const
{
	return(max_y);
}
int bullet::get_active(void) const
{
	return(this->active);
}
void bullet::set_x_b(void)
{
	this->x_b = this->max_x;
}


bullet &bullet::operator=(const bullet &op)
{
	this->curwin = op.get_curwin();
	this->x_b = op.get_x_b();
	this->y_b = op.get_y_b();
	this->max_x = op.get_max_x();
	this->max_y = op.get_max_y();
	return(*this);
}

void bullet::init_bull(WINDOW * win, int who)
{
	this->who = who;
	active = 0;
	x_b = 0;
	y_b = 0;
	curwin = win;
	getmaxyx(curwin, max_y, max_x);
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
	x_b--;
	if(x_b < 0)
		active = 0;
}

void bullet::display(void)
{


	if(active == 1 && x_b < max_x - 1 && who == 0)
	{
		mvwaddch(curwin, y_b, x_b - 1, ' ');
		mvwaddch(curwin, y_b, x_b , 'o');
	}
	if(active == 1 && x_b > 1 && who == 1)
	{
		attron(COLOR_PAIR(2));
		mvwaddch(curwin, y_b, x_b , '<');
		mvwaddch(curwin, y_b, x_b + 2, ' ');
	}
}