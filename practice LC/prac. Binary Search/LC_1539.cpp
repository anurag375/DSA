#include<bits/stdc++.h>	//#include<iostream>
using namespace std;


class Solution {    // 1539. Kth Missing Positive Number
    
public:
    int findKthPositive(vector<int>& arr, int k) {
    // optimal:     t = log n
        int low = 0;
        int high = arr.size() - 1;

        while(low <= high){
            int mid = low + (high-low)/2;

            int missing_values = arr[mid]-(mid + 1);
            if(missing_values < k){     // not <= ==> **U** using example 1
                low = mid + 1;
            }else{  // means >=
                high = mid - 1;
            }
        }

        return high + 1 + k;    // *U*
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



    // brute: striver (GOOD logoc)    t = n  // **U** the logic
        // if(k < arr[0]) return k; // *U* no need for this here
        
        // for(int ele:arr){
        //     if(ele <= k) k++;
        //     else break;
        // }

        // return k;


// ============


// GPT explains: Exaple: arr = [2,3,4,7,11], k = 5

// till index 3 → only 3 numbers missing
// till index 4 → 6 numbers missing

// We need the 5th missing number.
// So answer lies between index 3 and 4.

// What Binary Search Finds
// Binary search searches for the first index where missing count ≥ k

// Here:
// index 3 → missing = 3 (<5)
// index 4 → missing = 6 (≥5)

// So required position is around index 4.


// ============



// BRUTE: my-way (hard-coded ; NOT good) t = 1000 * n
// public:
//     bool found(vector<int>& arr, int i){
//         for(int ele:arr){
//             if(ele == i) return true;
//         }
//         return false;
//     }

//     int findKthPositive(vector<int>& arr, int k) {
//         int cnt_k = 0;

//         for(int i=1; i<=1000+1000; i++){
//             if(!found(arr, i)) cnt_k++;
//             if(cnt_k == k) return i;
//         }

//         return -1;
//     }