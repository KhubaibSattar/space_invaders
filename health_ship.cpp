#include "health_ship.cpp"
#include <iostream>    
using namespace std;

    meteor::meteor(SDL_Renderer* rend, SDL_Texture* ast, SDL_Rect mov): Unit(rend, ast), mover(mov){
        src = {23, 1, 52, 168};
        // x = 23, y = 1, width = 52, height = 168
        //src = {616, 201, 302, 96};
    }

    void health_ship::draw(){
      
    if(mover.x >= 10){
            
            Unit::draw(src, mover);
            mover.x-=10;
        }
    
    

    }

    SDL_Rect meteor::ret_mov_h(){
        return mover;
    }