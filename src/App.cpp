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

    if(Entity1.Load("./gfx/yoshi.bmp", 64, 64, 8) == false) {
        return false;
    }

    if(Entity2.Load("./gfx/yoshi.bmp", 64, 64, 8) == false) {
        return false;
    }

    Entity2.X = 100;

    Entity::EntityList.push_back(&Entity1);
    Entity::EntityList.push_back(&Entity2);

    Sprite::Transparent(Test, 255, 0, 255);

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
    for(int i = 0;i < Entity::EntityList.size();i++) {
        if(!Entity::EntityList[i]) continue;

        Entity::EntityList[i]->Loop();
    }
}

void App::Render() {
    SDL_FillRect(Screen, NULL, 0x000000);

    for(int i = 0;i < Entity::EntityList.size();i++) {
        if(!Entity::EntityList[i]) continue;

        Entity::EntityList[i]->Render(Screen);
    }

    SDL_Flip(Screen);
}

void App::Cleanup() {
    for(int i = 0;i < Entity::EntityList.size();i++) {
        if(!Entity::EntityList[i]) continue;

        Entity::EntityList[i]->Cleanup();
    }

    Entity::EntityList.clear();

    SDL_FreeSurface(Test);
    SDL_FreeSurface(Screen);
    SDL_Quit();
}

void App::Exit() {
    Running = false;
}
