#include<bits/stdc++.h>	//#include<iostream>
using namespace std;

class Solution {    // 4. Median of Two Sorted Arrays
public:
    // optimal: binary search  t = log(min. of the array length)     s=1
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        if(n < m) return findMedianSortedArrays(nums2, nums1); // *U* to make sure that nums1 is the smaller array..
        int size = m + n;

        int mid_point = (size + 1)/2;     // *U* so that it correctly gives the mid index of odd-length array as well..
        
        int low = 0, high = m;  // traverse over the smaller range

        while(low <= high){
            // ***U*** mid1, mid2 index pointers hein, but yeh no. of elements represent krenge (left-side of partition ke)
            int mid1 = low + (high-low)/2;  
            int mid2 = mid_point - mid1;

            int l1 = INT_MIN, l2 = INT_MIN;
            int r1 = INT_MAX, r2 = INT_MAX;

            // **U**
            if(mid1 < m) r1 = nums1[mid1];
            if(mid2 < n) r2 = nums2[mid2];
            if(mid1-1 >= 0) l1 = nums1[mid1-1];
            if(mid2-1 >= 0) l2 = nums2[mid2-1];
            if(l1 <= r2 && l2 <= r1){
                if(size % 2 == 1){  // odd-length array
                    return double(max(l1, l2));
                }
                return double((max(l1, l2) + min(r1, r2))/2.0);
            }else if(l1 > r2){
                high = mid1 - 1;
            }else{ // l2 > r1
                low = mid1 + 1;
            }
        }
        
        return 0;   // placeholder (never reached)
    }
};





int main(){
    Solution obj;
    vector<int> nums1 = {1, 2};
    vector<int> nums2 = {3, 4};

    double result = obj.findMedianSortedArrays(nums1, nums2);
    cout << result << endl;
    return 0;
}



// MY-WAY: better: 2-pointer  t=(m+n)     s=1
    // double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    //     int m = nums1.size();
    //     int n = nums2.size();
    //     int size = m + n;
        
    //     int mid_idx = size / 2;
    //     int mid_idx_pre = mid_idx - 1;  // for backup -> even array case

    //     int mid = -1;   // sufficient for ODD lengthed array
    //     int mid_pre = -1;   // ONLY used for EVEN

    //     int i = 0;
    //     int j = 0;
    //     int counter = 0;    // idx-counter for merged array (without actually merging)
    //     while(i<m && j<n){

    //         if(nums1[i] < nums2[j]){
    //             if(counter == mid_idx_pre) mid_pre = nums1[i];
    //             if(counter == mid_idx) mid = nums1[i];
    //             i++;
    //         }
    //         else{
    //             if(counter == mid_idx_pre) mid_pre = nums2[j];
    //             if(counter == mid_idx) mid = nums2[j];
    //             j++;
    //         }  
    //         counter++;  // *U* place at this place only
    //     }

    //     while(i < m){
    //         if(counter == mid_idx_pre) mid_pre = nums1[i];
    //         if(counter == mid_idx) mid = nums1[i];
    //         counter++;
    //         i++;
    //     }

    //     while(j < n){
    //         if(counter == mid_idx_pre) mid_pre = nums2[j];
    //         if(counter == mid_idx) mid = nums2[j];
    //         counter++;
    //         j++;
    //     }

    //     if(size % 2 == 1){  // odd-length array
    //         return double(mid);
    //     }else{
    //         return double(mid + mid_pre)/2;
    //     }
    // }



// BRUTE: (same as in the merge sort): t = (m+n)  ;  s = (m + n)
    // double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    //     int m = nums1.size();
    //     int n = nums2.size();
    //     vector<int> nums3(m + n, 0);
    //     int idx = 0;

    //     // combining both arrays:
    //     int i = 0, j = 0;
    //     while(i < m && j < n){
    //         if(nums1[i] < nums2[j]){
    //             nums3[idx++] = nums1[i++];
    //         }else{
    //             nums3[idx++] = nums2[j++];
    //         }
    //     }
    //     while(i < m){
    //         nums3[idx++] = nums1[i++];
    //     }
    //     while(j < n){
    //         nums3[idx++] = nums2[j++];
    //     }

    //     // finding mid element (in double):
    //     int size = idx;
    //     int mid1 = size/2;    // ceil index

    //     if(size % 2 == 0){    // even length array..
    //         int mid2 = mid1 - 1;    // floor index

    //         return ((double)nums3[mid1] + (double)nums3[mid2]) / 2;
    //     }else{
    //         return (double) nums3[mid1];
    //     }

    //     return -1;
    // }