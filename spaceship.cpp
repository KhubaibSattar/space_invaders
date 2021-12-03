#include "Bullet.hpp"
#include "spaceship.hpp"   
#include "spaceship_body.hpp"
#include "spaceship_turret.hpp"
#include <string>
using namespace std; 

    spaceship::spaceship(SDL_Renderer* rend, SDL_Texture* ast, SDL_Rect mov): Unit(rend, ast){
        SDL_Rect temp = {mov.x +25, mov.y+10, mov.w +50, mov.h + 30};
        SDL_Rect temp_2 = {mov.x, mov.y, mov.w +50, mov.h + 50};
        tb = new spaceship_body(rend,ast,temp_2);
        tt = new spaceship_turret(rend,ast,temp);

    }

    
    void spaceship::draw(){
        
         tb -> draw();
         tt -> draw();
    }

    SDL_Rect spaceship::getmov(){
        return tt ->  ret_mov();
    }

    bool spaceship::mover_1(){
        tt -> move();
    }

    SDL_Rect spaceship::ship_move(string dir){
        tt -> move_turret(dir);
        tb -> move_body(dir);
    }

  