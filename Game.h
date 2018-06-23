/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburlach <lburlach@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 16:29:00 by lburlach          #+#    #+#             */
/*   Updated: 2018/06/23 20:03:50 by lburlach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef D04_GAME_H
#define D04_GAME_H

#include "space_fantasy.h"
#include "Window.h"

class Game {
public:
	Game(void);
	Game(const Window* win);
	Game(Game const &src);
	~Game(void);
	Game &operator=(Game const &rhs);
	const Window * getPtrOnWin(void) const;
	void background(void);

private:
	const Window* _win;
	std::string * _hm;
	std::string * _tmp;
};


#endif //D04_GAME_H
