/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburlach <lburlach@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 13:27:00 by lburlach          #+#    #+#             */
/*   Updated: 2018/06/24 19:41:55 by lburlach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "space_fantasy.h"
#include "Window.h"
#include "Game.h"
#include "Score.h"

int 	main(void)
{
	Window * init_win = new Window();
	Game * game = new Game(init_win);
	player * pl = new player(init_win->getWinPtr(), init_win->getYMax()/2, 2);
	Score * sc = new Score(init_win, 4, 30);


	refresh();
	init_win->introduct();
	if(init_win->startButton())
	{
		delete init_win;
		delete pl;
		delete game;
		delete sc;
		return 0;
	}
	init_win->clearWindow();
	game->create_foes(1000, pl);
//	wprintw(init_win->getWinPtr(), "ok");
	wrefresh(init_win->getWinPtr());
	while (42) {
		game->background2();
		game->display_foes();
		pl->get_mv();
		pl->display();
		wrefresh(init_win->getWinPtr());
		sc->display();
		box(sc->getScWin(), 0, 0);
		wrefresh(sc->getScWin());
		delay_output(30);
		noecho();
		nodelay(init_win->getWinPtr(), true);
		nodelay(sc->getScWin(), true);
	}
//	game->background();
	delete init_win;
	delete game;
	delete pl;
	delete sc;
	return (0);
}
