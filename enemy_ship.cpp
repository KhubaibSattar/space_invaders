#include "enemy_ship.hpp"
#include <iostream>    
using namespace std;

    enemy_ship::enemy_ship(SDL_Renderer* rend, SDL_Texture* ast, SDL_Rect mov): Unit(rend, ast), mover(mov){
        src = {835, 441, 108, 126};
        //src = {616, 201, 302, 96};
    }

    void enemy_ship::draw(){
      /*
        if(count==0){
      src={31,377,107,119};
      count++;
    }else if(count==1){
      src={172,372,157,138};
      count++;
    }else if(count==2){
      src={338,360,168,169};
      count++;
    }else if(count==3){
      src={499,360,168,169};
      count++;
    }else if(count==4){
      src={669,360,168,169};
      count++;
    }else if(count==5){
      src={837,360,163,169};
      count++;
    }else if(count==6){
      src={1005,360,163,169};
      count=-1;
    }else if(count==-1){
      src = {161, 463, 35, 11};
      //src = {616, 201, 302, 96};
    
    }
    */
    if(mover.x >= 10){
            
            Unit::draw(src, mover);
            mover.x-=10;
        }
    

    }

    SDL_Rect enemy_ship::ret_mov_e(){
        return mover;
    }  