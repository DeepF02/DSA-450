// Write a Program to Move the last element to Front in a Linked List.
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
    Node* insert(Node* head, int dataX){
        Node*temp=new Node();
        temp->data=dataX;
        temp->next=NULL;
        if(head==NULL)return temp;
        Node* temp1=head;
        while(temp1->next!=NULL)temp1=temp1->next;
        temp1->next=temp;
        return head;
    }
    //Function to print a linked list ITERATIVE.
    void print(Node* head){
        while(head!=NULL){
            cout<<head->data<<" ";
            head=head->next;
        }
    }
    //Function to move last node to first node of a linked list (ITERATIVE).
    Node* lastToFrist(Node *head)
    {
        if (!head || !head->next) return; 
        //curr will point to curr Node and prev will point to previous node of curr
        Node *curr = head, *prev = NULL;
        while (curr->next) {
            prev=curr;
            curr=curr->next;
        }
        //Now curr is pointing to last Node and prev is pointing to 2nd last node
        curr->next=head;//we point last node to head i.e. 1st Node
        prev->next=NULL;//And we point 2nd last node NULL
        return curr;
    }// Time Complexity: O(n) where n is the number of nodes in the given Linked List.
     // Auxilary Space: O(1).
    
};

int32_t main()
{
    Node* head=NULL;
    /* Start with the empty list */
    LinkedList ll;
    head=ll.insert(head, 20);
    head=ll.insert(head, 4);
    head=ll.insert(head, 15);
    head=ll.insert(head, 85);
    head=ll.insert(head, 75);
    cout << "Given linked list\n";
    ll.print(head);cout<<endl;
    head=ll.lastToFrist(head);
    ll.print(head);
    return 0;
}