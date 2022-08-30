#include "game.h"
#include<iostream>
using namespace std;
int main(){
    //create rooms and items without neighbors
    string myIntro="Happy birthday little sibling! I know you like mysteries, so I've left a present in your house. You'll have to do a little investigating to get to it!";
    string myOutro="Here's your birthday present! I know you've been wanting the new Nitro Witch Game. Enjoy!";
    Game myGame("suitcase", myIntro,myOutro);
    Room* entrance= new Room("entrance");
    Object* closet= new Object(0,0, "closet","There are a few coats and shoes.");
    entrance->addItem(closet, 0);
    myGame.rooms.push_back(entrance);
    
    Room* hall= new Room("hall");
    Object* suitcase= new Object(2,1, "suitcase","Somehow, half of your wardrobe is in here.");
    hall->addItem(suitcase, 0);
    Object* picture= new Object(0,0, "picture","It is a photo of your family at the park.");
    hall->addItem(picture, 1);
    myGame.rooms.push_back(hall);
    
    Room* livingR= new Room("living room");
    Object* television= new Object(0,0, "television","An old cartoon is playing.");
    livingR->addItem(television, 0);
    Object* couch= new Object(0,0, "couch","There is a penny under the cushion. Lucky!");
    livingR->addItem(couch, 1);
    myGame.rooms.push_back(livingR);

    Room* yard=new Room("yard");
    Object* pool=new Object(0,3, "pool","There are some colorful rings at the bottom of the pool.");
    yard->addItem(pool, 0);
    myGame.rooms.push_back(yard);

    Room* kitchen= new Room("kitchen");
    Object* fridge= new Object(0,0, "fridge","There are plenty of vegetables and some suspicious cheese.");
    kitchen->addItem(fridge, 0);
    myGame.rooms.push_back(kitchen);

    Room* dining= new Room("dining room");
    Object* cabinet= new Object(3,2, "cabinet","There is a collection of hand-painted plates.");
    dining->addItem(cabinet, 0);
    myGame.rooms.push_back(dining);

    Room* bedR= new Room("bedroom");
    Object* musicBox= new Object(1,0, "music box","A ballerina twirls in time to chimes.");
    bedR->addItem(musicBox, 0);
    myGame.rooms.push_back(bedR);

    //add neighbors
    //index order: left right up down
    entrance->addNeighbor(bedR,0);
    entrance->addNeighbor(hall,1);

    hall->addNeighbor(entrance,0);
    hall->addNeighbor(livingR,2);

    livingR->addNeighbor(kitchen,0);
    livingR->addNeighbor(yard,2);
    livingR->addNeighbor(hall,3);

    yard->addNeighbor(livingR,3);

    kitchen->addNeighbor(dining,0);
    kitchen->addNeighbor(livingR,1);

    dining->addNeighbor(kitchen,1);
    dining->addNeighbor(bedR,3);

    bedR->addNeighbor(entrance,1);
    bedR->addNeighbor(dining,2);

    //run the game
    myGame.setStart(entrance);
    myGame.runGame();
    return 0;
}