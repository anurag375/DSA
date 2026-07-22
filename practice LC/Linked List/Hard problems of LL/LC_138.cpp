#include<bits/stdc++.h>	//#include<iostream>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

class Solution {    // 138. Copy List with Random Pointer
public:
    Node* copyRandomList(Node* head) {
    // optimal: (adding new nodes in between the old LL)    
    // t = 3n      s = n [only to create, store the new LL]

        if(head == nullptr) return head;

        // 1> insert copy-nodes in between
        Node* temp = head;
        while(temp){
            Node* copyNode = new Node(temp->val);
            copyNode->next = temp->next;
            temp->next = copyNode;

            temp = copyNode->next;    // **U** NEVER write temp = temp->next;
            // or
            // temp = temp->next->next;
        }

        // 2> connect/match the 'random' pointers
        temp = head;
        while(temp){
            Node* copiedNode = temp->next;
            if(temp->random) copiedNode->random = temp->random->next;
            else copiedNode->random = nullptr;   // *U* what if temp->random = nullptr

            temp = temp->next->next;
        }

        // 3> get deep-copy LL [match the 'next' pointers + separate both LLs] ==> [little diif. from striver's code]
        Node* dummyNode = new Node(-1); 
        dummyNode->next = head->next;   // *U*

        temp = head;
        while(temp->next){  // *U* must stop on reaching the last node
            Node* markNextNode = temp->next;
            temp->next = temp->next->next;

            temp = markNextNode;
        }

        return dummyNode->next;    // *U* 
    }
};

int main(){

    // Create nodes
    Node* n1 = new Node(7);
    Node* n2 = new Node(13);
    Node* n3 = new Node(11);
    Node* n4 = new Node(10);
    Node* n5 = new Node(1);

    // Connect next pointers
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;

    // Connect random pointers
    n1->random = nullptr;
    n2->random = n1;
    n3->random = n5;
    n4->random = n3;
    n5->random = n1;

    Node* head = n1;

    Solution s;
    head = s.copyRandomList(head);

    // NO proper OUTPUT.. BUT the code is CORRECT
    while(head){
        cout << head->val << " ";
        head = head->next;
    }

    return 0;
}


    // brute: (hash map)    t - 2n = n      s = n + n   [for map + copy nodes of new LL]
        // unordered_map<Node*, Node*> mp;

        // // 1> create new nodes (without connnecting) + store BOTH (old, new) in a hash-map
        // Node* temp = head;
        // while(temp){
        //     Node* newNode = new Node(temp->val);
        //     mp[temp] = newNode;
        //     temp = temp->next;
        // }

        // // 2> connect the nodes of new LL
        // temp = head;
        // while(temp){
        //     Node* newNode = mp[temp];
        //     newNode->next =  mp[temp->next];
        //     newNode->random =  mp[temp->random];

        //     temp = temp->next;
        // }

        // return mp[head];    // *U* head (being a node) was already stored before (step 1)

