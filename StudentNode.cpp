#include "StudentNode.hpp"

StudentNode::StudentNode(Student* payload)
{
    this->payload = payload;
    this->nextNode = 0;
}

void StudentNode::setNextNode(StudentNode* n)
{
    this->nextNode = n;
}

Student* StudentNode::getPayload()
{
    return this->payload;
}

StudentNode* StudentNode::getNextNode()
{
    return this->nextNode;
}