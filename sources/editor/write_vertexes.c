/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_vertexes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zytrams <zytrams@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 16:19:28 by djast             #+#    #+#             */
/*   Updated: 2019/11/18 21:23:32 by zytrams          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

int			write_vertexes_wall(t_sdl *sdl, int fd)
{
	t_ed_sector	*cur_sector;
	int			i;
	int			id;
	char		*char_id;

	cur_sector = sdl->sectors;
	id = 0;
	while (cur_sector != NULL && cur_sector->size != 0)
	{
		i = 0;
		printf("%d\n", cur_sector->size);
		while (i != cur_sector->size)
		{
			write(fd, "vertex:	", 8);
			char_id = ft_itoa(id++);
			write(fd, char_id, ft_strlen(char_id));
			free(char_id);
			write(fd, "	", 1);
			char_id = ft_itoa(cur_sector->point[i].x * 4);
			write(fd, char_id, ft_strlen(char_id));
			free(char_id);
			write(fd, "	", 1);
			char_id = ft_itoa(cur_sector->point[i].y * 4);
			write(fd, char_id, ft_strlen(char_id));
			free(char_id);
			write(fd, "	", 1);
			char_id = ft_itoa(cur_sector->z);
			write(fd, char_id, ft_strlen(char_id));
			free(char_id);
			write(fd, "\n", 1);
			i++;
		}
		write(fd, "\n", 1);
		cur_sector = cur_sector->next;
	}
	// write(fd, "\n", 1);
	return (id);
}

void		write_to_file(int fd, char *data, int numdata)
{
	data = ft_itoa(numdata);
	write(fd, data, ft_strlen(data));
	free(data);
}

void		write_vertexes_sprite(t_sdl *sdl, int fd, int last_id)
{
	t_ed_sprite	*cur_sprite;
	int			id;
	char		*char_id = NULL;

	cur_sprite = sdl->sprites;
	id = last_id;
	while (cur_sprite != NULL)
	{
		write(fd, "vertex:	", 8);
		write_to_file(fd, char_id, id++);
//		char_id = ft_itoa(id++);
//		write(fd, char_id, ft_strlen(char_id));
//		free(char_id);
		write(fd, "	", 1);
		write_to_file(fd, char_id, cur_sprite->x * 4);
		// char_id = ft_itoa(cur_sprite->x * 4);
		// write(fd, char_id, ft_strlen(char_id));
		// free(char_id);
		write(fd, "	", 1);
		write_to_file(fd, char_id, cur_sprite->y * 4);
		// char_id = ft_itoa(cur_sprite->y * 4);
		// write(fd, char_id, ft_strlen(char_id));
		// free(char_id);
		write(fd, "	", 1);
		write_to_file(fd, char_id, sdl->sectors->z);
		// char_id = ft_itoa(sdl->sectors->z);
		// write(fd, char_id, ft_strlen(char_id));
		// free(char_id);
		write(fd, "\n", 1);
		cur_sprite = cur_sprite->next;
	}
	write(fd, "\n\n", 3);
}
