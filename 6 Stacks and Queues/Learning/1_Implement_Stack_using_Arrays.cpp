#include<bits/stdc++.h>
using namespace std;

class StackUsingArr{    // Implement Stack using Arrays
    
public:
    int topIndex = -1;   // acts as an index..
    int st[10];  // predefined size => here top = 0 to 9
    void push(int data){
        if(topIndex == 9){
            cout << "Stack is full.." << endl;
        }else{
            topIndex++;
            st[topIndex] = data;
        }
    }

    void pop(){
        if(topIndex == -1) 
            cout << "Stack is empty.." << endl;
        else 
            topIndex--;
    }

    int top(){  // return type may change..  
        if(topIndex == -1){ 
            cout << "Stack is empty.." << endl;
            return -1;  // assuming the stack doesn't store -ve elements
        }
        else 
            return st[topIndex];
    }

    int size(){     // return type usually int, long long..
        return (topIndex + 1);
    }
};

int main(){    
    StackUsingArr s;

    cout << "Initial size: " << s.size() << endl;

    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Top element: " << s.top() << endl;
    cout << "Stack size: " << s.size() << endl;

    s.pop();

    cout << "After pop:" << endl;
    cout << "Top element: " << s.top() << endl;
    cout << "Stack size: " << s.size() << endl;

    s.pop();
    s.pop();

    // Stack is now empty
    cout << "Size: " << s.size() << endl;
    cout << "Top element: " << s.top() << endl; // gives -1 => assume thats an error

    // Try popping an empty stack
    s.pop();

    return 0;

}

// ⭐⭐ 
// T.C = O(1)
// S.C = O(size of the array)
// disadv: fixed size 

// =====
// Dynamic array => size is defined during runtime
// int n = 10;
// int* a;
// a = new int[n];