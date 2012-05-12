#include "Entity.h"

std::vector<Entity*> Entity::EntityList;

Entity::Entity() {
    Surface = NULL;

    X = Y = 0.0f;

    Width = Height = 0;

    AnimState = 0;
}

Entity::~Entity() {}

bool Entity::Load(char* File, int Width, int Height, int MaxFrames) {
    if((Surface = Sprite::Load(File)) == NULL) {
        return false;
    }

    Sprite::Transparent(Surface, 255, 0, 255);

    this->Width = Width;
    this->Height = Height;

    Anim.MaxFrames = MaxFrames;

    return true;
}

void Entity::Loop() {
    Anim.Animate();
}

void Entity::Render(SDL_Surface* Screen) {
    if(Surface == NULL || Screen == NULL) return;

    Sprite::Draw(Screen, Surface, X, Y, AnimState * Width, Anim.GetCurrentFrame() * Height, Width, Height);
}

void Entity::Cleanup() {
    if(Surface) {
        SDL_FreeSurface(Surface);
    }

    Surface = NULL;
}
