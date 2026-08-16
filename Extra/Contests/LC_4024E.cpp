#include<bits/stdc++.h>
using namespace std;

class Solution{ // 4024. Nearest Available Drone
public:
    int nearestDrone(vector<vector<int>>& drones, vector<int>& target) {
    // my-way: contest:   t = n    s = 1
        int n = drones.size();
        unordered_map<string, int> mapAns = {{"index", -1}, {"minManDist", INT_MAX}};   // *U* "index" = -1

        for(int i=0; i<n; i++){
            int x = drones[i][0];
            int y = drones[i][1];
            int range = drones[i][2];
            int manhattanDist = abs(x - target[0]) + abs(y - target[1]);

            if(manhattanDist > range) continue;   // cannot be the answer
            
            if((manhattanDist < mapAns["minManDist"])){
                mapAns["index"] = i;
                mapAns["minManDist"] = manhattanDist;
            }
            // *U* don't update anything for '=='
        }
        return mapAns["index"];
    }
};

int main(){
    Solution sol;
    // vector<vector<int>> drones = {{0,0,8},{2,2,9}};
    // vector<int> target = {3,4};     // // output: 1

    vector<vector<int>> drones = {{2,1,5},{4,4,5},{6,6,8}};
    vector<int> target = {5,5};     // output: 1

    cout << sol.nearestDrone(drones, target) << endl;
    return 0;
}