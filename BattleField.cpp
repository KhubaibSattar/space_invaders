#include "BattleField.hpp"
#include "spaceship.hpp"
#include "spaceship_turret.hpp"
#include<iostream>
using namespace std;

void BattleField::drawObjects(){
    // call draw functions of all the objects here
    for(Bullet * b1: bullets){
        b1 -> draw();}

    
        //if(ismove)
        //   ismove= ship -> mover_1();

        ship -> draw();
    

    for(meteor * m1: meteors){
        m1 -> draw();
    }

    
    for(enemy_ship * e1: enemy_ships){
        e1 -> draw();
    }

    for(health_ship * h1: health_ship){
        h1 -> draw();
    }

    check_collision();
}


void BattleField::createObject(){
    random_2 = rand() % 500 + 1;
    //random_3 = rand() % 500 + 1;
    random_choose = rand() % 2 + 1;
    //SDL_Rect mov = {950, random_2, 50, 40};

    random_3 = rand() % 20 + 1;

    if(random_choose==1){
        meteor *m1=new meteor(gRenderer, assets, {950, random_2, 50, 40});
        meteors.push_back(m1);
    }else if(random_choose==2){
        enemy_ship *e1=new enemy_ship(gRenderer, assets, {950, random_2, 50, 40});
        enemy_ships.push_back(e1);
    }else if(random_3 == 1){
        health_ship * h1 = new health_ship(gRenderer, assets, {950, random_3, 30, 10});
        health_ship.push_back(h1);
    }

}

void BattleField::move_ship(string x){
    ship -> ship_move(x);
}


BattleField::BattleField(SDL_Renderer *renderer, SDL_Texture *asst):gRenderer(renderer), assets(asst){
    ismove=false;
    SDL_Rect mov = {0, 5, 30, 10};
    ship = new spaceship(renderer, asst, mov);
}


void BattleField::fire(int x,int y){
    cout<<"F key is pressed"<<endl;
    // provide code to fire all of the tanks.
    //SDL_Rect mov = {x, y, 30, 10}; // let's make a rectangel on x, y of the size 30, 10
    SDL_Rect temp;
    //SDL_Rect temp_2;
    //SDL_Rect temp_m;
    //for(Ship * t:ships){
    temp=ship -> getmov();
    Bullet *b1= new Bullet(gRenderer, assets, {temp.x+60,temp.y+15,temp.w-50,temp.h-33});
    bullets.push_back(b1);
    //    ismove=true;
        
    //}

    //temp_2=b1 -> ret_mov_2();
    //temp_m=m -> ret_mov_m();
    //if (temp_2.x==temp_m.x){
    //    meteors.pop_back();

    //}

    
   // std::cout<<"Mouse clicked at: "<<x<<" -- "<<y<<std::endl;


}

void BattleField::check_collision(){

    SDL_Rect r1;
    SDL_Rect r2;
    SDL_Rect r3;
    for(Bullet * b1: bullets){
        r1=b1 -> ret_mov_2();
        r3=ship -> getmov();

        for(meteor * m1: meteors){
            r2=m1 -> ret_mov_m();
            

            if(SDL_HasIntersection(&r1,&r2)){
                //delete m1;
                //vector<meteors>::iterator new_end;

                meteors.remove(m1);
                cout<<"collide"<<endl;
                
            }else if(SDL_HasIntersection(&r1,&r3)){
                //delete ship;
                cout<<"collide"<<endl;
                
            }
        }
    
        for(enemy_ship * e1: enemy_ships){
            r2=e1 -> ret_mov_e();
            

            if(SDL_HasIntersection(&r1,&r2)){
                //delete e1;
                //remove(enemy_ships.begin(), enemy_ships.end(),e1);
                enemy_ships.remove(e1);
                cout<<"collide"<<endl;
            }else if(SDL_HasIntersection(&r2,&r3)){

                //ship;
                cout<<"collide"<<endl;
                
            }
        }

        for (health_ship * h1: health_ship){
            r2 = h1 -> ret_mov_h();

        if(SDL_HasIntersections(&r1,&r2)){
            health_ship.remove(h1);
            cout<<"Health is aqquired"<<endl;
        } else if (SDL_HasIntersections(&r2,&r3)){
            cout<<"Health is lost"<<endl;
        }

        }
    }
   
}

/*
Original for ref
void BattleField::createObject(int x, int y){
    SDL_Rect mov = {x, y, 30, 10}; // let's make a rectangel on x, y of the size 30, 10


    Tank *t=new Tank(gRenderer, assets, mov);
    tanks.push_back(t);
    std::cout<<"Mouse clicked at: "<<x<<" -- "<<y<<std::endl;

}

BattleField::BattleField(SDL_Renderer *renderer, SDL_Texture *asst):gRenderer(renderer), assets(asst){
    ismove=false;
}
*/

/*
void BattleField::createObject(int x, int y){
    
    if (ship_flag==false){
    random = rand() % 500 + 1;
    //cout<<random<<endl;
    x=5;
    y=random;

    SDL_Rect mov = {x, y, 30, 10}; // let's make a rectangel on x, y of the size 30, 10


    Ship *s=new Ship(gRenderer, assets, mov);
    ships.push_back(s);
    std::cout<<"Mouse clicked at: "<<x<<" -- "<<y<<std::endl;

    ship_flag=true;
    } else{

        ships.pop_back();
       y+=30;
    SDL_Rect mov = {x, y, 30, 10}; // let's make a rectangel on x, y of the size 30, 10


    Tank *t=new Tank(gRenderer, assets, mov);
    tanks.push_back(t);
    }

}
*/
