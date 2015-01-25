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
char bitmap[] = FIGURE_DIR"/eye.png";
char title[] = "bitmaps";

int main(char argc, char **argv)
{
	if (!init(&window, &surface, title)) {
		printf("Failed to initialize!\n");
		return -1;
	}

	if (!load_bitmap(&image, bitmap)) {
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

	SDL_Delay(2000);

	SDL_FreeSurface(image);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}
