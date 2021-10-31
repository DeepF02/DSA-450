// Reverse a Linked List in group of Given Size. [Very Imp]
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
    //Function to reverse a linked list in group of K.
    Node *reverse (struct Node *head, int k)
    { 
        // Complete this method
        Node *curr, *prev, *Next;
        curr=head;
        prev=NULL;
        int n=k;
        while(curr!=NULL && n--){
            if(curr==NULL)break;
            Next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=Next;
        }
        if(Next!=NULL) head->next=reverse(Next, k);
        return prev;
    }  
};

int32_t main()
{
    Node* head=NULL; // Start with the empty list 
    LinkedList ll;
    head=ll.insert(head, 20);
    head=ll.insert(head, 4);
    head=ll.insert(head, 15);
    head=ll.insert(head, 85);
    head=ll.insert(head, 55);
    head=ll.insert(head, 69);
    head=ll.insert(head, 71);
    head=ll.insert(head, 47);
    head=ll.insert(head, 36);
    head=ll.insert(head, 23);
    int k;
    cin>>k;
    cout << "Given linked list\n";
    ll.print(head);cout<<endl;
    head=ll.reverse(head, k);
    ll.print(head);
    return 0;
}
// Time Complexity: O(n). 
// Traversal of list is done only once and it has 'n' elements.
// Auxiliary Space: O(n/k). 
// For each Linked List of size n, n/k or (n/k)+1 calls will be made during the recursion