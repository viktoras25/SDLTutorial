#ifndef _APP_H_
#define _APP_H_

#include <SDL.h>

#include "Event.h"
#include "Sprite.h"

enum {
    GRID_TYPE_NONE = 0,
    GRID_TYPE_X,
    GRID_TYPE_O
};

class App : public Event {
    private:
        bool            Running;
        SDL_Surface*    Screen;

        SDL_Surface*    G;
        SDL_Surface*    X;
        SDL_Surface*    O;

        int             Grid[9];
        int CurrentPlayer;

    public:
        App();
        int Execute();

        bool Init();
        void Event(SDL_Event* Evt);
        void Loop();
        void Render();
        void Cleanup();
        void Exit();

    public:
        void Reset();
        void SetCell(int ID, int Type);
        void OnLButtonDown(int mX, int mY);
};

#endif
