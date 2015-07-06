#include <vector>
#include <cassert>
#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

class FindPeakEle {
public:
    int findPeakElement(vector<int>& nums);
};

int FindPeakEle::findPeakElement(vector<int>& nums){
    int left = 0;
    int right = nums.size() - 1;
    int mid = -1;

    while(left <= right){
        int mid = left + (right - left) / 2;
        if((mid == 0 || nums[mid] > nums[mid - 1]) && (mid == nums.size() - 1 || nums[mid] > nums[mid + 1])){
            return mid;
        }
        if(mid == nums.size() - 1 || nums[mid] < nums[mid + 1]){
            left = mid + 1;
        } else {
            right = mid - 1;    
        }
    }    
    return mid;
}


int main(){
    vector<int> nums1 {1, 2, 3};
    cout << FindPeakEle().findPeakElement(nums1) << endl;
}
