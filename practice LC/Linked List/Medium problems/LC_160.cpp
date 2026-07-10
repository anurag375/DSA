#include<bits/stdc++.h>	//#include<iostream>
using namespace std;

class ListNode{
public:
    int val;
    ListNode* next;
public:
    ListNode(int data1, ListNode* next1){
        val = data1;
        next = next1;
    }
public:
    ListNode(int data1){
        val = data1;
        next = nullptr;
    }
};

class Solution {    // 160. Intersection of Two Linked Lists
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // OPTIMAL: t = (n + m)    s = 1
        if(headA == nullptr || headB == nullptr) return nullptr; // no need for this ques.

        ListNode* t1 = headA;
        ListNode* t2 = headB;

        while(t1 != t2){    // **U** this condition also checks if both heads are same  (both LL are same)
            t1 = t1->next;
            t2 = t2->next;

            if(t1 == t2) return t1;

            if(t1 == nullptr) t1 = headB;
            if(t2 == nullptr) t2 = headA;
        }
        
        return t1;  // or 't2'  // **U** if ans NOT FOUND (or if both LL are same) ==> both 
    }
};

int main(){
    Solution s;

    ListNode* head1 = new ListNode(4);
    head1->next = new ListNode(1);
    head1->next->next = new ListNode(8);
    head1->next->next->next = new ListNode(4); 
    head1->next->next->next->next = new ListNode(5); 

    ListNode* head2 = new ListNode(5);
    head2->next = new ListNode(6);
    head2->next->next = new ListNode(1);

    head2->next->next->next = head1->next->next;    // *U* node 8 is intersected..

    ListNode* ansNode = s.getIntersectionNode(head1, head2);    // start node of loop
    int ans = (ansNode == nullptr) ? -1 : ansNode->val;     // * see
    cout << ans << endl;
    return 0;
}


// BETTER:  t = n + m + (greater - smaller) + smaller      s = 1

// class Solution {
//     ListNode* skipFrontNodes(ListNode* temp1, ListNode* temp2, int skip){
//         // 2> skip the extra nodes from the larger LL
//         while(skip > 0){
//             temp1 = temp1->next;
//             skip--;
//         }

//         // 3> try finding the intersecting node
//         while(temp1 != temp2){  // *U*
//             temp1 = temp1->next;
//             temp2 = temp2->next;
//         }
//         return temp1;   // ***U*** if intersection FOUND => that node is returned ; if NOT found => "nullptr" is returned automatically
//     }

// public:
//     ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
//         ListNode* temp1 = headA;
//         ListNode* temp2 = headB;
//         int size1 = 0;
//         int size2 = 0;

//         // 1> find size1 and size2
//         while(temp1){
//             size1++;
//             temp1 = temp1->next;
//         }
//         while(temp2){
//             size2++;
//             temp2 = temp2->next;
//         }

//         // 2> 
//         if(size1 > size2)
//             return skipFrontNodes(headA, headB, size1 - size2); // *U* (longer, shorter, size_difference)
//         else
//             return skipFrontNodes(headB, headA, size2 - size1); // *U* (longer, shorter, size_difference)
        
//         // return nullptr;  // JUST a demo placeholder
//     }
// };


// ============================



// BRUTE (striver): (GOOD TC)   t = size(1st LL) + size(2nd LL)      s = size(2nd LL)
        // unordered_map<ListNode*, bool> mp;    // bool = true(1) means VISITED | false(0) means NOT visited
        // ListNode* temp = headA;

        // // 1> hash the nodes
        // while(temp){
        //     mp[temp] = true;
        //     temp = temp->next;
        // }

        // // 2> match the nodes
        // temp = headB;
        // while(temp){
        //     if(mp[temp] == true) return temp;
        //     temp = temp->next;
        // }

        // return nullptr;



// ============================
// ====== (my-way below) ======

    // (my-way)
    // BRUTE: (NOT good TC)   t = n*m     s = 1
        // ListNode* temp1 = headA;

        // while(temp1){
        //     ListNode* temp2 = headB;
        //     while(temp2){
        //         if(temp1 == temp2) return temp2;
        //         temp2 = temp2->next;
        //     }
        //     temp1 = temp1->next;
        // }
        // return nullptr;


// ============================


// (my-way)
// BETTER:       t = [same as striver's BETTER]      s = 1  [same]

// class Solution {
//     ListNode* skipFrontNodes(ListNode* temp, int skip){
//         while(skip > 0){
//             temp = temp->next;
//             skip--;
//         }
//         return temp;
//     }

// public:
//     ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

//         ListNode* temp1 = headA;
//         ListNode* temp2 = headB;
//         int size1 = 0;
//         int size2 = 0;

//         // 1> find size1 and size2
//         while(temp1){
//             size1++;
//             temp1 = temp1->next;
//         }
//         while(temp2){
//             size2++;
//             temp2 = temp2->next;
//         }

//         // 2> skip the extra nodes from the larger LL
//         if(size1 > size2){
//             temp1 = skipFrontNodes(headA, size1 - size2);
//             temp2 = headB;  // *U* resets position
//         }
//         else if(size1 < size2){
//             temp2 = skipFrontNodes(headB, size2 - size1);
//             temp1 = headA;  // *U* resets position
//         }else{              // *U* [same size]  resets position
//             temp1 = headA;
//             temp2 = headB;
//         }

//         // 3> try finding the intersecting node
//         while(temp1){   // or temp2 [both are valid]
//             if(temp1 == temp2) return temp1;
//             temp1 = temp1->next;
//             temp2 = temp2->next;
//         }

//         return nullptr;
//     }
// };