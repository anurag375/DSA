#include<bits/stdc++.h>	//#include<iostream>
using namespace std;

class MinStack {    // 155. Min Stack   ==> ⭐ given, Methods pop, top and getMin are valid ==> so, NO extra checks there..
public:
// optimal (little complex => uses formula): t = 1       s = n

    stack<long long> st;
    long long mini = LLONG_MAX;
    MinStack() {
        
    }
    
    void push(int value) {
        if(st.empty()){     // *U* handle the 1st push [otherwise this will execute: 2*value - INT_MAX]
            st.push(value);
            mini = value;
        }else if(value < mini){
            long long key = 2LL * value - mini;   // *U* 2LL  // *U* value = "newMini" ; mini = "oldMini"
            st.push(key);
            mini = value;   // new mini
        }else{
            st.push(value);
        }
    }
    
    void pop() {
        if(st.top() < mini){    // **U** mini would change
            long long oldMini = 2*mini - st.top();    // *U* mini = "newMini" ; st.top() = "key"
            mini = oldMini;     // update with old mini
        }

        st.pop();
    }
    
    int top() {
        if(st.top() < mini){    // *U* in this case, "mini" stores the top-element ; whereas st.top() stores the "key"
            return (int)mini;
        }
        return (int)st.top();
    }
    
    int getMin() {
        return (int)mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

int main(){
    MinStack st;

    st.push(5);
    st.push(2);
    st.push(7);
    st.push(1);

    cout << "Top: " << st.top() << endl;
    cout << "Min: " << st.getMin() << endl;

    st.pop();

    cout << "Top after pop: " << st.top() << endl;
    cout << "Min after pop: " << st.getMin() << endl;
       
    return 0;
}



// (mostly) optimal (easy): t = 1 [for all operations]       s = 2n

    // stack<pair<int,int>> st;
    // // int mini = INT_MAX;      // my-way
    // MinStack() {
        
    // }
    
    // void push(int value) {
    //     // mini = min(mini, value);     // my-way

    //     // if(st.empty()) st.push({value, value});     // striver-way
    //     // else st.push({value, min(value, st.top().second)});

    //     int mini = st.empty() ? value : min(value, st.top().second);    // *U* gpt-way

    //     st.push({value, mini});
    // }
    
    // void pop() {
    //     st.pop();
    // }
    
    // int top() {
    //     return st.top().first;
    // }
    
    // int getMin() {
    //     return st.top().second;
    // }