#include<bits/stdc++.h>	//#include<iostream>
using namespace std;

class MinStack {    // 155. Min Stack
public:
// optimal (mostly): t = 1 [for all operations]       s = 2n

    stack<pair<int,int>> st;
    // int mini = INT_MAX;      // my-way
    MinStack() {
        
    }
    
    void push(int value) {
        // mini = min(mini, value);     // my-way

        // if(st.empty()) st.push({value, value});     // striver-way
        // else st.push({value, min(value, st.top().second)});

        int mini = st.empty() ? value : min(value, st.top().second);    // *U* gpt-way

        st.push({value, mini});
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
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