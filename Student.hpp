#ifndef Student_hpp
#define Student_hpp

#include <string>
#include "Item.hpp"
using namespace std;

class Room;
class Student
{
    private:
        string name;
        Room* currentRoom;
        Item** backpack;

    public:
        Student(string name);
        void displayBackpackContents();
        bool addItem(Item* anItem);
        string getName();
        Room* getCurrentRoom();
        void setCurrentRoom(Room* aRoom);
        int maxItemCount;
        int currentItemCount;
        Item * getOldestItem(); //possible future is to add support for picking the item to drop 
};

#endif