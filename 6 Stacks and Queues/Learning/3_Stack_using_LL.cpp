#include<bits/stdc++.h>
using namespace std;

class Node{ // Implement stack using Linkedlist
    public:
    int data;
    Node* next;

    Node(int d, Node* n){
        data = d;
        next = n;
    }

    Node(int d){
        data = d;
        next = nullptr;
    }
};

class StackUsingLL{
public:
    Node* topNode  = nullptr;
    int sizeCnt = 0;

    void push(int data){
        Node* newNode = new Node(data, topNode);
        topNode = newNode;
        sizeCnt++;
    }

    void pop(){
        if(topNode == nullptr) 
            cout << "Stack is empty.." << endl;
        else{
            Node* temp = topNode;
            topNode = topNode->next;
            delete temp;
            sizeCnt--;
        }
    }

    int top(){
        if(topNode == nullptr){
            cout << "Stack is empty.." << endl;
            return -1;  // // assuming the stack doesn't store -ve elements
        }
        return topNode->data;
    }

    int size(){     // return type usually int, long long..
        return sizeCnt;
    }
};


int main(){
    StackUsingLL s;

    cout << "Initial size: " << s.size() << endl;

    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Top element: " << s.top() << endl;
    cout << "Stack size: " << s.size() << endl;

    s.pop();

    cout << "After pop:" << endl;
    cout << "Top element: " << s.top() << endl;
    cout << "Stack size: " << s.size() << endl;

    s.push(40);

    cout << "After pushing 40:" << endl;
    cout << "Top element: " << s.top() << endl;
    cout << "Stack size: " << s.size() << endl;

    s.pop();
    s.pop();
    s.pop();

    cout << "Stack size: " << s.size() << endl;

    // Stack is empty
    s.top();
    s.pop();

    return 0;
}

// ⭐⭐ 
// T.C = O(1)   [for push, pop, top, and size]
// S.C = O(n)   [n = no. of current nodes]  ==>  Advantage
