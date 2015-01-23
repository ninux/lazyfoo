# lazyfoo - notes

## Including the SDL Library on Linux
For Linux you have to include SDL2 with

```c
#include <SDL2/SDL.h>
```

instead of

```c
#include <SDL.h>
```

## Window appears tranparent
The window appears tranparent after the first run of the program.

I think this could be an issue caused by *awesome WM* but this is just a guess. 
