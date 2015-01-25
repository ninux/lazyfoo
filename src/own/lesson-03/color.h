#ifndef COLOR_H
#define COLOR_H

typedef struct /* RGB_COLOR */ {
	int RED;
	int GREEN;
	int BLUE;
} RGB_COLOR;

RGB_COLOR *create_color(int red, int green, int blue);

#endif /* COLOR_H */
