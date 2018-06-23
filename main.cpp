#include "player.hpp"

int main(int argc, char ** argv)
{
	setlocale(LC_ALL, "");
	initscr();
	noecho();	


	WINDOW * win = newwin(50, 50, 1, 1);	
	refresh();
	wrefresh(win);
	player  * player1 = new player(win, 10 , 10);
	do {
		player1->display();
		wrefresh(win);
		// wclear(win);
	}while(player1->get_mv() != 'q');
	player1->display();
	endwin();
	// deallocates memory and ncueses
	return(0);
}
