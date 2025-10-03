#include <SDL2/SDL.h>
#include <../include/Game.h>

class Zombie
{
public:
    Zombie(Game &zombieMain); 
    void renderZombie(Game &zombieMainRender);
private:
    SDL_Texture* mZombieTexture;    
};
