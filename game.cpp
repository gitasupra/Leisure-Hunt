#include "game.h"

#include<iostream>
#include<stdexcept>
using namespace std;

void Game::printOptions(Room* rm){
    cout<<"You are in the "<<rm->getTitle()<<". Please choose an item or a direction."<<endl;
    for(int i=0; i<4; i++){
        if(rm->getItem(i) != nullptr){
            cout<<i<<": "<<rm->getItem(i)->getTitle()<<endl;;
        }
    }
    for(int i=0; i<4; i++){
        if(rm->getNeighbor(i)!= nullptr){
            switch(i){
                case 0:
                    cout<<"left: "<< rm->getNeighbor(i)->getTitle()<<endl;
                    break;
                case 1:
                    cout<<"right: "<< rm->getNeighbor(i)->getTitle()<<endl;
                    break;
                case 2:
                    cout<<"up: "<< rm->getNeighbor(i)->getTitle()<<endl;
                    break;
                case 3:
                    cout<<"down: "<< rm->getNeighbor(i)->getTitle()<<endl;
                    break;
            }
        }
    }
    cout<<endl;
}

void Game::runGame(){
    bool found=false;
    string myInput="";
    int inputNum;
    Room* curRoom=startRoom;
    cout<<intro<<endl;
    while(!found){
        cout<<endl;
        printOptions(curRoom);
        cin>>myInput;
        if(myInput != "left" && myInput != "right" && myInput != "up" && myInput != "down"){
            try{
                inputNum=stoi(myInput);
                //do something with number input
            }
            catch(std::invalid_argument &e){
                cout<<"Invalid input, please try again."<<endl;
            }
        }
        if(myInput=="left" && curRoom->getNeighbor(0) !=nullptr){
            curRoom=curRoom->getNeighbor(0); 
        }
        else if(myInput=="right" && curRoom->getNeighbor(1) !=nullptr){
            curRoom=curRoom->getNeighbor(1); 
        }
        else if(myInput=="up" && curRoom->getNeighbor(2) !=nullptr){
            curRoom=curRoom->getNeighbor(2);
        }
        else if(myInput=="down" && curRoom->getNeighbor(3) !=nullptr){
            curRoom=curRoom->getNeighbor(3); 
        }
    }
}
