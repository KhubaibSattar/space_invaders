#pragma once
#include "Unit.hpp"

class meteor: public Unit{
    SDL_Rect src, mover;
    private:
    int count=0;
    public:
    meteor(SDL_Renderer* rend, SDL_Texture* ast, SDL_Rect mov);
    SDL_Rect ret_mov_m();

    void draw();
    //void fire();
};