#include<bits/stdc++.h>
using namespace std;

class Solution {    // 3941. Password Strength
public:
    // my-way ONLY: 
    int passwordStrength(string password) {
        int n = password.size();
        int pt = 0;
            set<int> s; // tracks existing password character by there ascii
        
        for(int i=0; i<n; i++){
            int ascii = (int)password[i];
            if(s.find(ascii) == s.end()){
                s.insert((int)password[i]);
            
                if(ascii >= 48 && ascii <= 57) // 0 to 9
                    pt += 3;
                else if(ascii >= 65 && ascii <= 90) // A to Z
                    pt += 2;
                else if(ascii >= 97 && ascii <= 122) // a to z
                    pt += 1;
                    
                else // !@#$
                    pt += 5;
            
            }
        }

        return pt;
    }
};

int main(){
    Solution obj;
    string password = "Aa1!Aa1!";
    
    int result = obj.passwordStrength(password);
    cout << result << endl;
    return 0;
}