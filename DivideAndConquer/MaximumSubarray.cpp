#include <vector>
#include <cassert>
#include <iostream>
#include <climits>

using namespace std;


/* 1.Divide the array into left and right
 * 2.Find the maximum subarray in the left, find the maximum subarray in the right, find the crossing array
 * 3.Return the max array among the three mentioned above
 * -- Time Complexity: O(nlogn)
 * -- Space Complexity: O(1)
 *
 */

class MaximumSubarray{
public:
    int maxSubArray(vector<int>& nums);  
private:
    int maxSubArrayHelper(int start, int end, vector<int>& nums);
    int findCrossingMax(int start, int end, int mid, vector<int>& nums);
};

int MaximumSubarray::maxSubArray(vector<int>& nums){
    return maxSubArrayHelper(0, nums.size(), nums);    
} 

int MaximumSubarray::maxSubArrayHelper(int start, int end, vector<int>& nums){
    int result = INT_MIN;
    if(start == end - 1){
        result = nums[start];
    } else if (start < end){
        int mid = start + (end - start) / 2;
        int leftMax = maxSubArrayHelper(start, mid, nums);
        int rightMax = maxSubArrayHelper(mid, end, nums);
        int crossMax = findCrossingMax(start, end, mid, nums);
        result = max(max(leftMax, rightMax), crossMax); 
    }
    return result;
}

int MaximumSubarray::findCrossingMax(int start, int end, int mid, vector<int>& nums){
   int result = INT_MIN;
   if(end < start){ // cover more cases!
   //if(end - start >= 3){
      int i = mid - 1;
      int j = mid;
      int maxLeft = nums[i--];
      int maxRight = nums[j++];
      int curLeft = maxLeft;
      int curRight = maxRight;

      while(i >= start){
         curLeft += nums[i--];
         maxLeft = max(maxLeft, curLeft); 
      }

      while(j < end){
        curRight += nums[j++];
        maxRight = max(maxRight, curRight);
      }
      result = maxLeft + maxRight;
   }

   return result;
}

int main(){
    MaximumSubarray maxSubarraySolver;
    vector<int> nums1 {-1, 1};
    vector<int> nums2 {1, 2, 3};
    vector<int> nums3 {10, -4, 5, -2, -3};
    vector<int> nums4 {1, 2};
    assert(maxSubarraySolver.maxSubArray(nums1) == 1);
    assert(maxSubarraySolver.maxSubArray(nums2) == 6);
    assert(maxSubarraySolver.maxSubArray(nums3) == 11);
    assert(maxSubarraySolver.maxSubArray(nums4) == 4);
}
