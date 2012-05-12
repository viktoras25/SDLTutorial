#include <vector>

#include "Animation.h"
#include "Sprite.h"

class Entity {
    public:
        static std::vector<Entity*>    EntityList;

    protected:
        Animation      Anim;
        SDL_Surface*    Surface;

    public:
        float           X;
        float           Y;

        int             Width;
        int             Height;

        int             AnimState;

    public:
        Entity();
        virtual ~Entity();

        virtual bool Load(char* File, int Width, int Height, int MaxFrames);
        virtual void Loop();
        virtual void Render(SDL_Surface* Screen);
        virtual void Cleanup();
};
