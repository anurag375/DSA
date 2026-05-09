#include<bits/stdc++.h>	//#include<iostream>
using namespace std;


class Solution {    // 1011. Capacity To Ship Packages Within D Days

    // OPTIMAL: t = log(sum of weights - maxWeight +1) * n
    bool check(vector<int>& weights, int days, int curr_capacity){
        int cnt_sum = 0;
        int cnt_days = 1;   // *U* starts from 1 (not 0)

        for(int j=0; j<weights.size(); j++){
            if(cnt_sum + weights[j] > curr_capacity){
                cnt_days ++;
                cnt_sum = 0;
            }

            cnt_sum += weights[j];
        }
        return (cnt_days <= days);   // *U* notice the condition.. 
    }


    int sumArrayElements(vector<int>& weights){
        int sum = 0;
        for(int ele:weights) sum += ele;

        return sum;
    }

public:
    int shipWithinDays(vector<int>& weights, int days) {
        
        int low = *max_element(weights.begin(), weights.end());
        int high = sumArrayElements(weights);
        int ans = -1;   // or any other value..

        while(low <= high){
            int mid = low + (high-low)/2;

            if(check(weights, days, mid)){
                ans = mid;
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }

        return ans;
    }
};


int main(){
    Solution obj;
    // vector<int> weights = {1,2,3,4,5,6,7,8,9,10};
    vector<int> weights = {3,2,2,4,1,4};
    int days = 3;

    cout << obj.shipWithinDays(weights, days) << endl;
    
    return 0;
}



// BRUTE: ONLY this func. is different: t = (sum of weights - maxWeight +1) * n
// public:
//     int shipWithinDays(vector<int>& weights, int days) {
        
//         int low = *max_element(weights.begin(), weights.end());
//         int high = sumArrayElements(weights);

//         for(int i=low; i<=high; i++){
//             if(check(weights, days, i)) return i;   // found the Minimum ship-capacity
//         }

//         return -1;
//     }
