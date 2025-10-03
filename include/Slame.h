#pragma once
#include <SDL2/SDL.h>
#include <../include/Game.h>

class Slame
{
public:
    Slame();
    static const int SLAME_WIDTH = 64;
    static const int SLAME_HEIGHT = 64;
    static const int SLAME_VEL = 10;
    void loadTexForSlame(Game& loadTex);
    void renderSlameTex(Game& renderTex);
    void handleEvent(SDL_Event &event);
    void move();
private:
    SDL_Texture* slameTexture;
    SDL_Texture* bulletTexture;
    int mVelY;
    int mPosY;
    SDL_RendererFlip flip;
    bool renderBulletTexture;
    int counts;
    int bulletY;
    bool getNewY;
    bool countplus;
};
