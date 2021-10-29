// Write a Program to reverse the Linked List. (Both Iterative and recursive)
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
    Node* reverse(Node *head)
    {
        Node *curr, *prev, *next;
        curr=head;
        prev=NULL;
        while(curr!=NULL){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        head=prev;
        return head;
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