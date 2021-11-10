// Check if a linked list is a circular linked list.
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    Node(int val){
        data=val;
        next=NULL;
    }
};


class LinkedList
{
    public:
    //Function to insert data in a linked list ITERATIVE.
    Node* insert(Node* head, int dataX){
        Node*temp=new Node(dataX);
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

    //Function to return true if linked list is circular, else false */
    bool isCircular(Node *head)
    {
        if(!head) return true;
        Node* currNode=head;
        while(currNode){
            if(currNode->next==head)return true;
            currNode=currNode->next;
        }
        return false;
    }
};

int32_t main()
{
    Node* head=NULL;
    /* Start with the empty list */
    LinkedList ll;
    head=ll.insert(head, 1);
    head=ll.insert(head, 2);
    head=ll.insert(head, 4);
    head=ll.insert(head, 5);
    head=ll.insert(head, 7);
    head->next->next->next->next = head;
    (ll.isCircular(head))?cout<<"Given linked list is Circular\n":cout<<"Given linked list is NOT Circular\n";
    return 0;
}