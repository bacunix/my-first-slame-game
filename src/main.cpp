#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <../include/Game.h>
#include <../include/Window.h>

int main(int argc, char* args[])
{
    Game mainGame("unknown game", Window::windowWidth, Window::windowHeight);

    bool gameRunning = true;

    SDL_Event event;

    SDL_Texture* slimeTexture = mainGame.loadTexture("assets/images/a_slime.png");

    while(gameRunning)
    {
        while(SDL_PollEvent(&event))
        {   
            mainGame.gameHandleEvent(gameRunning, event);
            mainGame.gameRenderClear();
            mainGame.gameRenderEntity(slimeTexture);
            mainGame.gameRenderDisplay();
        }
    }
    SDL_DestroyTexture(slimeTexture); 
    mainGame.gameQuit();
    return 0;
}
