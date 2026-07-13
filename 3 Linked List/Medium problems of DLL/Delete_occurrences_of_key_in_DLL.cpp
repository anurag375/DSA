#include<bits/stdc++.h>	//#include<iostream>
using namespace std;

class Node {
  public:
    int data;
    Node* next;
    Node* prev;

    Node(int x) {
        data = x;
        next = nullptr;
        prev = nullptr;
    }

    Node(int x, Node* next1, Node* prev1) {
        data = x;
        next = next1;
        prev = prev1;
    }
};


// GFG: https://www.geeksforgeeks.org/problems/delete-all-occurrences-of-a-given-key-in-a-doubly-linked-list/1
class Solution {    // Delete all occurrences of a key in DLL
  public:

    Node* deleteAllOccurOfX(Node* head, int x) {
    // t = n    s = 1
        Node* temp = head;
        while(temp){
            if(temp->data == x){
                Node* delNode = temp;
                if(temp == head) head = delNode->next;  // if head is to be deleted, Update the new head to the next node
                
                Node* nextNode = delNode->next;
                Node* prevNode = delNode->prev;
                if(prevNode) prevNode->next = nextNode;
                if(nextNode) nextNode->prev = prevNode;

                delete delNode;
                temp = nextNode;
            }else{
                temp = temp->next;
            }
        }
        return head;
    }
};

int main(){
    Solution s;

    Node* head = new Node(1);   
    head->next = new Node(3, nullptr, head);
    head->next->next = new Node(4, nullptr, head->next);
    head->next->next->next = new Node(5, nullptr, head->next->next);
    head->next->next->next->next = new Node(1, nullptr, head->next->next->next);
    head->next->next->next->next->next = new Node(8, nullptr, head->next->next->next->next);
    head->next->next->next->next->next->next = new Node(4, nullptr, head->next->next->next->next->next);

    int x = 1;
    head = s.deleteAllOccurOfX(head, x);

    while(head){
        cout << head->data << " ";
        head = head->next;
    }
    return 0;
}
// 1 3 4 5 1 8 4


// my-way [same logic BUT lengthy]:

        // if(head->next == nullptr){  // edge case: single-length LL
        //     if(head->data == x) return nullptr;
        //     else return head;
        // }

        // Node* temp = head;
        // while(temp){
        //     if(temp->data != x) temp = temp->next;

        //     else{
        //         if(temp == head){   // HEAD..
        //             Node* delNode = temp;
        //             head = delNode->next;
        //             head->prev = nullptr;
                    
        //             delete delNode;
        //             temp = head;
        //         }else if(temp->next == nullptr){    // TAIL..
        //             Node* delNode = temp;
        //             delNode->prev->next = nullptr;
        //             delete delNode;
                    
        //             temp = nullptr;
        //         }else{      // MIDDLE NODE..
        //             Node* delNode = temp;
        //             Node* prevNode = temp->prev;
        //             Node* frontNode = temp->next;
                    
        //             prevNode->next = frontNode;
        //             frontNode->prev = prevNode;
                    
        //             delete delNode;
        //             temp = frontNode;
        //         }
        //     }
        // }
        
        // return head;
