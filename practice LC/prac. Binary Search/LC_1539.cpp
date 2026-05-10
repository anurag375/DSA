#include<bits/stdc++.h>	//#include<iostream>
using namespace std;


class Solution {    // 1539. Kth Missing Positive Number
// BRUTE: my-way (hard-coded ; not good) t = 1000 * n
public:
    bool found(vector<int>& arr, int i){
        for(int ele:arr){
            if(ele == i) return true;
        }
        return false;
    }

    int findKthPositive(vector<int>& arr, int k) {
        int cnt_k = 0;

        for(int i=1; i<=1000+1000; i++){
            if(!found(arr, i)) cnt_k++;
            if(cnt_k == k) return i;
        }

        return -1;
    }
};


int main(){
    Solution obj;
    vector<int> arr = {1,2,3,4};
    int k = 2;

    int result = obj.findKthPositive(arr, k);
    cout << result << endl;
    
    return 0;
}

