// Add two numbers represented by linked lists.
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
    
    //Function to reverse a linked list ***Recursive***.
    Node* reverse(Node *head)
    {
        if(head==NULL || head->next==NULL) return head;
        Node* curr = reverse(head->next);
        head->next->next=head;
        head->next=NULL;
        return curr;
    }
    //Function to add two numbers represented by linked list.
    Node* addTwoLists(Node* first, Node* second)
    {
        //reversing both lists and stroing new head in ptr1 & ptr2 for simplification of addition.
        Node *ptr1=reverse(first), *ptr2=reverse(second);
        int carry=0;
        Node* ans=NULL;
        // using a loop till both lists and carry gets exhausted.
        while(ptr1 || ptr2 || carry){
            int newVal=carry;//using a newVal to store sum of two digits along with carry.
            if(ptr1)newVal+=ptr1->data;
            if(ptr2)newVal+=ptr2->data;
            carry=newVal/10;//updating carry.
            newVal=newVal%10;//using modulus to store last digit at that place.
            Node* temp=new Node(newVal);
            temp->next=ans;//storing the previously made nodes in the link part of new node.
            ans=temp;//making the new node as the first node of all previously made node.
            // Then moving our pointers
            if(ptr1)ptr1=ptr1->next;
            if(ptr2)ptr2=ptr2->next;
        }
        return ans;
    }// Time Complexity: O(m + n), where m and n are numbers of nodes in first and second lists respectively. 
    // Space Complexity: O(m + n). A temporary linked list is needed to store the output number
};

int32_t main()
{
    Node* head1=NULL;
    Node* head2=NULL;
    /* Start with the empty list */
    LinkedList ll;
    head1=ll.insert(head1, 1);
    head1=ll.insert(head1, 2);
    head1=ll.insert(head1, 3);
    head1=ll.insert(head1, 5);
    head2=ll.insert(head2, 6);
    head2=ll.insert(head2, 7);
    head2=ll.insert(head2, 8);
    head2=ll.insert(head2, 9);
    Node* newHead=ll.addTwoLists(head1, head2);
    ll.print(newHead);
    return 0;
}