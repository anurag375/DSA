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


// GFG: https://www.geeksforgeeks.org/problems/find-pairs-with-given-sum-in-doubly-linked-list/1
class Solution {    // Find Pairs with Given Sum in Doubly Linked List
  public:

    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target) {
    // OPTIMAL: [two-pointers] [WORKS since LL is sorted] t = (n + n) = n       s = n [only to store the answer]
    // (similar to what we did in arrays)

        vector<pair<int, int>> ans;
        if(head == nullptr) return ans;
        Node* left = head;
        Node* right = head;

        // 1> send 'right' to the tail
        while(right->next){ // *U* it should STOP at the tail
            right = right->next;
        }

        // 2> compare and store results
        while(left->data < right->data){
            if(left->data + right->data == target){
                ans.push_back({left->data, right->data});
                left = left->next;
                right = right->prev;
            }
            else if(left->data + right->data < target) left = left->next;
            else right = right->prev;
        }

        return ans;
    }
};

int main(){
    Solution s;

    Node* head = new Node(1);   
    head->next = new Node(2, nullptr, head);
    head->next->next = new Node(4, nullptr, head->next);
    head->next->next->next = new Node(5, nullptr, head->next->next);
    head->next->next->next->next = new Node(6, nullptr, head->next->next->next);
    head->next->next->next->next->next = new Node(8, nullptr, head->next->next->next->next);
    head->next->next->next->next->next->next = new Node(9, nullptr, head->next->next->next->next->next);

    int target = 7;
    vector<pair<int, int>> ans = s.findPairsWithGivenSum(head, target);

    for(pair<int,int> pr:ans){
        cout << pr.first << " " << pr.second << endl;
    }
    return 0;
}


    // BRUTE: t = n*n       s = n/2 = n [only to store the answer]
        // vector<pair<int, int>> ans;
        // Node* temp1 = head;

        // while(temp1->next){
        //     Node* temp2 = temp1->next;
        //     // while(temp2 != nullptr && (temp1->data + temp2->data) <= target){     // *U* breaks early
        //         // or..
        //     while(temp2){
        //         if(temp1->data + temp2->data == target) ans.push_back({temp1->data, temp2->data});
        //         temp2 = temp2->next;
        //     }
        //     temp1 = temp1->next;
        // }

        // return ans;