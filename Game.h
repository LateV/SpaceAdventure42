/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburlach <lburlach@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 16:29:00 by lburlach          #+#    #+#             */
/*   Updated: 2018/06/24 12:03:11 by lburlach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef D04_GAME_H
#define D04_GAME_H

#include "space_fantasy.h"
#include "Window.h"
#include "Foe.h"

class Game {
public:
	Game(void);
	Game(const Window* win);
	Game(Game const &src);
	~Game(void);
	Game &operator=(Game const &rhs);
	const Window * getPtrOnWin(void) const;
	void background(void);
	void background2(void);
	void create_foes(int N, player * hm);
	void display_foes(void);

private:
	const Window* _win;
	int * _indeces;
	char * _tmp;
	int _map_iter;
	Foe * _Foes;
	int _foesIt;
	int _N;
	player * _pl;
};


#endif //D04_GAME_H
