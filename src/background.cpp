#include <../include/Background.h>


Background::Background(Game &loadBackgroundTex)
{
    backgroundTexture = loadBackgroundTex.loadTexture("assets/images/slame-game-background.png");
}

void Background::backgroundRender(Game &renderBackground)
{
    renderBackground.gameRenderEntity( backgroundTexture, 0, 0, NULL, 0.0, NULL, SDL_FLIP_NONE );
}
