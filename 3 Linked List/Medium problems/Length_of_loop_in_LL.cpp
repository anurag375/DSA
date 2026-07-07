#include<bits/stdc++.h>	//#include<iostream>
using namespace std;

class ListNode{
public:
    int val;
    ListNode *next;

public:
    ListNode(int data1, ListNode *next1){
        val = data1;
        next = next1;
    }

public:
    ListNode(int data1){
        val = data1;
        next = nullptr;
    }
};

class Solution {    // Length of loop in LL

// OPTIMAL: (Floyd's Tortoise-Hare): [similar to OPTIMAL LC_141]    t = around O(n)   s = 1
    int findLoopLength(ListNode* start){
        ListNode* mover = start;
        int cnt = 1;
        mover = mover->next;
        while(start != mover){
            cnt++;
            mover = mover->next;
        }
        return cnt;
    }

public:
    int findLengthOfLoop(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast) return findLoopLength(slow);   // [ONLY this user-defined func. is diff. from LC_141's OPTIMAL]
        }
        return 0;
    }
};


int main(){
    Solution s;
    ListNode *head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = head->next->next;    // *U* 4th node loops with 3rd node

    cout << s.findLengthOfLoop(head) << endl;
    return 0;
}


// both BRUTE : [similar to BRUTE LC_141] (using unordered_map)

    // BRUTE (striver): (less loops): t = (n + k) = n [where n = total length; k = length of loop]   s = n
        // ListNode* temp = head;
        // unordered_map<ListNode*, int> mp;   // int = step-count (1, 2, 3, ..) ; 0 = not found
        // int steps = 0;

        // while(temp){
        //     if(mp[temp] != 0){  // loop found => start counting
        //         int lastLoopStep = steps;
        //         int firstLoopStep = mp[temp];
        //         return lastLoopStep - firstLoopStep + 1;    // *U*
        //     }
        //     steps++;
        //     mp[temp] = steps;
        //     temp = temp->next;
        // }
        // return 0;



    // BRUTE (my-way): (nested loops) t = (n + k) = n    s = n
        // ListNode* temp = head;
        // unordered_map<ListNode*, bool> mp;

        // while(temp){
        //     if(mp[temp] == 1){  // loop found => start counting
        //         int cnt = 1;
        //         ListNode* start = temp;
        //         temp = temp->next;
        //         while(start != temp){
        //             cnt++;
        //             temp = temp->next;  
        //         }
        //         return cnt;

        //     }
        //     mp[temp] = 1;
        //     temp = temp->next;
        // }
        // return 0;
