#include<bits/stdc++.h>
using namespace std;

class StockSpanner {    // 901. Online Stock Span
public:
// optimal (my-way): [similar to Previous Greater Element]:     ===>>   Prefer this...
// t = (n + n) [for trversing + stack poping]    s = n
    stack<pair<int,int>> st;     // {price, days span}
    StockSpanner() {
        
    }
    
    int next(int price) {
        int ans = 1;    // *U* → today's day is always included...
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
    // Output:
    // [1, 1, 1, 2, 1, 4, 6]

    return 0;
}



// // optimal (striver): t, s [almost SAME logic as my-way optimal; just some code difference] 
// public:
//     stack<pair<int,int>> st;    // {price, index}
//     int idx;

//     StockSpanner() {
//         idx = -1;   // traces the index/order of the funs. calls (days)
//     }
    
//     int next(int price) {
//         idx++;
//         int ans = 1;    // *U* current day is always included...
//         while(!st.empty() && st.top().first <= price)
//             st.pop();

//         ans = idx - ((st.empty()) ? -1 : st.top().second);    // **U** calc. the index/days diff.

//         st.push({price, idx});
//         return ans;
//     }


// =====================


// // brute:    ==>    NOT imp.
// // t = (total no. of days)
//  // s = (total number of "next" func. calls)
// public:
//     vector<int> vec;
//     StockSpanner() {}
    
//     int next(int price) {
//         int ans = 1;    // *U* consider current day first...
//         for(int i=vec.size()-1; i>=0; i--){
//             if(vec[i] > price) break;
//             ans++;
//         }

//         vec.push_back(price);
//         return ans;
//     }