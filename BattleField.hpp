#pragma once
#include<SDL.h>
#include "Bullet.hpp"
#include "meteor.hpp"
#include "enemy_ship.hpp"
#include<list>
#include<vector>
#include "spaceship.hpp"

using namespace std;
class BattleField{
    list<Bullet*> bullets;
    //list<Ship*> ships;
    list<meteor*> meteors;
    list<enemy_ship*> enemy_ships;
    list<health_ship*> health_ship;
    spaceship* ship;
    SDL_Renderer *gRenderer;
    SDL_Texture *assets;
    bool ismove;
    bool ship_flag =false;
    int random;
    int random_2;
    int random_3;
    int random_choose;

    public:
    BattleField(SDL_Renderer *, SDL_Texture *);
    void drawObjects(); 
    //void createObject(int, int);
    void createObject();
    void fire(int, int);
    void check_collision();
    void move_ship(string x);

    

};