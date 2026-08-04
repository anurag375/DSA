#include<bits/stdc++.h>
using namespace std;

class MyQueue{    // 232. Implement Queue using Stacks
// ⭐⭐ given: All the calls to pop and top are valid.    ==>    So, NO additional checks there

public:
    stack<int> st1;
    stack<int> st2;
    MyQueue() {
        
    }

// Approach 2️⃣: [optimised for more push operations]:    
// t = O(1) for push, empty   &   O(n) for pop, peek    [**U** they don't always take O(n)]        s = O(n)
// ⭐ st2 = main holder → holds elements ready for pop()/peek().
// ⭐ st1 = holds newly pushed elements.
// ⭐ Elements can exist in BOTH stacks.

    void push(int x){ 
        st1.push(x);
    }

    int pop(){
        if(st2.empty()){
            while(!st1.empty()){
                st2.push(st1.top());
                st1.pop();
            }
        }
        int temp = st2.top();
        st2.pop();
        return temp;
    }

    int peek(){
        if(st2.empty()){
            while(!st1.empty()){
                st2.push(st1.top());
                st1.pop();
            }
        }
        return st2.top();
    }

    bool empty(){
        return st1.empty() && st2.empty();  // *U* ✅
    }
};


int main(){
    MyQueue q;

    q.push(10);
    q.push(20);
    q.push(30);

    cout << "Front: " << q.peek() << endl;

    cout << "Pop: " << q.pop() << endl;
    cout << "Front: " << q.peek() << endl;

    cout << "Pop: " << q.pop() << endl;
    cout << "Pop: " << q.pop() << endl;

    cout << "Is empty? " << q.empty() << endl;

    return 0;
}


// Approach 1️⃣: [good for operations other than push]:   
// t = O(2n) for push()   &   O(1) for others       s = O(n)
// ⭐ st1 is the main holder here.

    // void push(int x){ 
    //     // 1> Move everything from st1 → st2
    //     while(!st1.empty()){    // **U** 🧠 don't use for loop with size() [because size changes after each pop()]
    //         st2.push(st1.top());
    //         st1.pop();
    //     }
    //     // 2> Put new element at bottom
    //     st1.push(x);
    //     // 3> Move everything back st2 → st1
    //     while(!st2.empty()){
    //         st1.push(st2.top());
    //         st2.pop();
    //     }
    // }

    // int pop(){
    //     int temp = st1.top();
    //     st1.pop();
    //     return temp;
    // }

    // int peek(){
    //     return st1.top();
    // }

    // bool empty(){
    //     return st1.empty();
    // }