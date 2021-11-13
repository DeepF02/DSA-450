// Add two numbers represented by linked lists.
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

// Node* head=NULL; // Global declaration of head

class LinkedList
{
public:
    //Function to insert data in a linked list ITERATIVE.
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
    //Function to print a linked list ITERATIVE.
    void print(Node *head)
    {
        while (head != NULL)
        {
            cout << head->data << " ";
            head = head->next;
        }
    }
    
    //Function to return head node of list contaning intersection of 2 sorted linked list.
    Node *findIntersection(Node *head1, Node *head2){
        Node *ptr1 = head1, *ptr2 = head2;
        Node *tail = NULL, *head = NULL;
        while (ptr1 && ptr2){
            if (ptr1->data == ptr2->data){
                // if head doesn't exist i.e we need to creat new list from start
                if (!head) head = tail = new Node(ptr2->data);
                else{
                    tail->next = new Node(ptr2->data);//pointing tail's of next to new node
                    tail= tail->next;//moving tail to it's next node
                }
                //Moving both pointer nodes
                ptr1 = ptr1->next;
                ptr2 = ptr2->next;
            }
            // moving to next node in list with smaller node
            else if (ptr1->data < ptr2->data) ptr1 = ptr1->next;
            else ptr2 = ptr2->next;
        }
        return head;
    } // Time Complexity: O(m + n), where m and n are numbers of nodes in first and second lists respectively.
    // Space Complexity: O(m + n). A temporary linked list is needed to store the output number
};

int32_t main()
{
    Node *head1 = NULL;
    Node *head2 = NULL;
    /* Start with the empty list */
    LinkedList ll;
    head1 = ll.insert(head1, 1);
    head1 = ll.insert(head1, 2);
    head1 = ll.insert(head1, 3);
    head1 = ll.insert(head1, 4);
    head1 = ll.insert(head1, 6);
    head2 = ll.insert(head2, 2);
    head2 = ll.insert(head2, 4);
    head2 = ll.insert(head2, 6);
    head2 = ll.insert(head2, 8);
    Node *newHead = ll.findIntersection(head1, head2);
    ll.print(newHead);
    return 0;
}