#include <../include/Slame.h>
#include <SDL2/SDL.h>
#include "../include/Window.h"
#include "../include/Game.h"

Slame::Slame()
{
    slameTexture = NULL; 
    bulletTexture = NULL;
    mPosY = Window::windowHeight - SLAME_HEIGHT;
    mVelY = 0;
    flip = SDL_FLIP_HORIZONTAL;
    renderBulletTexture = false;
    getNewY = true;
    bulletY = 0;
    counts = 15;
    countplus = true;
}

void Slame::handleEvent(SDL_Event &event)
{
    if(event.type == SDL_KEYDOWN && event.key.repeat == 0)
    {
        switch(event.key.keysym.sym)
        {
            case SDLK_UP:
            case SDLK_w:
                mVelY -= SLAME_VEL;
            break;

            case SDLK_DOWN:
            case SDLK_s:
                mVelY += SLAME_VEL;
            break;

            case SDLK_SPACE:
                renderBulletTexture = true;
            break;
        }
    }

    else if(event.type == SDL_KEYUP)
    {
        switch(event.key.keysym.sym)
        {
            case SDLK_UP:
            case SDLK_w:
                mVelY += SLAME_VEL;
            break;
            
            case SDLK_DOWN:
            case SDLK_s:
                mVelY -= SLAME_VEL;
            break;
        }
    }
}

void Slame::move()
{
    mPosY += mVelY;

    if(mPosY < 0 || mPosY + SLAME_HEIGHT > Window::windowHeight)
    {
        mPosY -= mVelY;
    }
}

void Slame::loadTexForSlame(Game& loadTex)
{
    slameTexture = loadTex.loadTexture("assets/images/a_slime.png");
    bulletTexture = loadTex.loadTexture("assets/images/bullet.png");
}

void Slame::renderSlameTex(Game& renderTex)
{
    renderTex.gameRenderEntity( slameTexture, 5, mPosY, NULL, 0.0, NULL, flip );
    if(renderBulletTexture)
    {
        if(getNewY)
        {
            bulletY = mPosY + 10;        
            getNewY = false;
        }
        renderTex.gameRenderEntity( bulletTexture, counts, bulletY, NULL, 0.0, NULL, SDL_FLIP_NONE);
        if(counts > Window::windowWidth)
        {
            renderBulletTexture = false; 
            counts = 15;
        }
        else 
        {
            counts+=24;
        }
    }

    else 
    {
        getNewY = true;
    }
}
