// Implementing using Circular Array logic
#include <bits/stdc++.h>
using namespace std;

class MyQueue {
private:
    int n;
    int arr[100];
    int front=-1, rear=-1;

public :
    MyQueue(int N){
        this->n=N;
        // this->arr=new int[n];
    }
    // Time comeplexity O(N)
    void enqueue(int data){
        if((rear+1)%n==front)return;
        if(front==-1)front=0;
        rear=(rear+1)%n;
        arr[rear]=data;
    }
    // Time comeplexity O(N)
    int dequeue(){
        if(front==-1)return -1;
        int result=arr[front];
        if(rear==front)front=rear=-1;
        else front=(front+1)%n;
        return result;
    }
};

int32_t main()
{
    MyQueue q(5);
    q.enqueue(0);
    q.enqueue(1);
    q.enqueue(4);
    q.enqueue(3);
    q.enqueue(2);
    for(int i=0; i<5; i++){
        cout<<q.dequeue()<<"  ";
    }
    return 0;
}