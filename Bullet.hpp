#pragma once
#include "Unit.hpp"

class Bullet: public Unit{
    SDL_Rect src, mover;
    private:
    int count=0;
    public:
    Bullet(SDL_Renderer* rend, SDL_Texture* ast, SDL_Rect mov);
    SDL_Rect ret_mov_2();

    void draw();
    //void fire();
};