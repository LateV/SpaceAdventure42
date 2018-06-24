#include "player.hpp"

player::player(WINDOW * win,int y, int x)
{
	this->curwin = win;
	x_l = x;
	y_l = y;

	body[0][0] = 0;
	body[0][1] = 0;
	body[0][2] = 0;
	body[0][3] = 1;
	body[0][4] = 1;
	body[0][5] = 0;
	body[0][6] = 0;
	body[0][7] = 0;
	body[0][8] = 0;
	body[0][9] = 0;

	body[1][0] = 0;
	body[1][1] = 0;
	body[1][2] = 0;
	body[1][3] = 1;
	body[1][4] = 0;
	body[1][5] = 1;
	body[1][6] = 1;
	body[1][7] = 1;
	body[1][8] = 1;
	body[1][9] = 0;
	
	body[2][0] = 1;
	body[2][1] = 1;
	body[2][2] = 1;
	body[2][3] = 1;
	body[2][4] = 1;
	body[2][5] = 1;
	body[2][6] = 1;
	body[2][7] = 1;
	body[2][8] = 1;
	body[2][9] = 1;

	body[3][0] = 0;
	body[3][1] = 0;
	body[3][2] = 0;
	body[3][3] = 1;
	body[3][4] = 1;
	body[3][5] = 1;
	body[3][6] = 0;
	body[3][7] = 0;
	body[3][8] = 0;
	body[3][9] = 0;

	getmaxyx(this->curwin, this->max_y, this->max_x);
	keypad(this->curwin, true);
}

player::~player()
{

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
	if(y_l < min_y)
		y_l = min_y;
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
	if(y_l > max_y - 4)
		y_l = max_y - 4;
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
	if(x_l < min_x)
		x_l = min_x;
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
	if(x_l > max_x - 10)
		x_l = max_x - 10;
}

int  player::get_mv()
{
	nodelay(this->curwin, true);
	int mv = wgetch(curwin);
	switch(mv)
	{
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
	nodelay(curwin, true);
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


