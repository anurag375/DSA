#include<bits/stdc++.h>	//#include<iostream>
using namespace std;

class StockSpanner {    // 901. Online Stock Span
public:
// my-way: t = n    s = n
    stack<pair<int,int>> st;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int ans = 1;    // *U* consider its day first...
        while(!st.empty() && st.top().first <= price){
            ans += st.top().second;
            st.pop();
        }

        st.push({price, ans});
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 * 
 Input
["StockSpanner", "next", "next", "next", "next", "next", "next", "next"]
[[], [100], [80], [60], [70], [60], [75], [85]]
Output
[null, 1, 1, 1, 2, 1, 4, 6]

 */

int main(){
    StockSpanner* obj = new StockSpanner();
    // int result = obj->next(100);
    cout << obj->next(100) << endl;
    cout << obj->next(80) << endl;
    cout << obj->next(60) << endl;
    cout << obj->next(70) << endl;
    cout << obj->next(60) << endl;
    cout << obj->next(75) << endl;
    cout << obj->next(85) << endl;

    return 0;
}