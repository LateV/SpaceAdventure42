/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburlach <lburlach@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 13:27:00 by lburlach          #+#    #+#             */
/*   Updated: 2018/06/24 18:28:06 by lburlach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "space_fantasy.h"
#include "Window.h"
#include "Game.h"
#include "player.hpp"

int 	main(void)
{
	Window * init_win = new Window();
	Game * game = new Game(init_win);
	player * pl = new player(init_win->getWinPtr(), init_win->getYMax()/2, 2);

	init_win->introduct();
	if(init_win->startButton())
	{
		delete init_win;
		delete pl;
		delete game;
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
		delay_output(50);
		nodelay(init_win->getWinPtr(), true);
	}
//	game->background();
	delete init_win;
	delete game;
	delete pl;
	return (0);
}
