/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zytrams <zytrams@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 13:05:37 by djast             #+#    #+#             */
/*   Updated: 2019/11/18 21:26:34 by zytrams          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

t_sdl	*init_editor(void)
{
	t_sdl	*sdl;

	sdl = (t_sdl *)malloc(sizeof(t_sdl));
	init_sdl(sdl);
	init_grid(sdl->grid_field);
	redraw(sdl);
	return (sdl);
}

int		run_editor(t_sdl *sdl)
{
	SDL_RenderPresent(sdl->renderer);
	big_loop(sdl);
}

void	stop_editor(t_sdl *sdl)
{
	SDL_DestroyWindow(sdl->window);
}
