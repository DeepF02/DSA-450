// Write a Program to get middle Element of the Linked List. (Both Iterative and recursive)
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
    //Function to reverse a linked list ITERATIVE.
    Node* middleNode(Node *head)
    {
        Node *slow = head, *fast = head;
        // While slow moves by 1 step fast moves by 2
        // Hence when fast reaches at end slow will be at middle
        while (fast && fast->next) slow = slow->next, fast = fast->next->next; 
        return slow;
    }
    
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
    // head=ll.insert(head, 75);
    cout << "Given linked list\n";
    ll.print(head);cout<<endl;
    head=ll.middleNode(head);
    cout<<head->data;
    // ll.print(head);
    return 0;
}