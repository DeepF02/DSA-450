/* C++ Program to implement a stackthat supports findMiddle() and deleteMiddle in O(1) time */
#include <bits/stdc++.h>
using namespace std;

/* A Doubly Linked List Node */
struct DLLNode
{
    int data;
    DLLNode *prev, *next;
};
/* Representation of the stack data structure that supports findMiddle() in O(1) time. 
The Stack is implemented using Doubly Linked List.
It maintains pointer to head node, pointer to middle node and count of nodes */

struct myStack
{
    int count;
    DLLNode *head, *mid;
};

class middleStack
{
public:
    /* Function to create the stack data structure */
    myStack *createMyStack(){
        myStack *ms = new myStack();
        ms->count = 0;
        return ms;
    }

    /* Function to push an element to the stack */
    void push(myStack *ms, int new_data)
    {
        /* allocate DLLNode and put in data */
        DLLNode *newDLLNode = new DLLNode();
        newDLLNode->data = new_data;

        /* Since we are adding at the beginning, prev is always NULL */
        newDLLNode->prev = NULL;

        /* link the old list off the new DLLNode */
        newDLLNode->next = ms->head;

        /* Increment count of items in stack */
        ms->count ++;

        /* Change mid pointer in two cases
        1) Linked List is empty
        2) Number of nodes in linked list is odd */
        if (ms->count == 1) ms->mid = newDLLNode;
        else{
            ms->head->prev = newDLLNode;
            if (!(ms->count & 1))//same as ms->count%2==1
                ms->mid = ms->mid->prev; // Update mid if ms->count is even
        }
        /* move head to point to the new DLLNode */
        ms->head = newDLLNode;
    }

    /* Function to pop an element from stack */
    int pop(myStack *ms){
        /* Stack underflow */
        if (ms->count == 0){
            cout << "Stack is empty\n";
            return -1;
        }

        DLLNode *head = ms->head;
        int item = head->data;
        ms->head = head->next;

        // If linked list doesn't become empty, update prev of new head as NULL
        if (ms->head != NULL)
            ms->head->prev = NULL;
        ms->count -= 1;

        // update the mid pointer when we have odd number of elements in the stack, i,e move down the mid pointer.
        if ((ms->count) & 1)
            ms->mid = ms->mid->next;
        free(head);
        return item;
    }

    // Function for finding middle of the stack
    int findMiddle(myStack *ms){
        if (ms->count == 0){
            cout << "Stack is empty now\n";
            return -1;
        }
        return ms->mid->data;
    }
    // Function for deleting middle of the stack
    int deletemiddle(myStack *ms){
        int temp = ms->mid->data;
        ms->mid->prev->next = ms->mid->next;
        ms->mid->next->prev = ms->mid->prev;
        delete ms->mid;
        ms->mid = ms->mid->next; //So that mid does not contain garbage value
        return temp;
    }
};

int32_t main()
{
    /* Let us create a stack using push() operation*/
    middleStack midStack;
    myStack *ms = midStack.createMyStack();
    midStack.push(ms, 11);
    midStack.push(ms, 22);
    midStack.push(ms, 33);
    midStack.push(ms, 44);
    midStack.push(ms, 55);
    midStack.push(ms, 66);
    midStack.push(ms, 77);

    cout << "Item popped is " << midStack.pop(ms) << endl;
    cout << "Item popped is " << midStack.pop(ms) << endl;
    cout << "Item popped is " << midStack.pop(ms) << endl;
    cout << "Middle Element is " << midStack.findMiddle(ms) << endl;
    cout << "Deleted Middle Element is " << midStack.deletemiddle(ms) << endl;
    cout << "Middle Element is " << midStack.findMiddle(ms) << endl;
    return 0;
}