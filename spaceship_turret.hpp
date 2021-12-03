// Inherit from Unit class
#pragma once
#include "Unit.hpp"
#include <string>
using namespace std;

class spaceship_turret: public Unit{
    SDL_Rect src, mover;
    private:
    int count_1=0;
    public:
    spaceship_turret(SDL_Renderer* rend, SDL_Texture* ast, SDL_Rect mov);

    void draw();
    SDL_Rect ret_mov();
    SDL_Rect move_turret(string dir);
    bool move();
    
};