#ifndef _APP_H_
#define _APP_H_

#include <SDL.h>

#include "Event.h"
#include "Sprite.h"
#include "Animation.h"
#include "Entity.h"

class App : public Event {
    private:
        bool            Running;
        SDL_Surface*    Screen;
        SDL_Surface*    Test;

        Entity         Entity1;
        Entity         Entity2;

    public:
        App();
        int Execute();

        bool Init();
        void Event(SDL_Event* Evt);
        void Loop();
        void Render();
        void Cleanup();
        void Exit();
};

#endif
