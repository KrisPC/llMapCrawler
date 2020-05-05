#ifndef Item_hpp
#define Item_hpp

#include <string>
using namespace std;
class Item
{
    private:
        string name;
    
    public:
        Item(string name);
        string getName();
};
#endif