#include "App.h"

App::App() {
    CurrentPlayer = 0;

    G = NULL;
    X = NULL;
    O = NULL;

    Screen = NULL;

    Running = true;
}

bool App::Init() {
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        return false;
    }

    if((Screen = SDL_SetVideoMode(600, 600, 32, SDL_HWSURFACE | SDL_DOUBLEBUF)) == NULL) {
        return false;
    }

    if((G = Sprite::Load("./gfx/grid.bmp")) == NULL) {
    return false;
    }

    if((X = Sprite::Load("./gfx/x.bmp")) == NULL) {
    return false;
    }

    if((O = Sprite::Load("./gfx/o.bmp")) == NULL) {
    return false;
    }

    Sprite::Transparent(X, 255, 0, 255);
    Sprite::Transparent(O, 255, 0, 255);

    Reset();

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

void App::Loop() {}

void App::Render() {
    Sprite::Draw(Screen, G, 0, 0);

    for(int i = 0;i < 9;i++) {
        int cX = (i % 3) * 200;
        int cY = (i / 3) * 200;

        if(Grid[i] == GRID_TYPE_X) {
            Sprite::Draw(Screen, X, cX, cY);
        }else
        if(Grid[i] == GRID_TYPE_O) {
            Sprite::Draw(Screen, O, cX, cY);
        }
    }

    SDL_Flip(Screen);
}

void App::Cleanup() {
    SDL_FreeSurface(G);
    SDL_FreeSurface(X);
    SDL_FreeSurface(O);
    SDL_FreeSurface(Screen);
    SDL_Quit();
}

void App::Exit() {
    Running = false;
}

void App::Reset() {
    for(int i = 0;i < 9;i++) {
        Grid[i] = GRID_TYPE_NONE;
    }
}

void App::SetCell(int ID, int Type) {
    if(ID < 0 || ID >= 9) return;
    if(Type < 0 || Type > GRID_TYPE_O) return;

    Grid[ID] = Type;
}

void App::OnLButtonDown(int mX, int mY) {
    int ID = mX / 200;
    ID = ID + ((mY / 200) * 3);

    if(Grid[ID] != GRID_TYPE_NONE) {
        return;
    }

    if(CurrentPlayer == 0) {
        SetCell(ID, GRID_TYPE_X);
        CurrentPlayer = 1;
    }else{
        SetCell(ID, GRID_TYPE_O);
        CurrentPlayer = 0;
    }
}
