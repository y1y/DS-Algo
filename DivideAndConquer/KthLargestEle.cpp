#include <vector>
#include <cassert>
#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

class KthLargestEle{
public:

    int findKthLargest(vector<int>& nums, int k);
private:
    // return idx is a better option
    int partition(int start, int end, vector<int>&nums); 
};

int KthLargestEle::findKthLargest(vector<int>& nums, int k){
    int start = 0;
    int end = nums.size();
    int numIdx = partition(start, end, nums);
    // keep track of start and end;
    while(numIdx != k){
        if(numIdx < k){
            start = numIdx + 1;
        } else {
            // off by one
            end = numIdx - 1;
        }
        numIdx = partition(start, end, nums);
    } 
    return nums[numIdx - 1];
    
}

int KthLargestEle::partition(int start, int end, vector<int> & nums){
    if(end - start == 1){
        return start;    
    }
    int mid = start + (end - start) / 2;

    swap(nums[mid], nums[end-1]);

    int pivot = nums[end - 1];
    int i = start; 
    int j = start;
    while(j < end - 1){
        if(nums[j] >= pivot){
            swap(nums[i], nums[j]);
            ++i;    
        }
        ++j;
    }
    swap(nums[i++], nums[end-1]);

    return i;
}

int main(){
    vector<int> nums1 {1, 3, 2};
    cout << KthLargestEle().findKthLargest(nums1, 2) << endl;
}
