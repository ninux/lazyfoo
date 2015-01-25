#include <SDL2/SDL.h>
#include <stdbool.h>
#include "sdladdon.h"
#include "debug.h"
#include "error.h"
#include "settings.h"

bool init(SDL_Window **window, SDL_Surface **surface, char *title)
{
	bool success = true;

	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		print_sdl_error();
		success = false;
	}

	*window = SDL_CreateWindow(title,
				  SDL_WINDOWPOS_UNDEFINED,
				  SDL_WINDOWPOS_UNDEFINED,
				  640,
				  480,
				  SDL_WINDOW_SHOWN);
	if (*window == NULL) {
		print_sdl_error();
		success = false;
	} else {
		*surface = SDL_GetWindowSurface(*window);
		if (*surface == NULL) {
			print_sdl_error();
			success = false;
		}
	}

	return success;
}

bool load_bitmap(SDL_Surface **surface, char *filename)
{
	bool success = true;

	*surface = SDL_LoadBMP(filename);
	if (*surface == NULL) {
		print_sdl_error();
		success = false;
	}

	return success;
}
