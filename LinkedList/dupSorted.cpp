// Remove Duplicates in a sorted Linked List.
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
    //Function to remove duplicates from sorted linked list.
    Node* removeDuplicates(Node *head)
    {
        Node* currNode=head;
        /* do nothing if the list is empty */
        if(!currNode || !currNode->next)return head;
        /* Traverse the list till last node */
        while(currNode->next){
            if(currNode->data==currNode->next->data) currNode->next=currNode->next->next;
            /* This is tricky: only advance if no deletion */
            else currNode=currNode->next;
        }
    return head;
    }// Time complexity O(Nodes);
     // Auxilary Space O(1);
    
};

int32_t main()
{
    Node* head=NULL;
    /* Start with the empty list */
    LinkedList ll;
    head=ll.insert(head, 20);
    head=ll.insert(head, 4);
    head=ll.insert(head, 4);
    head=ll.insert(head, 75);
    head=ll.insert(head, 75);
    cout << "Given Sorted linked list is : ";
    ll.print(head);cout<<endl;
    head=ll.removeDuplicates(head);
    ll.print(head);
    return 0;
}