#ifndef _ANIMATION_H_
#define _ANIMATION_H_

#include <SDL.h>

class Animation {
    private:
        int    CurrentFrame;
        int     FrameInc;

        int     FrameRate;
        long    OldTime;

    public:
        int    MaxFrames;
        bool    Oscillate;

    public:
        Animation();
        void Animate();

    public:
        void SetFrameRate(int Rate);
        void SetCurrentFrame(int Frame);
        int GetCurrentFrame();
};

#endif
