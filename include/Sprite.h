#ifndef _SPRITE_H_
#define _SPRITE_H_

#include <SDL.h>

class Sprite {
    public:
        Sprite();

        static SDL_Surface* Load(const char* File);
        static bool Draw(SDL_Surface* Dest, SDL_Surface* Src, int X, int Y);
        static bool Draw(SDL_Surface* Dest, SDL_Surface* Src, int X, int Y, int X2, int Y2, int W, int H);
};

#endif
