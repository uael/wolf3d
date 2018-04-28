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

#include <SDL.h>
#include <wolf3d.h>

int main(int argc, char* argv[]) {

	int leftMouseButtonDown = 0;
	int quit = 0;
	SDL_Event event;

	(void)argc;
	(void)argv;
	SDL_Init(SDL_INIT_VIDEO);

	SDL_Window * window = SDL_CreateWindow("SDL2 Pixel Drawing",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, 0);

	SDL_Renderer * renderer = SDL_CreateRenderer(window, -1, 0);
	SDL_Texture * texture = SDL_CreateTexture(renderer,
		SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STATIC, 640, 480);
	Uint32 pixels[640 * 480];

	memset(pixels, 255, 640 * 480 * sizeof(Uint32));

	while (!quit)
	{
		SDL_UpdateTexture(texture, NULL, pixels, 640 * sizeof(Uint32));

		SDL_WaitEvent(&event);

		switch (event.type)
		{
			case SDL_QUIT:
				quit = 1;
				break;
			case SDL_MOUSEBUTTONUP:
				if (event.button.button == SDL_BUTTON_LEFT)
					leftMouseButtonDown = 0;
				break;
			case SDL_MOUSEBUTTONDOWN:
				if (event.button.button == SDL_BUTTON_LEFT)
					leftMouseButtonDown = 1;
			case SDL_MOUSEMOTION:
				if (leftMouseButtonDown)
				{
					int mouseX = event.motion.x;
					int mouseY = event.motion.y;
					pixels[mouseY * 640 + mouseX] = 0;
				}
				break;
		}

		SDL_RenderClear(renderer);
		SDL_RenderCopy(renderer, texture, NULL, NULL);
		SDL_RenderPresent(renderer);
	}

	SDL_DestroyTexture(texture);
	SDL_DestroyRenderer(renderer);

	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}
