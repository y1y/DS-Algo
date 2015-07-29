int minSubArrayLen(int s, vector<int> & nums){
    int sum = 0;
    int begin = 0;
    int length = INT_MAX;
    for(int i = 0; i < nums.size(); ++i){
        sum += nums[i];
        while(sum >= s){
            length = min(length, i - begin + 1);
            sum -= nums[begin++];
        }
    }
    return length == INT_MAX? 0: length;
}
