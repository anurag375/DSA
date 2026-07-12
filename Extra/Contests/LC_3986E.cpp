#include<bits/stdc++.h>	//#include<iostream>
using namespace std;

class Solution {    // 3986. Number of Elapsed Seconds Between Two Times
public:
    int secondsBetweenTimes(string startTime, string endTime) { 
    // my-way + gpt: => Contest     t = 1       s = 1
        string sS = startTime.substr(6,2);
        string eS = endTime.substr(6,2);
        string sM = startTime.substr(3,2);
        string eM = endTime.substr(3,2);
        string sH = startTime.substr(0,2);
        string eH = endTime.substr(0,2);

        int sSec = stoi(sS);
        int eSec = stoi(eS);
        int sMin = stoi(sM);
        int eMin = stoi(eM);
        int sHr = stoi(sH);
        int eHr = stoi(eH);

        int startInSec = (sHr * 3600) + (sMin * 60) + (sSec);
        int endInSec = (eHr * 3600) + (eMin * 60) + (eSec);

        return (endInSec - startInSec);     // ***U*** this method ONLY works because given => (endTime >= startTime)
    }
};

int main(){
    Solution s; 
    cout << s.secondsBetweenTimes("01:00:00", "01:00:25") << endl;   // 25
    cout << s.secondsBetweenTimes("12:34:56", "13:00:00") << endl;   // 1504
    return 0;
}


// exactly SAME  as above, but shorter version:

        // int sHr = stoi(startTime.substr(0,2));
        // int sMin = stoi(startTime.substr(3,2));
        // int sSec = stoi(startTime.substr(6,2));

        // int eHr = stoi(endTime.substr(0,2));
        // int eMin = stoi(endTime.substr(3,2));
        // int eSec = stoi(endTime.substr(6,2));

        // int startInSec = (sHr * 3600) + (sMin * 60) + (sSec);
        // int endInSec = (eHr * 3600) + (eMin * 60) + (eSec);

        // return (endInSec - startInSec);  