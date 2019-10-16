/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_stuff.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eharrag- <eharrag-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 11:16:02 by eharrag-          #+#    #+#             */
/*   Updated: 2019/10/16 09:59:57 by eharrag-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

void	set_sprite(t_sdl *sdl)
{
	(void) sdl;
}

void	set_player(t_sdl *sdl, int x, int y)
{
	if (check_intersection(sdl->sectors, 0, 0, x, y) % 2 == 1)
	{
		sdl->player->x = x;
		sdl->player->y = y;
		printf("Player is available\n");
		add_command(&(sdl->commands), PLAYER_TYPE);
	}
}

void	make_player_or_sprite(t_sdl *sdl)
{
	int i;

	i = 0;
	SDL_GetMouseState(&sdl->mouse_position.x, &sdl->mouse_position.y);
	if (sdl->mouse_position.x > 94 && sdl->mouse_position.x < (int)SIZE_WIN_X * 0.8 - 94
			&& sdl->mouse_position.y > 101 && sdl->mouse_position.y < SIZE_WIN_Y - 101)
	{
		if (sdl->type_pressed == PLAYER_TYPE)
			set_player(sdl, sdl->mouse_position.x, sdl->mouse_position.y);
		else if (sdl->type_pressed == SPRITE_TYPE)
			set_sprite(sdl);
	}
}
