// Check if Linked List is Palindrome .
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

class LinkedList
{
public:
    // Function to insert data in a linked list ITERATIVE.
    Node *insert(Node *head, int dataX)
    {
        Node *temp = new Node(dataX);
        if (head == NULL)
            return temp;
        Node *temp1 = head;
        while (temp1->next != NULL)
            temp1 = temp1->next;
        temp1->next = temp;
        return head;
    }
    //Function to Reverse a linked list ITERATIVE.
    Node* reverse(Node* head){
        Node *curr=head, *prev=NULL, *nex;
        while(curr){
            nex=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nex;
        }
        return prev;
    }
    
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        //Your code here
        int cnt=0;//this will count the middle of Linked-list
        Node *newHead, *slow=head, *fast=head;
        //Get the middle of the linked list. 
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
            cnt++;
        }
        newHead=reverse(slow);//Reverse the second half of the linked list. 
        // Check if the first half and second half are identical. 
        while(cnt--){
            if(head->data!=newHead->data)return 0;
            newHead=newHead->next;
            head=head->next;
        }
        return 1;
    }// Time Complexity: O(n) where n is the number of nodes in the given Linked List.
     // Auxilary Space: O(1).
};

int32_t main()
{
    Node *head = NULL;
    /* Start with the empty list */
    LinkedList ll;
    head = ll.insert(head, 1);
    head = ll.insert(head, 2);
    head = ll.insert(head, 4);
    head = ll.insert(head, 2);
    head = ll.insert(head, 1);
    (ll.isPalindrome(head)) ? cout << "Given linked list is Palindrome\n" : cout << "Given linked list is NOT Palindrome\n";
    return 0;
}