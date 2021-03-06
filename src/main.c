/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 00:00:42 by alucas-           #+#    #+#             */
/*   Updated: 1970/01/01 00:00:42 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>

#undef main

int	main(int ac, char *av[])
{
	t_game	game;
	t_world	world;
	t_me	me;

	SDL_ClearError();
	ft_bzero(&game, sizeof(t_game));
	if (world_init(&world, ac, av))
		return (game_quit(&game, "Unable to init world."));
	if (me_init(&me, &world, 0.8f))
		return (game_quit(&game, "There is no space left to place the player"));
	if (game_init(&game, &world, &me))
		return (game_quit(&game, "Unable to init game."));
	return (game_loop(&game));
}
