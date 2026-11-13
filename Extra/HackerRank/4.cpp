vector<int> matchingStrings(vector<string> stringList, vector<string> queries) {
    map<string,int> mp; // {string, count}
    vector<int> ans;
    
    for(string s:stringList) mp[s]++;   // count frequency
    for(string s:queries) ans.push_back(mp[s]); // find frequency
    
    return ans;
}


