#ifndef house_h
#define house_h

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
        Room* neighbors[4]={nullptr, nullptr, nullptr, nullptr}; //0=left, 1=right, 2=up, 3=down
        Object* items[4]={nullptr, nullptr, nullptr, nullptr};
};

#endif