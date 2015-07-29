class SearchInsert{
public:
    int searchInsert(vector<int> & nums, int target);

};
// [1, 3]
// 2
int SearchInsert::searchInsert(vector<int> & nums, int target){
    // 0
    int low = 0;
    // 1
    int high = nums.size() - 1;
    while(low < high){
        // mid = 0    
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
