#include <iostream>
#include <vector>
using namespace std;
class BSearchRotate{
public:
    int search(vector<int> & nums, int target);
    vector<int> searchRange(vector<int> & nums, int target);
private:
    int find_lower(vector<int> & nums, int target);
    int find_upper(vector<int> & nums, int target);

};


int BSearchRotate::search(vector<int> & nums, int target){
    int low = 0;
    int high = nums.size() - 1;

    while(low <= high){
        int mid = low + (high - low ) / 2;
        if(nums[mid] == target){
            return mid;
        }
        if(nums[low] <= nums[mid]){
            if(target >= nums[low] && target < nums[mid]){
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        } else {
            if(target > nums[mid] && target <= nums[high]){
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
    }
    return -1;
}

// first element >= target
// 5
// [2, 5]
// low = 1
// high = 1

int BSearchRotate::find_lower(vector<int> & nums, int target){
    int low  = 0;
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

int BSearchRotate::find_upper(vector<int> & nums, int target){
    int low = 0;
    int high = nums.size() - 1;
    while(low < high){
        int mid = low + (high - low) / 2;
        if(nums[mid] <= target){
            low = mid + 1;
        } else {
            high = mid;
        }
    }
    if(nums[low] <= target){
        return nums.size();
    }
    return low;

}
vector<int> BSearchRotate::searchRange(vector<int> & nums, int target){
    int lower_bound = find_lower(nums, target);
    int upper_bound = find_upper(nums, target);
    if(lower_bound == upper_bound){
        return vector<int>{-1, -1};
    }
    return vector<int> {lower_bound, upper_bound - 1};
}

int main(){
    vector<int> test{1};
    vector<int> result = BSearchRotate().searchRange(test, 0);
}
