#include<bits/stdc++.h>
using namespace std;

class MyStack {     // 225. Implement Stack using Queues    
// ⭐⭐ given: All the calls to pop and top are valid.    ==>     So, NO additional checks there

public:
// (striver-way ONLY): t = O(n) for push   &   O(1) for others       s = O(n)
    queue<int> q;  // ✅ class member (shared by all member functions)
        
    MyStack() {

    }
    
    void push(int x) {
        q.push(x);
        for(int i=1; i<q.size(); i++){ // *U* After pushing x, rotate all previous elements behind x
            int temp = q.front();
            q.pop();
            q.push(temp);
        }
    }
    
    int pop() {
        int temp = q.front();
        q.pop();    // *U* pop() doesn't return
        return temp;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

int main(){
    MyStack st;

    st.push(10);
    st.push(20);
    st.push(30);

    cout << "Top: " << st.top() << endl;

    cout << "Pop: " << st.pop() << endl;
    cout << "Top: " << st.top() << endl;

    cout << "Pop: " << st.pop() << endl;
    cout << "Pop: " << st.pop() << endl;

    cout << "Is empty? " << st.empty() << endl;
    
    return 0;
}