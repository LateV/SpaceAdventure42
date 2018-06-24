#include "player.hpp"

const bool player::body[4][10] = {
		{false, false, false, true, true, false, false, false, false, false},
		{false, false, false, true, false, true, true, true, true, false},
		{true, true, true, true, true, true, true, true, true, true},
		{false, false, false, true, true, true, false, false, false, false}
};
player::player(WINDOW * win,int y, int x)
{
	curr_shot = 0;
	int i = 0;
	this->curwin = win;
	x_l = x;
	y_l = y;
	p_bull = new bullet[1000];

	while(i < 1000)
	{
		p_bull[i].init_bull(curwin);
		i++;
	}
	getmaxyx(this->curwin, this->max_y, this->max_x);
	keypad(this->curwin, true);
}

player::~player()
{
	delete[] p_bull;
}
void player::mvup()
{
	int i = 0;
	int j = 0;

	while(i < 10)
	{
		while(j < 4)
		{

				mvwaddch(curwin, y_l + j, x_l + i, ' ');
			j++;
		}
		j = 0;
		i++;
	}
	y_l--;
	if(y_l < 1)
		y_l = 1;
}

void player::mvdown()
{
	int i = 0;
	int j = 0;

	while(i < 10)
	{
		while(j < 4)
		{	

				mvwaddch(curwin, y_l + j, x_l + i, ' ');
			j++;
		}
		j = 0;
		i++;
	}
	y_l++;
	if(y_l > max_y - 5)
		y_l = max_y - 5;
}

void player::mvleft()
{
	int i = 0;
	int j = 0;

	while(i < 10)
	{
		while(j < 4)
		{
				mvwaddch(curwin, y_l + j, x_l + i, ' ');
			j++;
		}
		j = 0;
		i++;
	}
	x_l--;
	if(x_l < 1)
		x_l = 1;
}

void player::mvright()
{
	int i = 0;
	int j = 0;

	while(i < 10)
	{
		while(j < 4)
		{
				mvwaddch(curwin, y_l + j, x_l + i, ' ');
			j++;
		}
		j = 0;
		i++;
	}	
	x_l++;
	if(x_l > max_x - 11)
		x_l = max_x - 11;
}

int  player::get_mv()
{
	nodelay(this->curwin, true);
	int mv = wgetch(curwin);
	switch(mv)
	{
		case ' ':
			p_bull[curr_shot].shot(x_l + 9, y_l + 2);
			curr_shot++;
			break;
		case 27:
			wclear(this->curwin);
			wrefresh(this->curwin);
			exit(0);
			break;
		case KEY_UP:
			mvup();
			break;
		case KEY_LEFT:
			mvleft();
			break;
		case KEY_DOWN:
			mvdown();
			break;
		case KEY_RIGHT:
			mvright();
			break;
		default:
			break;
	}
	return(mv);
}

void player::display()
{
	int i = 0;

	nodelay(curwin, true);
	while(i < 1000)
	{
		if(p_bull[i].get_active() == 1)
		{
			p_bull[i].p_bull_mv();
		}
		p_bull[i].display();
		i++;
	}
	mvwaddch(curwin, y_l, x_l + 3, '_');
	mvwaddch(curwin, y_l, x_l + 4, '_');

	mvwaddch(curwin, y_l + 1, x_l + 3, '\\');
	mvwaddch(curwin, y_l + 1, x_l + 5, '\\');
	mvwaddch(curwin, y_l + 1, x_l + 6, '_');
	mvwaddch(curwin, y_l + 1, x_l + 7, '_');
	mvwaddch(curwin, y_l + 1, x_l + 8, '_');

	mvwaddch(curwin, y_l + 2, x_l, '#');
	mvwaddch(curwin, y_l + 2, x_l + 1, '#');
	mvwaddch(curwin, y_l + 2, x_l + 2, '#');
	mvwaddch(curwin, y_l + 2, x_l + 3, '[');
	mvwaddch(curwin, y_l + 2, x_l + 4, '=');
	mvwaddch(curwin, y_l + 2, x_l + 5, '=');
	mvwaddch(curwin, y_l + 2, x_l + 6, '_');
	mvwaddch(curwin, y_l + 2, x_l + 7, '_');
	mvwaddch(curwin, y_l + 2, x_l + 8, '_');
	mvwaddch(curwin, y_l + 2, x_l + 9, '>');

	mvwaddch(curwin, y_l + 3, x_l + 3, '/');
	mvwaddch(curwin, y_l + 3, x_l + 4, '_');
	mvwaddch(curwin, y_l + 3, x_l + 5, '/');

}

int player::getXL() {
	return this->x_l;
}

int player::getYL() {
	return this->y_l;
}
