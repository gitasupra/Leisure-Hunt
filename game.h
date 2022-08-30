#ifndef game_h
#define game_h

#include <string>
#include<vector>
class Player{
    public:
        bool hasKey(int k){
            return keys[k];
        }
        void gainKey(int k){
            keys[k]=true;
        }
    private:
        bool keys[3]={false};
};

class Object{
    public:
        Object(int lock, int key, std::string inTitle, std::string inDesc){
            hasLock=lock;
            hasKey=key;
            title=inTitle;
            desc=inDesc;
        }
        int getLock(){
            return hasLock;
        }
        int getKey(){
            return hasKey;
        }
        std::string getTitle(){
            return title;
        }
        std::string getDesc(){
            return desc;
        }
        void unlock(){
            hasLock=0;
        }
        void takeKey(){
            hasKey=0;
        }
    private:
        int hasLock=0;
        int hasKey=0;
        std::string title;
        std::string desc;


};

class Room{
    public:
        Room(std::string inTitle){
            title=inTitle;
        };
        ~Room(){
            for(auto it:items){
                if(it!= nullptr){
                    delete it;
                }
            }
        }
        void addNeighbor(Room* neighbor, int direction){
            neighbors[direction]=neighbor;
        }
        void addItem(Object* item, int idx){
            items[idx]=item;
        }
        Room* getNeighbor(int idx){
            return neighbors[idx];
        }
        Object* getItem(int idx){
            return items[idx];
        }
        std::string getTitle(){
            return title;
        }
    private:
        std::string title;
        Room* neighbors[4]={nullptr}; //left, up, right, down
        Object* items[4]={nullptr};
};

class Game{
    public:
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
        std::vector<Room*> rooms={nullptr};
    private:
        std::string treasure;
};

#endif
