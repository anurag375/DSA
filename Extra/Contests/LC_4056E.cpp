#include<bits/stdc++.h>	//#include<iostream>
using namespace std;

class Solution {    // 4056. Number of Intersecting Interval Pairs I
public:
    int countIntersectingIntervals(vector<vector<int>>& intervals) {
    // brute: (contest)
        int n = intervals.size();
        int cnt = 0;

        sort(intervals.begin(), intervals.end());

        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                if(intervals[j][0] <= intervals[i][1])
                    cnt++;
            }
        }

        return cnt;
    }
};

int main(){
    Solution sol;
    vector<vector<int>> intervals = {{1,2},{2,3},{3,4}};    // output: 2
    cout << sol.countIntersectingIntervals(intervals) << endl;
    return 0;
}