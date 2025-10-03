#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "../include/Game.h"
#include "../include/Window.h"
#include "../include/Slame.h"
#include "../include/Background.h"
#include <../include/Zombie.h>

int main(int argc, char* args[])
{
    Slame mainCharacter;

    Game mainGame("Slame VS zombie", Window::windowWidth, Window::windowHeight);

    Zombie zombie_chars(mainGame);

    Background gBack(mainGame);

    bool gameRunning = true;

    SDL_Event event;

    SDL_Rect warningRect = {
        60,
        0,
        10,
        Window::windowHeight
    };

    while(gameRunning)
    {
        while(SDL_PollEvent(&event))
        {   
            if(event.type == SDL_QUIT)
            {
                gameRunning = false;
            }
            mainCharacter.handleEvent(event);
        }
        mainGame.gameRenderClear();
        mainCharacter.move();
        gBack.backgroundRender(mainGame);
        mainCharacter.loadTexForSlame(mainGame);
        mainCharacter.renderSlameTex(mainGame);
        mainGame.gameRenderRect(warningRect);
        zombie_chars.renderZombie(mainGame);
        mainGame.gameRenderDisplay();
    }
    mainGame.gameQuit();
    return 0;
}
