#include <../include/Zombie.h>
#include <SDL2/SDL.h>
#include <../include/Game.h>

Zombie::Zombie(Game& zombieMain)
{
    mZombieTexture = zombieMain.loadTexture("assets/images/zomchim.png");
}


void Zombie::renderZombie(Game &zombieMainRender)
{
    zombieMainRender.gameRenderEntity(mZombieTexture, 70, 90);
}
