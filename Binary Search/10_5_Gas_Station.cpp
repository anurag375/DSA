#include<bits/stdc++.h>	//#include<iostream>
using namespace std;


// ONLY available on GFG: https://www.geeksforgeeks.org/problems/minimize-max-distance-to-gas-station/1

// striver optimal:     t = n * log(high - low) + n
class Solution {

    int numberOfGasStationsRequired(vector<int> &stations, long double dist){   // ***U*** if no remainder left ->  {stationsInBetween - 1 }  ==>> if there is some remainder (in decimal form) -> {stationsInBetween}
        int cnt = 0;
        for(int i=0; i<stations.size() - 1; i++){
            int stationsInBetween = (stations[i+1] - stations[i]) / dist;

            if((stations[i+1] - stations[i]) / dist == stationsInBetween * dist){
                stationsInBetween--;
            }
            cnt += stationsInBetween;
        }
        return cnt;
    }

    long double maxOfElement(vector<int> &stations){
        long double maxi = 0.0;
        for(int i=0; i<stations.size() - 1; i++){
            maxi = max(maxi, (long double)(stations[i+1] - stations[i]));   // **U** fixing the data type mismatch error
        }
        return maxi;
    }

  public:
    double minMaxDist(vector<int> &stations, int K) {

        int n = stations.size();
        long double low = 0;
        long double high = maxOfElement(stations);
        long double ans;

        long double diff = 1e-6;
        while(high - low > diff){
            long double mid = low + (high-low)/2;

            int cnt = numberOfGasStationsRequired(stations, mid);

            if(cnt > K){    // *U* means more than required stations --> less distance --> so increase distance
                low = mid;
            }else{
                ans = high;
                high = mid;
            }
        }
        
        return high;
    }
};


int main(){
    Solution obj;
    vector<int> stations = {0, 10};
    int K = 2;

    double result = obj.minMaxDist(stations, K);
    cout << result << endl;
    
    return 0;
}



// =============================================================================
// better: priority queue: TLE: t = n log(n) + K log(n)  (because of priority queue)    s = (n - 1)


// class Solution {
//   public:
//     double minMaxDist(vector<int> &stations, int K) {

//         int n = stations.size();
//         priority_queue<pair<double, int>> pq;    // *U* <gap, index>
//         vector<int> inserted(n-1, 0);

//         for(int i=0; i<n-1; i++){
//             double gap = stations[i+1] - stations[i];
//             pq.push({gap, i});  // *U* gaps ke liye total n-1 indices honge
//         }

//         for(int i=1; i<=K; i++){
//             double max_gap = pq.top().first;
//             int max_idx = pq.top().second;

//             pq.pop();

//             double gap = stations[max_idx + 1] - stations[max_idx];
//             inserted[max_idx]++;
//             double new_gap = gap / (inserted[max_idx] + 1);

//             pq.push({new_gap, max_idx});
//         }
        
//         return pq.top().first;
//     }
// };



// =============================================================================
// striver brute:    TLE:   t = K*n + n     s = (n - 1)


// class Solution {
//   public:
//     double minMaxDist(vector<int> &stations, int K) {
//         // Code here
//         int n = stations.size();
//         vector<int> inserted(n-1, 0);
        
//         for(int i=1; i<=K; i++){    // should be <=
//             double max_gap = -1;
//             int max_idx = -1;

//             for(int j=0; j<n-1; j++){
//                 double diff = stations[j+1] - stations[j];
//                 double gap = diff / (inserted[j] + 1);

//                 if(gap > max_gap){
//                     max_gap = gap;
//                     max_idx = j;
//                 }
//             }
//             inserted[max_idx]++;
//         }
        
//         double max_ans = -1;
//         for(int i=0; i<n-1; i++){
//             double diff = stations[i+1] - stations[i];
//             double gap = diff / (inserted[i] + 1);

//             max_ans = max(max_ans, gap);
//         }
        
//         return max_ans;
//     }
// };


// =============================================================================
// =============================================================================
// my-way brute:    TLE:    t = n + K       s = 2 * (n - 1)


// class Solution {
//   public:
//     double minMaxDist(vector<int> &stations, int K) {
//         // Code here
//         int n = stations.size();

//         vector<double> gaps;
//         vector<int> placed;
        
//         for(int i=0; i<n-1; i++){
//             gaps.push_back( double(stations[i+1] - stations[i]) );
//             placed.push_back(0);
//         }
        
//         while(K >= 1){
//             int max_idx = max_element(gaps.begin(), gaps.end()) - gaps.begin();
//             placed[max_idx] = placed[max_idx] + 1;
//             gaps[max_idx] = double(stations[max_idx + 1] - stations[max_idx]) / (placed[max_idx] + 1);
//             K--;
//         }
        
//         double ans = *max_element(gaps.begin(), gaps.end());
//         return round(ans * 1e6) / 1e6;
        
//         // return ans;
//     }
// };