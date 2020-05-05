#include "Room.hpp"
#include <iostream>
#include "Door.hpp"
#include "Item.hpp"

using namespace std;

Room::Room(string title)
{
    this->title = title;
    this->currentNumberOfDoors = 0;
    this->hasItem = false;
}

void Room::addDoor(Door* aDoor)
{
    this->collectionOfDoors[this->currentNumberOfDoors] = aDoor;
    this->currentNumberOfDoors++;
    this->theStudents = new LinkedListOfStudents();
}

void Room::addStudent(Student* aStudent)
{
    if(this->theStudents->indexOf(aStudent) == -1)
    {
        this->theStudents->addFront(aStudent);
        aStudent->setCurrentRoom(this);
    } 
}

void Room::removeStudent(Student* aStudent)
{
    int indexOfStudent = this->theStudents->indexOf(aStudent);
    if(indexOfStudent != -1)
    {
        this->theStudents->removeAtIndex(indexOfStudent);
        aStudent->setCurrentRoom(0); //the student is in limbo
    }
}

void Room::takeDoor(Student* aStudent, string direction)
{
    Door* tempDoor;
    Room* currentRoom = this;
    for(int i = 0; i < this->currentNumberOfDoors; i++)
    {
        tempDoor = this->collectionOfDoors[i];
        if(tempDoor->getDirectionToOtherRoom(currentRoom) == direction)
        {
            Room* theOtherRoom = tempDoor->getTheOtherRoom(currentRoom);
            
            //remove the student from the current room
            this->removeStudent(aStudent);

            //put the student in the new room
            theOtherRoom->addStudent(aStudent);
        }
    }
}

void Room::display()
{
    cout << this->title << "\n";

    //show the potential doors
    cout << "Obvious Exits: ";
    Door* tempDoor = 0;
    
    for(int i = 0; i < this->currentNumberOfDoors; i++)
    {
        tempDoor = this->collectionOfDoors[i];
        cout << tempDoor->getDirectionToOtherRoom(this) << " ";
    }
    cout << "\n Also Here: ";
    Student* tempStudent;

    for(int i = 0; i < this->theStudents->getCount(); i++)
    {
        tempStudent = this->theStudents->getAtIndex(i);
        cout << tempStudent->getName() << " ";
    }

    if(this->hasItem)
    {
        cout << "\n" << "Item here: " << this->itemInroom->getName() << "\n";
    }
    cout << "\n";
}

void Room::addItem(Item * nameOfItem)
{
    this->itemInroom = nameOfItem;
    hasItem = true;
}

void Room::emptyItem()
{
    this->itemInroom = NULL;
    hasItem = false;
}