#include<bits/stdc++.h>	//#include<iostream>
using namespace std;


class Solution {
public:
  int NthRoot(int N, int M) {
    // my-way OPTIMAL: t = log(M)   ==> (modified Lower Bound)  ==> NOT proper code
        int low = 1, high = M;

        while(low <= high){
            int mid = low + (high-low)/2;

            long long val = pow(mid, N);
            if(val == M) return mid;
            else if(val > M){
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }

        return -1;
    }
};


int main(){
    Solution obj;
    int N = 3, M = 27;
    cout << obj.NthRoot(N, M) << endl;
    return 0;
}