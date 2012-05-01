#ifndef _APP_H_
#define _APP_H_

#include <SDL.h>

class App {
    private:
        bool    Running;
        SDL_Surface*    Screen;

    public:
        App();
        int Execute();

    public:
        bool Init();
        void Event(SDL_Event* Event);
        void Loop();
        void Render();
        void Cleanup();
};

#endif
