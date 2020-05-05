#include <iostream>
#include "Student.hpp"
#include "Room.hpp"
#include "Door.hpp"
#include "Student.hpp"
#include "Item.hpp"

using namespace std;

int main()
{
    Student* theStudent = new Student("Mr. Gonzales");
    Room* lobby = new Room("Lobby");
    Room* serverRoom = new Room("Server Room");
    Room* esports = new Room("Esports");
    Room* locklairOffice = new Room("Lockair's Office");

    Door* d1 = new Door("north", serverRoom, "south", lobby);
    Door* d2 = new Door("west", locklairOffice, "east", lobby);
    Door* d3 = new Door("south", esports, "north", lobby);

    string command = "";
    lobby->addStudent(theStudent);

    Item* chainsaw = new Item("a running chainsaw");
    theStudent->addItem(chainsaw);
    Item* BFG = new Item("Big freaking gun");
    esports->addItem(BFG);

    while(command != "quit")
    {
        theStudent->getCurrentRoom()->display();
        cout << "Where would you like to go?: ";
        cin >> command; 

        if(command == "backpack")
        {
            theStudent->displayBackpackContents();
        }
        else
        {
            theStudent->getCurrentRoom()->takeDoor(theStudent, command);
        }

        if(command == "grab")
        {
            if(theStudent->getCurrentRoom()->hasItem)
            {
                if(theStudent->currentItemCount == theStudent->maxItemCount)
                {
                    cout << "Your backpack is full!"<<"\n";
                }
                else
                {
                    //student picks up item and adds to backpack
                    theStudent->addItem(theStudent->getCurrentRoom()->itemInroom);
                    theStudent->displayBackpackContents();
                    theStudent->getCurrentRoom()->emptyItem();
                }
            }
            else
            {
                cout << "No item here!"<<"\n";
            }
        } 
        if(command == "drop")
        {
            if(theStudent->currentItemCount == 0)
            {
                cout << "No item to drop!" << "\n";
            }

            else if(theStudent->getCurrentRoom()->hasItem)
            {
                cout << "Room is already full with an item, pick up item first." << "\n";
            }
            else
            {
                cout << "Dropping oldest item in room!" << "\n";
                theStudent->getCurrentRoom()->addItem(theStudent->getOldestItem());
            }
            
        }
    }
    cout << "Goodbye!!!\n";
    return 0;
}