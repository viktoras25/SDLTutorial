#include "App.h"

App::App() {
    Test = NULL;
    Screen = NULL;
    Running = true;
}

bool App::Init() {
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        return false;
    }

    if((Screen = SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE | SDL_DOUBLEBUF)) == NULL) {
        return false;
    }

    if((Test = Sprite::Load("image.bmp")) == NULL) {
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

void App::Render() {
    Sprite::Draw(Screen, Test, 0, 0);
    Sprite::Draw(Screen, Test, 70, 110, 90, 90, 50, 50);

    SDL_Flip(Screen);
}

void App::Cleanup() {
    SDL_FreeSurface(Test);
    SDL_FreeSurface(Screen);
    SDL_Quit();
}
