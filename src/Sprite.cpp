#include "Sprite.h"

Sprite::Sprite() {
}

SDL_Surface* Sprite::Load(const char* File) {
    SDL_Surface* Temp = NULL;
    SDL_Surface* Result = NULL;

    if((Temp = SDL_LoadBMP(File)) == NULL) {
        return NULL;
    }

    Result = SDL_DisplayFormat(Temp);
    SDL_FreeSurface(Temp);

    return Result;
}

bool Sprite::Draw(SDL_Surface* Dest, SDL_Surface* Src, int X, int Y) {
    if(Dest == NULL || Src == NULL) {
        return false;
    }

    SDL_Rect Area;
    Area.x = X;
    Area.y = Y;

    SDL_BlitSurface(Src, NULL, Dest, &Area);

    return true;
}

bool Sprite::Draw(SDL_Surface* Dest, SDL_Surface* Src, int X, int Y, int X2, int Y2, int W, int H) {
    if(Dest == NULL || Src == NULL) {
        return false;
    }

    SDL_Rect DestArea;

    DestArea.x = X;
    DestArea.y = Y;

    SDL_Rect SrcArea;

    SrcArea.x = X2;
    SrcArea.y = Y2;
    SrcArea.w = W;
    SrcArea.h = H;

    SDL_BlitSurface(Src, &SrcArea, Dest, &DestArea);

    return true;
}
