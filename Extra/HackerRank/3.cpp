vector<int> rotateLeft(int d, vector<int> arr) {
    reverse(arr.begin(), arr.begin()+d);
    reverse(arr.begin()+d, arr.end());
    reverse(arr.begin(), arr.end());
    
    return arr;
}
