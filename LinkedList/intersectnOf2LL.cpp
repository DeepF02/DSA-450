// Intersection Point of two Linked Lists.
#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node *next;
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

class LinkedList{
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
    //Function to loop 2nd list with list 1 at node dataX. 
    Node *yLoop(Node *head, int dataX)
    {
        while(head->data!=dataX)head=head->next;
        return head;
    }

    //Function to find intersection point in Y shaped Linked Lists.
    int intersectPoint(Node *head1, Node *head2)
    {
        int n = 0, m = 0;
        Node *curr1 = head1, *curr2 = head2;
        while (head1){//Loop to get size of list1
            head1 = head1->next;
            ++n;
        }
        while (head2){//Loop to get size of list2
            head2 = head2->next;
            ++m;
        }
        //we compare which list has greater size and intialize curr1 to that list
        if (n < m) swap(curr1, curr2);
        // We traverse through greater length list till we get to same length of another list start
        for (int i = 0; i < abs(n - m); ++i) curr1 = curr1->next;
        //Now we simply traverse ahead till we get the intersection point
        while (curr1 != curr2)//If there is none, this loop will break when both pointers point at NULL.
        {
            curr1 = curr1->next;
            curr2 = curr2->next;
        }
        return curr1->data;
    } // Time Complexity: O(m + n), where m and n are numbers of nodes in first and second lists respectively.
    // Space Complexity: O(1), constant time.
};

int32_t main()
{
    /* 
        Create two linked lists 
    
        1st 3->6->9->15->30 
        2nd 10->15->30 
    
        15 is the intersection point 
    */
    Node *head1 = NULL;
    Node *head2 = NULL;
    /* Start with the empty list */
    LinkedList ll;
    head1 = ll.insert(head1, 3);
    head1 = ll.insert(head1, 6);
    head1 = ll.insert(head1, 9);
    head1 = ll.insert(head1, 15);
    head1 = ll.insert(head1, 30);
    head2 = ll.insert(head2, 10);
    head2->next=ll.yLoop(head1, 15);// we loop head 2 at node 15
    cout<< "The node of intersection is " << ll.intersectPoint(head1, head2)<<endl;

    return 0;
}