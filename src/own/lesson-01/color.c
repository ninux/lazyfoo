#include <stdio.h>
#include <stdlib.h>
#include "color.h"
#include "debug.h"

RGB_COLOR *create_color(int red, int green, int blue)
{
	RGB_COLOR *color;

	color = (RGB_COLOR*)malloc(sizeof(RGB_COLOR));
	if (color == NULL) {
		dbgmsg(MEMORY_ALLOCATION_FAIL);
		return NULL;
	}

	color->RED = red;
	color->GREEN = green;
	color->BLUE = blue;
}
