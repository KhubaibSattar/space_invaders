#pragma once
#include "Unit.hpp"

class enemy_ship: public Unit{
    SDL_Rect src, mover;
    private:
    int count=0;
    public:
    enemy_ship(SDL_Renderer* rend, SDL_Texture* ast, SDL_Rect mov);
    SDL_Rect ret_mov_e();

    void draw();
    //void fire();
};