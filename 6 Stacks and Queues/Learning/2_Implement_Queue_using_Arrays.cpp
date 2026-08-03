#include<bits/stdc++.h>
using namespace std;

class QueueUsingArr{    // Implement Queue using Arrays

public:
    int start = -1, end = -1;
    int sizeCnt = 0;
    int q[10];  // predefined size
    void push(int data){
        if(sizeCnt == 10){
            cout << "Q is full.." << endl;
        }else{
            if(sizeCnt == 0){  // *U*
                start = 0;
                end = 0;
            }else{
                end = (end+1) % 10;
            }

            q[end] = data;
            sizeCnt++;
        }
    }

    void pop(){
        if(sizeCnt == 0){
            cout << "Queue is empty.." << endl;
        }
        else{
            start = (start + 1) % 10;
            sizeCnt--;

            if(sizeCnt == 0){   // *U*
                start = -1;
                end = -1;
            }
        }
    }

    int front(){
        if(sizeCnt == 0){ 
            cout << "Queue is empty.." << endl;
            return -1;  // assuming the queue doesn't store -ve elements
        }
        return q[start];
    }

    int size(){
        return sizeCnt;
    }
};


int main(){
    QueueUsingArr q;

    cout << "Initial size: " << q.size() << endl;

    q.push(10);
    q.push(20);
    q.push(30);

    cout << "Front element: " << q.front() << endl;
    cout << "Queue size: " << q.size() << endl;

    q.pop();

    cout << "After pop:" << endl;
    cout << "Front element: " << q.front() << endl;
    cout << "Queue size: " << q.size() << endl;

    q.push(40);

    cout << "Front element: " << q.front() << endl;
    cout << "Queue size: " << q.size() << endl;

    q.pop();
    q.pop();
    q.pop();

    cout << "Queue size: " << q.size() << endl;

    // Queue is empty
    q.front();
    q.pop();

    return 0;
}

// ⭐⭐ 
// T.C = O(1)   [for push, pop, front, and size]
// S.C = O(n)   [n = size of array]
// disadv: fixed size 