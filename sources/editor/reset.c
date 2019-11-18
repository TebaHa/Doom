/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zytrams <zytrams@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 10:48:39 by eharrag-          #+#    #+#             */
/*   Updated: 2019/11/18 21:23:26 by zytrams          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

void	delete_sprites(t_ed_sprite *sprites)
{
	while (sprites != NULL)// доделать
	{
		sprites->type = 0;
		sprites->x = 0;
		sprites->y = 0;
		sprites = sprites->next;
	}
}

void	delete_player(t_ed_point *player)
{
	player->x = 0;
	player->y = 0;
}

void	delete_point(t_ed_sector *sector)
{
	sector->point[sector->size - 1].x = 0;
	sector->point[sector->size - 1].y = 0;
	sector->size--;
}

void	reset(t_ed_sector **head, t_ed_point *player, t_ed_sprite *sprites)
{
	t_ed_sector **prev;
	t_ed_sector **cur;

	prev = head;
	cur = &((*head)->next);
	while (*cur != NULL)
	{
		free(*prev);
		*prev = *cur;
		*cur = (*cur)->next;
	}
	ft_bzero((*prev)->point, 100);
	(*prev)->size = 0;
	delete_player(player);
	delete_sprites(sprites);
}
