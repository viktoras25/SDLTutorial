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

    if((Test = Sprite::Load("./gfx/yoshi.bmp")) == NULL) {
        return false;
    }

    Sprite::Transparent(Test, 255, 0, 255);
    Anim_Yoshi.MaxFrames = 8;

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

void App::Event(SDL_Event* Evt) {
    Event::Handle(Evt);
}

void App::Loop() {
    Anim_Yoshi.Animate();
}

void App::Render() {
    SDL_FillRect(Screen, NULL, 0x000000);
    Sprite::Draw(Screen, Test, 290, 220, 0, Anim_Yoshi.GetCurrentFrame() * 64, 64, 64);

    SDL_Flip(Screen);
}

void App::Cleanup() {
    SDL_FreeSurface(Test);
    SDL_FreeSurface(Screen);
    SDL_Quit();
}

void App::Exit() {
    Running = false;
}
