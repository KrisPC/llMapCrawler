#ifndef Room_hpp
#define Room_hpp

#include <string>
#include "LinkedListOfStudents.hpp"

class Item;
class Door; // allows us to reference door when door refereneces Room.

using namespace std;

class Room
{
    private:
        string title;
        Door* collectionOfDoors[10];
        int currentNumberOfDoors;
        LinkedListOfStudents* theStudents;
    
    public:
        Room(string title);
        void addDoor(Door* aDoor);
        void display();
        void addStudent(Student* aStudent);
        void removeStudent(Student* aStudent);
        void takeDoor(Student* aStudent, string direction);
        void addItem(Item * nameOfItem);
        Item * itemInroom;
        bool hasItem;
        void emptyItem();

};
#endif