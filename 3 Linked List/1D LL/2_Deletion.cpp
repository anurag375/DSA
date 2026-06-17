
// 4 types:
    // 1. from head, 
    // 2. from tail, 
    // 3. via position, 
    // 4. via element/value

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


// ======== extra ========
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

void print(Node* temp){
    while(temp != NULL){    // (temp != nullptr)
        cout << temp->data << " ";
        temp = temp->next;
    }   
    cout << endl;
     
}
// ======== extra ======== ^


// 1. delete from head:
Node* deleteFromHead(Node* head){
    if(head == NULL) return head;
  
    Node* temp = head;    
    head = head->next;
    delete temp;    // free(temp)

    return head;
}

// 2. delete from tail:
Node* deleteFromTail(Node* head){
    if(head == NULL || head->next == NULL) return NULL;

    Node* temp = head;    
    while(temp->next->next != nullptr){
        temp = temp->next;
    }
    delete temp->next;  // free(temp->next)
    temp->next = nullptr;

    return head;
}

// 3. delete via position (k):
// **U** if k=1 (head), k=(somewhere in between), k=last_node
Node* deletePositionK(Node* head, int k){
    if(head == NULL) return head;

    if(k == 1){     // SAME logic: 1. delete from head
        Node* temp = head;
        head = head->next;
        delete temp;

        return head;
    }

    int cnt = 0;
    Node* temp = head; 
    Node* prev = NULL;  // *U* initially it stays somewhere before the head => as loop starts it stays just before 'temp'  
    while(temp != nullptr){
        cnt++;
        if(cnt == k){
            prev->next = temp->next;
            delete temp;    // free(temp)
            break;
        }
        prev = temp;
        temp = temp->next;
    }

    return head;
}

// 4. delete Value:
Node* deleteVal(Node* head, int val){   // MOSTly similar to 3.
    if(head == NULL) return head;

    if(head->data == val){     // SAME logic: 1. delete from head
        Node* temp = head;
        head = head->next;
        delete temp;

        return head;
    }

    Node* temp = head; 
    Node* prev = NULL; 
    while(temp != nullptr){
        if(temp->data == val){
            prev->next = temp->next;
            delete temp;    // free(temp)
            break;
        }
        prev = temp;
        temp = temp->next;
    }

    return head;
}


int main(){
    vector<int> v = {11,22,33,44,55,66,77,88,99};
    Node* head = array2LL(v);

    head = deleteFromHead(head);
    print(head);

    head = deleteFromTail(head);
    print(head);

    head = deletePositionK(head, 4);
    print(head);

    head = deleteVal(head, 44);
    print(head);
    
    return 0;
}
