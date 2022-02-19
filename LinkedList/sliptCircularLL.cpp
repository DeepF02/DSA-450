// Split a Circular linked list into two halves.
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
    // Function to print a linked list ITERATIVE.
    void print(Node *head)
    {
        while (head != NULL)
        {
            cout << head->data << " ";
            head = head->next;
        }
    }
    // Function which splits the circular linked list.  head is pointer to head Node of given lined list.  head1_ref1 and *head_ref2
    // are pointers to head pointers of resultant two halves.
    void splitList(Node *head, Node **head1_ref, Node **head2_ref)
    {
        // your code goes here
        Node *slow = head, *curr = head, *fast = head, *prev = NULL;
        while (curr->next != head)
            curr = curr->next;
        curr->next = NULL;
        while (fast && fast->next)
        {
            prev = slow;
            fast = fast->next->next;
            slow = slow->next;
        }
        if (!fast)
        {
            curr->next = slow;
            prev->next = head;
        }
        else
        {
            fast->next = slow->next;
            slow->next = head;
        }
        *head1_ref = head;
        *head2_ref = curr->next;
    }
};

int32_t main()
{
    Node *head = NULL;
    /* Start with the empty list */
    LinkedList ll;
    head = ll.insert(head, 1);
    head = ll.insert(head, 2);
    head = ll.insert(head, 4);
    head = ll.insert(head, 5);
    head = ll.insert(head, 7);
    head->next->next->next->next = head;
    (ll.isCircular(head)) ? cout << "Given linked list is Circular\n" : cout << "Given linked list is NOT Circular\n";
    return 0;
}