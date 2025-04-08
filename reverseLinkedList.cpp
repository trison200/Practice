#include <iostream>

using namespace std;

class LLNode
{
public:
    int val;
    LLNode *next;
    LLNode();                      // Constructor: val = 0, next = nullptr
    LLNode(int val, LLNode *next); // Constructor with customized data
};

LLNode *reverseLinkedList(LLNode *head)
{
    LLNode *prev = nullptr;
    LLNode *current = head;
    LLNode *next = nullptr;

    while (current != nullptr)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}