// Make composition of TankBody and TankTurret objects in Tank class
#pragma once
#include "Unit.hpp"
#include "spaceship_body.hpp"
#include "spaceship_turret.hpp"
#include <string>
using namespace std;

class spaceship: public Unit{
    
    public:
    spaceship_body *tb;
    spaceship_turret *tt;

    spaceship(SDL_Renderer* rend, SDL_Texture* ast, SDL_Rect mov);
    


    void draw();
    SDL_Rect getmov();
    SDL_Rect ship_move(string dir);
    bool mover_1();
    

    
};
