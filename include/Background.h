#pragma once 
#include <../include/Game.h>
#include <SDL2/SDL.h>

class Background
{
public:
    Background(Game &loadBackgroundTex);
    void backgroundRender(Game &renderBackground); 
private:
    SDL_Texture* backgroundTexture;
};
