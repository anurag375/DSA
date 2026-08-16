#include<bits/stdc++.h>
using namespace std;

class Solution {    // 4020. Elevator Requests I
public:
    int elevatorRequests(int n, vector<int>& requests) {
    // my-way: contest: t = m     s = 1
        int prevFloor = 0;   // initial position
        int time = 0;
        
        int m = requests.size();
        for(int i=0; i<m; i++){
            time += abs(requests[i] - prevFloor);
            prevFloor = requests[i];
        }
        return time;
    }
};

int main(){
    Solution sol;
    int n = 5;
    vector<int> requests = {2,1,4,3};   // output: 7

    cout << sol.elevatorRequests(n, requests) << endl;
    return 0;
}