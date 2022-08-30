#include "game.h"
#include<iostream>
using namespace std;
int main(){
    //create rooms and items without neighbors
    string myIntro="\nYou see a note on your front door.\n\"Happy birthday little sibling! I know you like mysteries, so I've left a present in your house. You'll have to do a little investigating to get to it!\"";
    string myOutro="\"Here's your birthday present! I know you've been wanting the new Nitro Witch Game. Enjoy!\"\n";
    Game myGame("music box", myIntro,myOutro);
    Room* entrance= new Room("ENTRANCE");
    Object* item= new Object(0,0, "closet","There are a few coats and shoes.");
    entrance->addItem(item, 0);
    item=new Object(0,0,"painting","It is a landscape painting of a flower field.");
    entrance->addItem(item,1);
    item=new Object(0,0,"rug","The rug has spiral patterns that make you dizzy if you look too long.");
    entrance->addItem(item,2);
    myGame.rooms.push_back(entrance);
    
    Room* hall= new Room("HALL");
    item= new Object(2,1, "suitcase","Somehow, half of your wardrobe is in here.");
    hall->addItem(item, 0);
    item= new Object(0,0, "large picture","It is a photo of your family at the park.");
    hall->addItem(item, 1);
    item=new Object(0,0, "small picture", "It is a polaroid selfie of you and a stray cat.");
    hall->addItem(item,2);
    myGame.rooms.push_back(hall);
    
    Room* livingR= new Room("LIVING ROOM");
    item= new Object(0,0, "television","An old cartoon is playing.");
    livingR->addItem(item, 0);
    item= new Object(0,0, "couch","There is a penny under the cushion. Lucky!");
    livingR->addItem(item, 1);
    item=new Object(0,0, "chess board","A glass chess set that impresses more than your chess skills.");
    livingR->addItem(item, 2);
    myGame.rooms.push_back(livingR);

    Room* yard=new Room("YARD");
    item=new Object(0,3, "pool","There are some colorful rings at the bottom of the pool.");
    yard->addItem(item, 0);
    item=new Object(0,0, "shed","The shed has some garden tools and many, many cobwebs.");
    yard->addItem(item, 1);
    item=new Object(0,0, "planter box", "There are some sprouts and a few vegetable signs.");
    yard->addItem(item, 2);
    myGame.rooms.push_back(yard);

    Room* kitchen= new Room("KITCHEN");
    item= new Object(0,0, "fridge","There are plenty of vegetables, bread, and some suspicious cheeses.");
    kitchen->addItem(item, 0);
    item=new Object(0,0, "trapdoor","AHA! Nothing to see here.");
    kitchen->addItem(item,1);
    myGame.rooms.push_back(kitchen);

    Room* dining= new Room("DINING ROOM");
    item= new Object(3,2, "cabinet","There is a collection of hand-painted plates.");
    dining->addItem(item, 0);
    item=new Object(0,0,"dining table","There is an arrangement of flowers in the center.");
    dining->addItem(item,1);
    myGame.rooms.push_back(dining);

    Room* bedR= new Room("BEDROOM");
    item= new Object(1,0, "music box","A ballerina twirls in time to chimes. You also see your present! There is also a card.");
    bedR->addItem(item, 0);
    item=new Object(0,0,"poster","A poster for your favorite video game series, Nitro Witch! The witches blast magic at a Nitro Dragon.");
    bedR->addItem(item, 1);

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