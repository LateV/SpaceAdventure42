#include "player.hpp"

int main(int argc, char ** argv)
{
	setlocale(LC_ALL, "");
	initscr();
	noecho();	


	WINDOW * win = newwin(100, 100, 1, 1);	
	refresh();
	wrefresh(win);
	player  * player1 = new player(win, 10 , 10);
	do
	{
		player1->display();
		wrefresh(win);
	}while(player1->get_mv() != 'q');

	endwin();
	// deallocates memory and ncueses
	return(0);
}
