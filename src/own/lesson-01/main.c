#include <SDL2/SDL.h>
#include <stdio.h>
#include "settings.h"
#include "color.h"

int main(char argc, char **argv)
{
	SDL_Window *window = NULL;
	SDL_Surface *screen_surface = NULL;
	struct RGB_COLOR bg_color;

	bg_color.RED = 0x55;
	bg_color.GREEN	= 0x55;
	bg_color.BLUE = 0x55;

	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf("SDL could not initialize! SDL_Error: %s\n",
		       SDL_GetError());
	} else {
		window = SDL_CreateWindow("ninux does SDL",
					  SDL_WINDOWPOS_UNDEFINED,
					  SDL_WINDOWPOS_UNDEFINED,
					  SCREEN_WIDTH,
					  SCREEN_HEIGHT,
					  SDL_WINDOW_SHOWN);
		if (window == NULL) {
			printf("Window could not be created! SDL_Error: %s\n",
			       SDL_GetError());
		} else {
			screen_surface = SDL_GetWindowSurface(window);
			SDL_FillRect(screen_surface, NULL,
				     SDL_MapRGB(screen_surface->format,
						bg_color.RED,
						bg_color.GREEN,
						bg_color.BLUE));
			SDL_UpdateWindowSurface(window);
			SDL_Delay(TIMEOUT);
		}
	}

	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}
