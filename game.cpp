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
            cout<<directions[i]<<": "<<rm->getNeighbor(i)->getTitle()<<endl;
        }
    }
    cout<<endl;
}

bool Game::interactWithObject(Object* item){
    if(item->getLock()){
        cout<<endl<<"The "<<item->getTitle()<<" has a "<<colors[item->getLock()-1]<<" lock."<<endl;

        if(!gamePlayer.hasKey(item->getLock())){
            cout<<"You do not have the matching key."<<endl;
            return false;
        }
        else{
            cout<<"You use the matching key to unlock the "<<item->getTitle()<<". "<<endl;
            item->unlock();
        }
    }

    cout<<endl<<item->getDesc()<<endl;

    if(item->getKey()){
        cout<<endl<<"The "<<item->getTitle()<<" has a "<<colors[item->getKey()-1]<<" key. You take it."<<endl;
        gamePlayer.gainKey(item->getKey());
        item->removeKey();
    }
    if(treasure == item->getTitle()){
        return true;
    }
    return false;
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
            }
            catch(std::invalid_argument &e){
                cout<<"\nInvalid input, please try again."<<endl;
                continue;
            }
            if(inputNum>3 || inputNum<0 || curRoom->getItem(inputNum) ==nullptr){
                cout<<"\nInvalid input, please try again."<<endl;
                continue;
            }
            if(interactWithObject(curRoom->getItem(inputNum))){
                found=true;
                continue;
            }
        }
        else if(myInput=="left" && curRoom->getNeighbor(0) !=nullptr){
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
        else{
            cout<<"\nInvalid input, please try again."<<endl;
        }
    }
    cout<<outro<<endl;
}
