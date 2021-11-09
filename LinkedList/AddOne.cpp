// Add “1” to a number represented as a Linked List.
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

// Node* head=NULL; // Global declaration of head

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
    //Function to reverse a linked list **ITERATIVE**.
    // Node* reverse(Node *head)
    // {
    //     Node *curr, *prev, *next;
    //     curr=head;
    //     prev=NULL;
    //     while(curr!=NULL){
    //         next=curr->next;
    //         curr->next=prev;
    //         prev=curr;
    //         curr=next;
    //     }
    //     return prev;
    // }
    
    //Function to reverse a linked list ***Recursive***.
    Node* reverse(Node *head)
    {
        if(head==NULL || head->next==NULL) return head; //we check base conditon for 2nd last node
        Node* curr = reverse(head->next); //when we reach to our base condition curr has address of last node
        // Node* prevCurr=head->next;
        // prevCurr->next=head;
        //we can reduce above 2 statement to single statement as
        head->next->next=head; //head here is pointing to 2nd last node and we make last Node point to this node i.e head
        head->next=NULL; // We make this node i.e. currently 2nd last node point to null 
        return curr;
    }
    //Function to add one at end of a linked list .
    Node* addOne(Node *head) 
    {
        // return head of list after adding one
        if(!head) return head;
        Node* currNode, *prevNode;
        prevNode=currNode=reverse(head);
        if(currNode->data<9)currNode->data++;
        else{
            while(currNode->next && currNode->data==9){
                currNode->data=0;
                currNode=currNode->next;
            }
            if(currNode->data<9)currNode->data++;
            else{
                currNode->data=0;
                Node* newNode= new Node(1);
                // newNode->data=1;
                // newNode->next=NULL;
                currNode->next=newNode;
            }
        }
        return reverse(prevNode);
    }
};

int32_t main()
{
    Node* head=NULL;
    /* Start with the empty list */
    LinkedList ll;
    head=ll.insert(head, 9);
    head=ll.insert(head, 9);
    head=ll.insert(head, 9);
    head=ll.insert(head, 9);
    cout << "Given linked list\n";
    ll.print(head);cout<<endl;
    head=ll.addOne(head);
    ll.print(head);
    return 0;
}