/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburlach <lburlach@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 13:27:00 by lburlach          #+#    #+#             */
/*   Updated: 2018/06/23 18:25:51 by lburlach         ###   ########.fr       */
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
	game->background();
	getch();
//	game->background();
	delete init_win;
	delete game;
	return (0);
}
