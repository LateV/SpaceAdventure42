/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburlach <lburlach@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 13:27:00 by lburlach          #+#    #+#             */
/*   Updated: 2018/06/23 21:44:36 by lburlach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "space_fantasy.h"
#include "Window.h"
#include "Game.h"

int 	main(void)
{
	Window * init_win = new Window();
	Game * game = new Game(init_win);

	init_win->introduct();
	if(init_win->startButton())
	{
		delete init_win;
		delete game;
		return 0;
	}
	init_win->clearWindow();
	while (wgetch(init_win->getWinPtr()) != 10) {
		game->background2();
		wrefresh(init_win->getWinPtr());
	}
	getch();
//	game->background();
	delete init_win;
	delete game;
	return (0);
}
