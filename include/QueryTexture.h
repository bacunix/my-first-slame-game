#include <SDL2/SDL.h>

class QueryTexture
{
public:
    void querytexture(SDL_Texture* query_tex); 
    int getTexWidth();
    int getTexHeight();
private:
    int tex_width;
    int tex_height;
}
