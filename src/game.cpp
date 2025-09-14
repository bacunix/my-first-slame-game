#include <../include/Game.h>
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL.h>
#include <string>
// #include <../include/Window.h>

Game::Game(std::string name, int w_width, int w_height)
{
    if(SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cout << "SDL_Init has failed to initialize. SDL_Error: " << SDL_GetError() << std::endl;
    }

    else if(!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG))
    {
        std::cout << "IMG_Init has failed. IMG_Error: " << SDL_GetError() << std::endl;
    }

    window = NULL;
    renderer = NULL;

    window =  SDL_CreateWindow(name.c_str(),
                               SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, w_width,
                              w_height, SDL_WINDOW_SHOWN);
    if(window == NULL)
    {
        std::cout << "Create window has failed. SDL_Error: " << SDL_GetError() << std::endl;
    }

    renderer = SDL_CreateRenderer(window,
                        -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
    if(renderer == NULL)
    {
        std::cout << "Create renderer has failed. SDL_GetError: " << SDL_GetError() << std::endl; 
    }
}

void Game::gameHandleEvent(bool &gameRunning, SDL_Event& event)
{
    if(event.type == SDL_QUIT)
    {
        gameRunning = false; 
    }
}

SDL_Texture* Game::loadTexture(std::string path)
{
    return IMG_LoadTexture(this->renderer, path.c_str());
}

void Game::gameRenderClear()
{
    SDL_SetRenderDrawColor(this->renderer, 255, 255, 255, 255);
    SDL_RenderClear(this->renderer);
}

void Game::gameRenderDisplay()
{
    SDL_RenderPresent(this->renderer);
}

void Game::gameRenderEntity(SDL_Texture* tex, int x, int y, SDL_Rect* srcRect)
{
    int textureWidth = 0;
    int textureHeight = 0;

    SDL_QueryTexture(tex,
                        NULL, NULL, 
                        &textureWidth, &textureHeight);

    SDL_Rect dstRect = {x, y, textureWidth, textureHeight};

    if(srcRect != NULL)
    {
        dstRect.w = srcRect->w;
        dstRect.h = srcRect->h;
    }

    SDL_RenderCopy(renderer, tex, srcRect, &dstRect);
}

void Game::gameQuit()
{
    SDL_DestroyWindow(this->window);
    SDL_DestroyRenderer(this->renderer);

    IMG_Quit();
    SDL_Quit();
}
