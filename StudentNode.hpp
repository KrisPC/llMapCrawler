#ifndef StudentNode_hpp
#define StudentNode_hpp

#include "Student.hpp"

class StudentNode
{
    private:
        Student* payload;
        StudentNode* nextNode;

    public:
        StudentNode(Student* payload);
        void setNextNode(StudentNode* n);
        Student* getPayload();
        StudentNode* getNextNode();
};
#endif