#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "color.h"
#include "debug.h"
#include "error.h"
#include "settings.h"
#include "sdladdon.h"

SDL_Window *window = NULL;
SDL_Surface *surface = NULL;
SDL_Surface *image = NULL;

char figure_1[] = FIGURE_DIR"/eye_1.png";
char figure_2[] = FIGURE_DIR"/eye_2.png";
char title[] = "bitmaps";

int main(char argc, char **argv)
{
	SDL_Event events;
	bool quit = false;

	if (!init(&window, &surface, title)) {
		printf("Failed to initialize!\n");
		return -1;
	}

	if (!load_bitmap(&image, figure_1)) {
		printf("Failed to load the image!\n");
		if (image != NULL) {
			SDL_FreeSurface(image);
		}
		SDL_DestroyWindow(window);
		SDL_Quit();
		return -1;
	}

	SDL_BlitSurface(image, NULL, surface, NULL);
	SDL_Delay(500);
	SDL_UpdateWindowSurface(window);

	while (!quit) {
		while (SDL_PollEvent(&events) != 0) {
			if (events.type == SDL_QUIT)
			{
				quit = true;
			}
		}
	}

	SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format,
					       0x00, 0x00, 0x00));
	load_bitmap(&image, figure_2);

	SDL_BlitSurface(image, NULL, surface, NULL);
	SDL_Delay(500);
	SDL_UpdateWindowSurface(window);

	SDL_Delay(2000);

	SDL_FreeSurface(image);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}
