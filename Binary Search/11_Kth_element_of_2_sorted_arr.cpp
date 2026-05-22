#include<bits/stdc++.h>	//#include<iostream>
using namespace std;

class Solution {
public:
    int kthElement(vector<int> &a, vector<int>& b, int k) {
        int n1 = a.size();
        int n2 = b.size();
        int size = (n1 + n2);
        if(n2 < n1) return kthElement(b, a, k);   // similar to LC_4.cpp

        int left_point = k;     // *U* diff. from LC_4.cpp (mid_point) bcs here we have to find the k-th element, not the median
        int low = max(0, k-n2);  // diff. from LC_4.cpp
        int high = min(k, n1);   // diff. from LC_4.cpp
        while(low <= high){
            int mid1 = low + (high-low)/2;
            int mid2 = left_point - mid1;

            int l1 = INT_MIN, l2 = INT_MIN;
            int r1 = INT_MAX, r2 = INT_MAX;
            if(mid1 < n1) r1 = a[mid1]; 
            if(mid2 < n2) r2 = b[mid2];
            if(mid1 - 1 >= 0) l1 = a[mid1 - 1];
            if(mid2 - 1 >= 0) l2 = b[mid2 - 1];

            if(l1 <= r2 && l2 <= r1) return max(l1, l2);

            else if(l1 > r2) high = mid1 - 1;
            else if(l2 > r1) low = mid1 + 1;    // 'else' part
        }
    }
};

int main(){
    Solution obj;
    vector<int> a = {2, 3, 6, 7, 9};
    vector<int> b = {1, 4, 8, 10};
    int k = 5;

    int result = obj.kthElement(a, b, k);
    cout << result << endl;    
    return 0;
}


// BRUTE (derived from merge sort) 
// and 
// BETTER (two-pointer) 
// are almost similar to the BinarySearch/LC_4.cpp