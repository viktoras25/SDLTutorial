#include "App.h"

App::App() {
    Screen = NULL;
    Running = true;
}

bool App::Init() {
    if(SDL_Init(SDL_INIT_EVERYTHING) > 0) {
        return false;
    }

    if((Screen = SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE | SDL_DOUBLEBUF)) == NULL) {
        return false;
    }

    return true;
}

int App::Execute() {
    if(Init() == false) {
        return -1;
    }

    SDL_Event Evt;

    while(Running) {
        while(SDL_PollEvent(&Evt)) {
            Event(&Evt);
        }

        Loop();
        Render();
    }

    Cleanup();
    return 0;
}

int main(int argc, char* argv[]) {
    App App;
    return App.Execute();
}

void App::Event(SDL_Event* Event) {
    if(Event->type == SDL_QUIT) {
        Running = false;
    }
}

void App::Loop() {}
void App::Render() {}

void App::Cleanup() {
    SDL_Quit();
}
