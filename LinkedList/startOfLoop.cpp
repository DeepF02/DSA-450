// Find the starting point of the loop. 
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
    Node *insert(Node *head, int dataX)
    {
        Node *temp = new Node();
        temp->data = dataX;
        temp->next = NULL;
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
    void loopHere(Node *head, Node *tail, int pos)
    {
        if (pos == 0)
            return;
        Node *walk = head;
        for (int i = 1; i < pos; i++)
            walk = walk->next;
        tail->next = walk;
    }
    
    //Function to detect a loop in linked list using **HashMap**
    /*int detectLoop(Node *h)
    {
        unordered_set<Node *> s;
        while (h)
        {
            // If this node is already present in hashmap it means there is a cycle(Because you we encountering the node for the second time).
            if (s.find(h) != s.end())
                return h->data;
            // If we are seeing the node for the first time, insert it in hash
            s.insert(h);
            h = h->next;
        }
        return false;
    }*/   //Disadvantage of this method is its space complexity is O(n);

    //Function to detect a loop in linked list using *** Floyd’s Cycle-Finding Algorithm ***.
    // In Const Space
    int detectLoop(Node *head)
    {
        // your code here
        Node *slow = head, *fast = head;
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next; // this is called Floyd’s Cycle-Finding Algorithm.
            if (slow == fast){
                fast=head;
                while(fast!=slow){
                    slow=slow->next;
                    fast=fast->next;
                }
                return fast->data;
            }
        }
        return 0;
    }
};

int32_t main()
{
    Node *head = NULL;
    /* Start with the empty list */
    LinkedList ll;
    head = ll.insert(head, 20);
    head = ll.insert(head, 4);
    head = ll.insert(head, 15);
    head = ll.insert(head, 85);
    head = ll.insert(head, 69);
    head = ll.insert(head, 56);
    head = ll.insert(head, 74);
    Node *tail = head;
    for (int i = 0; i < 6; i++)
        tail = tail->next;
    ll.loopHere(head, tail, 5);
    // cout << "Given linked list\n";
    // ll.print(head);cout<<endl;
    int ans = ll.detectLoop(head);
    (ans) ? cout << "Loop exist here "<<ans<<endl : cout << "Loop doesn't exist\n";
    return 0;
}