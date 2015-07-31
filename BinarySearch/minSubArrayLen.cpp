class MinSubArrayLen{
private:
    int lower_bound(int target, vector<int> & nums);
public:
    int minSubArrayLen(int s, vector<int> & nums);
    int minSubArrayLenBsearch(int low, int target, vector<int> & nums);
};

int MinSubArrayLen::minSubArrayLen(int s, vector<int> & nums){
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

// [0, 1, 2, 3]
// [0, 1, 3, 4]

int MinSubArrayLen::lower_bound(int low, int target, vector<int> & nums){
    int low = 0;
    int high = nums.size() - 1;
    while(low < high){
        int mid = low + (high - low) / 2;
        if(nums[mid] < target){
            low = mid + 1;
        } else {
            high = mid; 
        }
    }

    if(nums[low] < target){
        return nums.size();
    }
    return low;
}

int MinSubArrayLen::minSubArrayLenBsearch(int s, vector<int> & nums){
    if(nums.empty()){
        return 0;
    }
    vector<int> accum(nums.size());
    accum[0] = nums[0];
    for(int i = 1; i < nums.size(); ++i){
        accum[i] = nums[i] + accum[i-1];
    }
    int minLen = INT_MAX;
    // search nums[i] + s >= lowerbound
    for(int i = 0; i < nums.size(); ++i){
        int j = lower_bound(i, accum[i] - nums[i] + s, accum);
        if(j == nums.size()){
            break;       
        }
        minLen = min(minLen, j - i + 1);
    }
    return minLen == INT_MAX? 0: minLen;
}


