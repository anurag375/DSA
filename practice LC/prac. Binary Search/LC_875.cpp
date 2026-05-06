#include<bits/stdc++.h>	//#include<iostream>
using namespace std;

class Solution {    // 875. Koko Eating Bananas         
    
// optimal: t = log base 2 (max. element)  *  n
    bool possibleEatingAll(vector<int>& piles, int h, int current_speed){
        long long current_h = 0;    // ***U*** DON'T use "int" ==> it can overflow for very large inputs.

        for(int pile:piles){
        // we are finding ceil division:
            // if(pile <= current_speed) current_h ++;                                  // ==>> my-version
            // else{   // (pile > current_speed)
            //     current_h += (pile / current_speed);    // completely divisible
            //     if(pile % current_speed != 0) current_h ++;     // Not completely divisible
            // }
        // or..
            current_h += (pile + current_speed - 1) / current_speed;                    // ==>> GPT-version
        }

        return (current_h <= h);
    }


public:
    int minEatingSpeed(vector<int>& piles, int h) {     
        // int low = *min_element(piles.begin(), piles.end());
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        int ans = INT_MAX;

        while(low <= high){     // *U* consider all no.s btw 'low' and 'high' as the banana-eating-speed (per hour)
            int mid = low + (high-low)/2;

            if(possibleEatingAll(piles, h, mid)){
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
    vector<int> piles = {805306368,805306368,805306368};
    int h = 1000000000;

    Solution obj;
    int ans = obj.minEatingSpeed(piles, h);
    cout << ans << endl;
    
    return 0;
}