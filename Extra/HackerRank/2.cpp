int hourglassSum(vector<vector<int>> arr) {
    int maxHrSum = INT_MIN; // ***U*** don't take 0.
    
    for(int i=1; i<arr.size()-1; i++){
        for(int j=1; j<arr[0].size()-1; j++){
            int hrSum = 0;  // *U* reset every time..
            hrSum += (arr[i-1][j-1] + arr[i-1][j] + arr[i-1][j+1]  +  arr[i][j]  +  arr[i+1][j-1] + arr[i+1][j] + arr[i+1][j+1]);
            
            maxHrSum = max(maxHrSum, hrSum);
        }
    }
    
    return maxHrSum;
}