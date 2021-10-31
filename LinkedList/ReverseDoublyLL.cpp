// Write a Program to reverse the Doubly Linked List. (Both Iterative and recursive)
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
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
        temp->prev=NULL;
        if(head==NULL){
            return temp;
        }
        Node* temp1=head;
        while(temp1->next!=NULL)temp1=temp1->next;
        temp1->next=temp;
        temp->prev=temp1;
        return head;
    }
    //Function to print a linked list ITERATIVE.
    void print(Node* head){
        while(head!=NULL){
            cout<<head->data<<" ";
            head=head->next;
        }
    }

    //Function to reverse a linked list **ITERATIVE**.
    /*Node* reverse(Node *head)
    {
        if(head==NULL || head->next==NULL) return head;
        Node *curr= head, *newHeadPtr=NULL;
        while(curr){
            newHeadPtr=curr->prev;
            curr->prev=curr->next;
            curr->next=newHeadPtr;
            curr=curr->prev;
        }
        return newHeadPtr->prev;
    }*/

    //Function to reverse a linked list ***Recursive***.
    Node* reverse(Node *head)
    {
        if(!head) return NULL;
        Node* temp=head->next;
        head->next=head->prev;
        head->prev=temp;
        if(!(head->prev)) return head; 
        return reverse(head->prev);
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
    cout << "Given linked list\n";
    ll.print(head);cout<<endl;
    head=ll.reverse(head);
    ll.print(head);
    return 0;
}