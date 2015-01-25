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
The window won't update as it should. The bug seems to be either at awesome or at X11.
Forcing a delay (with `SDL_Delay()`) of about 100ms is a possible workaround.

### Some links to this issue
* [Awesome user report](https://awesome.naquadah.org/bugs/index.php?do=details&task_id=1167)
* [Bugzilla report](https://bugzilla.libsdl.org/show_bug.cgi?id=1948)
