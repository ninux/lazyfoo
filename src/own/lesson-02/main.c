#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "color.h"
#include "debug.h"
#include "error.h"
#include "settings.h"
#include "sdladdon.h"

SDL_Window *window;
SDL_Surface *window_surface;
SDL_Surface *image;
char bitmap[] = "hello_world.bmp";

int main(char argc, char **argv)
{
	if (!init(window, window_surface, "loading a bitmap")) {
		printf("Failed to initialize!\n");
	} else {
		if (!load_bitmap(image, bitmap)) {
			printf("Failed to load the image!\n");
		} else {
			SDL_BlitSurface(image, NULL, window_surface, NULL);
			SDL_UpdateWindowSurface(window);
			SDL_Delay(2000);
		}
	}

	SDL_FreeSurface(image);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}
