#include "spaceship_turret.hpp""    
#include <string>
using namespace std;

    spaceship_turret::spaceship_turret(SDL_Renderer* rend, SDL_Texture* ast, SDL_Rect mov): Unit(rend, ast), mover(mov){
        //src = {601, 0, 500, 155};
        src = {987, 662, 147, 93};

    }

    void spaceship_turret::draw(){
        Unit::draw(src, mover);
        
    }

    bool spaceship_turret::move(){
            if(count_1==0){
                mover.x +=3;
                count_1++;
                return true;
            }else if(count_1==1){
                mover.x -=3;
                count_1= 0;
                return false;
                }
    }

    
    SDL_Rect spaceship_turret::ret_mov(){
        return mover;
    }

    SDL_Rect spaceship_turret::move_turret(string dir){
        if (dir=="up"){
            if(mover.y>20){
                mover.y-=15;
            }
        }else if(dir=="down"){
            
            if(mover.y<510){
                mover.y+=15;
            }
            
            
        }

    }