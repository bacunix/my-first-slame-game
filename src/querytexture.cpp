#include "../include/QueryTexture.h"

void QueryTexture::querytexture(SDL_Texture* query_tex)
{
    SDL_QueryTexture( query_tex,
                        NULL, NULL,
                      &tex_width, &tex_height);
}

int QueryTexture::getTexWidth()
{
    return tex_width;
}

int QueryTexture::getTexHeight()
{
    return tex_height;
}

