#include<bits/stdc++.h>	//#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    public:
    Node(int data1, Node* next1){
        data = data1;
        next = next1;
    }

    public:
    Node(int data1){
        data = data1;
        next = nullptr;
    }
};


// 1. Array to LL:
Node* array2LL(vector<int>& v){
    if(v.size() == 0) return NULL;

    Node* head = new Node(v[0]);
    Node* mover = head;
    
    for(int i=1; i<v.size(); i++){
        Node* temp = new Node(v[i]);
        mover->next = temp;
        mover = temp;
    }

    return head;
}


// 2. Traversal LL  +   3. length of LL:
void traverseLL(Node* temp){
    int cnt = 0;

    while(temp){    // (temp != nullptr)
        cout << temp->data << " ";
        
        temp = temp->next;
        cnt++;
    }
    cout << "\nLength: " << cnt << endl;
    
}


// 4. find element
bool findInLL(Node* temp, int target){
    int cnt = 0;

    while(temp){    // (temp != nullptr)
        if(temp->data == target) return true;
        
        temp = temp->next;
    }
    return false;
}


int main(){
    int a = 2;
    Node* b = new Node(a, nullptr);


    vector<int> v = {11,22,33,44,55};
    Node* head = array2LL(v);
    cout << head->data << endl;

    traverseLL(head);

    cout << findInLL(head, 33) << endl;
    
    return 0;
}
