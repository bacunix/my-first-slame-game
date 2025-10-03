#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
// #include <../include/Window.h>

class Game
{
public:
    Game(std::string name, int w_width, int w_height);
    void gameRenderClear();
    void gameRenderDisplay();
    void gameRenderEntity(SDL_Texture* tex, int x, int y, SDL_Rect* srcRect = NULL, double angel = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);
    void gameRenderRect(SDL_Rect dstRect);
    SDL_Texture* loadTexture(std::string path);
    void gameQuit();
private:
    SDL_Window* window;
    SDL_Renderer* renderer;
};


