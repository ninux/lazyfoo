#include <SDL2/SDL.h>
#include <stdio.h>
#include "settings.h"
#include "color.h"
#include "debug.h"
#include "error.h"

int main(char argc, char **argv)
{
	SDL_Window *window = NULL;
	SDL_Surface *screen_surface = NULL;
	RGB_COLOR *bg_color;

	bg_color = create_color(0x55, 0x66, 0x77);

	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		print_sdl_error();
	} else {
		window = SDL_CreateWindow("ninux does SDL",
					  SDL_WINDOWPOS_UNDEFINED,
					  SDL_WINDOWPOS_UNDEFINED,
					  SCREEN_WIDTH,
					  SCREEN_HEIGHT,
					  SDL_WINDOW_SHOWN);
		if (window == NULL) {
			print_sdl_error();
		} else {
			screen_surface = SDL_GetWindowSurface(window);
			SDL_FillRect(screen_surface, NULL,
				     SDL_MapRGB(screen_surface->format,
						bg_color->RED,
						bg_color->GREEN,
						bg_color->BLUE));
			SDL_UpdateWindowSurface(window);
			SDL_Delay(TIMEOUT);
		}
	}

	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}
