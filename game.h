#ifndef game_h
#define game_h

#include <string>
#include<vector>
#include "house.h"

class Game{
    public:
        Game(std::string inTreasure, std::string myIntro, std::string myOutro){
            treasure=inTreasure;
            intro=myIntro;
            outro=myOutro;
            
        }
        Game(std::string inTreasure){
            treasure=inTreasure;
            
        }
        ~Game(){
            for(auto rm: rooms){
                if(rm !=nullptr){
                    delete rm;
                }
            }
        }
        void setStart(Room* rm){
            startRoom=rm;
        }
        std::string colors[3]={"RED","YELLOW","BLUE"};
        std::string directions[4]={"left","right","up","down"};
        void printOptions(Room* curRoom);
        bool interactWithObject(Object* item);
        void runGame();
        std::vector<Room*> rooms={nullptr};
        Player gamePlayer;
    private:
        std::string treasure;
        std::string intro="Game Start!";
        std::string outro="Game End.";
        Room* startRoom=nullptr;
};

#endif
