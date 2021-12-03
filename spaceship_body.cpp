#include "spaceship_body.hpp""  
#include <string>  
using namespace std;

    spaceship_body::spaceship_body(SDL_Renderer* rend, SDL_Texture* ast, SDL_Rect mov): Unit(rend, ast), mover(mov){
        //src = {0, 0, 428, 295};
        src = {174, 686, 315, 115};
    }

    void spaceship_body::draw(){
        Unit::draw(src, mover);
        
    }

    SDL_Rect spaceship_body::move_body(string dir){
        if (dir=="up"){
            if(mover.y>10){
                mover.y-=15;
            }
        }else if(dir=="down"){
            if(mover.y<500){
                mover.y+=15;
            }
            
            
        }

    }