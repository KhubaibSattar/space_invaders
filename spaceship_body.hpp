// Inherit from Unit class
#pragma once
#include "Unit.hpp"
#include <string>
using namespace std;

class spaceship_body: public Unit{
    SDL_Rect src, mover;
    public:
    spaceship_body(SDL_Renderer* rend, SDL_Texture* ast, SDL_Rect mov);
    SDL_Rect move_body(string dir);

    void draw();

    
};