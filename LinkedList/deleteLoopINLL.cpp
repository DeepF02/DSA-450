// Write a program to Detect loop in a linked list.
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

// Node* head=NULL; // Global declaration of head

class LinkedList
{
public:
    //Function to insert data in a linked list ITERATIVE.
    Node *insert(Node *head, int dataX)
    {
        Node *temp = new Node();
        temp->data = dataX;
        temp->next = NULL;
        if (head == NULL)
            return temp;
        Node *temp1 = head;
        while (temp1->next != NULL)
            temp1 = temp1->next;
        temp1->next = temp;
        return head;
    }
    //Function to print a linked list ITERATIVE.
    void print(Node *head)
    {
        while (head != NULL)
        {
            cout << head->data << " ";
            head = head->next;
        }
    }
    void loopHere(Node *head, Node *tail, int pos)
    {
        if (pos == 0)
            return;
        Node *walk = head;
        for (int i = 1; i < pos; i++)
            walk = walk->next;
        tail->next = walk;
    }
    
    //Function to detect a loop in linked list using **HashMap**
    /*bool detectLoop(Node *h)
    {
        unordered_set<Node *> s;
        while (h)
        {
            // If this node is already present in hashmap it means there is a cycle(Because you we encountering the node for the second time).
            if (s.find(h) != s.end())
                return true;
            // If we are seeing the node for the first time, insert it in hash
            s.insert(h);
            h = h->next;
        }
        return false;
    }*/   //Disadvantage of this method is its space complexity is O(n);

    //Function to detect a loop in linked list using *** Floyd’s Cycle-Finding Algorithm ***.
    // In Const Space
    void removeLoop(Node* head)
    {
        Node *slow=head, *fast=head, *start=head, *prev;
        if(head==NULL || (head->next==NULL))return;
        while(fast!=NULL && fast->next!=NULL){
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                if(start==slow){
                    prev->next=NULL;
                    return;
                }
                while(start!=slow){
                    start=start->next;
                    if(start==slow->next)break;
                    slow=slow->next;
                }
                slow->next=NULL;
                return;
            }
        }
    }
};

int32_t main()
{
    Node *head = NULL;
    /* Start with the empty list */
    LinkedList ll;
    head = ll.insert(head, 20);
    head = ll.insert(head, 4);
    head = ll.insert(head, 15);
    head = ll.insert(head, 85);
    Node *tail = head;
    for (int i = 0; i < 3; i++)
        tail = tail->next;
    ll.loopHere(head, tail, 3);
    ll.removeLoop(head);
    ll.print(head);cout<<endl;
    return 0;
}