#include<bits/stdc++.h>	//#include<iostream>
using namespace std;


class Solution {    // 1482. Minimum Number of Days to Make m Bouquets

    // optimal: t = log(maxDay - minDay +1) * n   ==> pattern: FFFFTTTTTTT : BINARY SEARCH
    bool check(vector<int>& bloomDay, int m, int k, int day){ // 'day' = i = mid
        int cnt_consecutive = 0;
        int cnt_boquette = 0;
        
        int j = 0;
        while (j < bloomDay.size()){
            if(bloomDay[j] <= day) cnt_consecutive ++;
            else cnt_consecutive = 0;

            if(cnt_consecutive == k){
                cnt_boquette ++;
                cnt_consecutive = 0;
            }
            j++;
        }
        
        return (cnt_boquette >= m);
    }

public:
    int minDays(vector<int>& bloomDay, int m, int k) {  
        int low = *min_element(bloomDay.begin(), bloomDay.end());   // or low = 1   =>  both are possible..
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        int ans = -1;

        if(bloomDay.size() < m*k) return -1;    // *U* insufficient flowers..

        while(low <= high){
            int mid = low + (high-low)/2;

            if(check(bloomDay, m, k, mid)){
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
    vector<int> bloomDay = {1,10,3,10,2};
    int m = 3, k = 1;

    cout << obj.minDays(bloomDay, m, k) << endl;
    
    return 0;
}


// BRUTE: ONLY this func. is different: t = (maxDay - minDay +1) * n   ==> **U**
// public:
//     int minDays(vector<int>& bloomDay, int m, int k) {  // 1482. Minimum Number of Days to Make m Bouquets
//         int low = 1;
//         int high = *max_element(bloomDay.begin(), bloomDay.end());

//         if(bloomDay.size() < m*k) return -1;    // *U* insufficient flowers..

//         for(int i=low; i<=high; i++){
//             if(check(bloomDay, m, k, i)) return i;   // found the Minimum day
//         }

//         return -1;
//     }