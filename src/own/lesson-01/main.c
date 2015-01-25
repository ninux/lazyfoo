#include <SDL2/SDL.h>
#include <stdio.h>
#include "settings.h"
#include "color.h"
#include "debug.h"
#include "error.h"

int main(char argc, char **argv)
{
	SDL_Window *window = NULL;
	SDL_Surface *surface = NULL;
	SDL_Surface *drawing_red = NULL;
	SDL_Surface *drawing_green = NULL;
	SDL_Surface *drawing_blue = NULL;
	RGB_COLOR *red, *green, *blue;
	int result;

	red = create_color(0xFF, 0x00, 0x00);
	green = create_color(0x00, 0xFF, 0x00);
	blue = create_color(0x00, 0x00, 0xFF);

	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		print_sdl_error();
	}

	// create a window
	window = SDL_CreateWindow("ninux does SDL",
				  SDL_WINDOWPOS_UNDEFINED,
				  SDL_WINDOWPOS_UNDEFINED,
				  SCREEN_WIDTH,
				  SCREEN_HEIGHT,
				  SDL_WINDOW_SHOWN);
	if (window == NULL) {
		print_sdl_error();
		SDL_Quit();
		return -1;
	}

	// create a surface associated with the window
	surface = SDL_GetWindowSurface(window);
	if (surface == NULL) {
		print_sdl_error();
		SDL_DestroyWindow(window);
		SDL_Quit();
		return -1;
	}

	// for some reason it won't work if here's not a delay - WHY???
	SDL_Delay(100);

	// create surfaces for drawing & filling the rectangles
	drawing_red = SDL_CreateRGBSurface(0, SCREEN_WIDTH, SCREEN_HEIGHT,
					   32, 0, 0, 0, 0);
	drawing_green = SDL_CreateRGBSurface(0, SCREEN_WIDTH, SCREEN_HEIGHT,
					   32, 0, 0, 0, 0);
	drawing_blue = SDL_CreateRGBSurface(0, SCREEN_WIDTH, SCREEN_HEIGHT,
					   32, 0, 0, 0, 0);

	// fill the drawing surfaces with the corresponding colors
	SDL_FillRect(drawing_red, NULL, SDL_MapRGB(surface->format,
					       red->RED,
					       red->GREEN,
					       red->BLUE));

	SDL_FillRect(drawing_green, NULL, SDL_MapRGB(surface->format,
					       green->RED,
					       green->GREEN,
					       green->BLUE));

	SDL_FillRect(drawing_blue, NULL, SDL_MapRGB(surface->format,
					       blue->RED,
					       blue->GREEN,
					       blue->BLUE));


	// copy all the drawings to the window surface and update the window
	SDL_BlitSurface(drawing_red, NULL, surface, NULL);
	SDL_UpdateWindowSurface(window);
	SDL_Delay(TIMEOUT);

	SDL_BlitSurface(drawing_green, NULL, surface, NULL);
	SDL_UpdateWindowSurface(window);
	SDL_Delay(TIMEOUT);

	SDL_BlitSurface(drawing_blue, NULL, surface, NULL);
	SDL_UpdateWindowSurface(window);
	SDL_Delay(TIMEOUT);

	// free the allocated colors
	free(red);
	free(green);
	free(blue);

	// clean up the SDL stuff
	SDL_FreeSurface(drawing_red);
	SDL_FreeSurface(drawing_green);
	SDL_FreeSurface(drawing_blue);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}
