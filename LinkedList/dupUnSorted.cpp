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
    //Function to remove duplicates from unsorted linked list.
    Node* removeDuplicates(Node *head)
    {
        //using sets in STL to store no duplicates of an element in list. 
        unordered_set<int> dup;
        Node* currNode=head;
        while(currNode->next){
            dup.insert(currNode->data);
            //if data at current node is already present in set, we skip the current node and store the node next to current node. 
            if(dup.find(currNode->next->data)!=dup.end())currNode->next=currNode->next->next;// We cam also delete(curr->next->next) to save memory
            else currNode=currNode->next;// else moving forward andupdating current to the next node.
        }
        return head;
    }
    }// Time complexity O(Nodes);
     // Auxilary Space O(Nodes)->worst case;
    
};

int32_t main()
{
    Node* head=NULL;
    /* Start with the empty list */
    LinkedList ll;
    head=ll.insert(head, 75);
    head=ll.insert(head, 4);
    head=ll.insert(head, 20);
    head=ll.insert(head, 75);
    head=ll.insert(head, 20);
    cout << "Given UnSorted linked list is : ";
    ll.print(head);cout<<endl;
    head=ll.removeDuplicates(head);
    ll.print(head);
    return 0;
}