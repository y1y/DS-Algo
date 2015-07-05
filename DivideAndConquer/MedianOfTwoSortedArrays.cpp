#include <vector>
#include <cassert>
#include <iostream>

using namespace std;

/*
 * 1. Find median of each array, compared
 * 2. Compared and dropped the smallest left part
 *  -- Time Complexity: O(logn + logm)
 *  -- Space Complexity: O(1)
 *
 */

class MediansOfTwoSortedArrays{
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2);  
private:
    int findKthLargestElement(vector<int> &nums1, vector<int> & nums2, int start1, int end1, int start2, int end2, int k);
};

double MediansOfTwoSortedArrays::findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2){
    
    int totalNum = nums1.size() + nums2.size();
    int firstEle = findKthLargestElement(nums1, nums2, 0, nums1.size(), 0, nums2.size(), (totalNum + 1)/ 2);
    
    if(totalNum % 2){
       return (double)firstEle; 
    }
    int secondEle = findKthLargestElement(nums1, nums2, 0, nums1.size(), 0, nums2.size(), totalNum / 2 + 1);
    
    return (firstEle + secondEle) / 2.0;
}

int MediansOfTwoSortedArrays::findKthLargestElement(vector<int> &nums1, vector<int> & nums2, int start1, int end1, int start2, int end2, int k){
   
   if(k == 1){
       return min(nums1[start1], nums2[start2]);
   } 
   if(start1 >= end1){
       return nums1[start2 + k - 1]; 
   }
   if(start2 >= end2){
       return nums2[start1 + k - 1];    
   }


   int mid1 = start1 + (end1 - start1) / 2 ;
   int mid2 = start2 + (end2 - start2) / 2 ;


   if(nums1[mid1] < nums2[mid2]){
       // mid1, mid2 may equal to start1 and start2
       if((mid1 - start1 + mid2 - start2 + 1) >= k){
            // drop right part
            return findKthLargestElement(nums1, nums2, start1, end1, start2, mid2 - 1, k);
       } else {
            // drop left part    
            return findKthLargestElement(nums1, nums2, mid1 - 1, end1, start2, end2, k - (mid1 - start1 + 1));
       }
   } else {
       // 1 + 2 - 2
       if((mid1 - start1 + mid2 - start2 + 1) >= k){
            // drop right part
            return findKthLargestElement(nums1, nums2, start1, mid1 - 1, start2, end2, k);
       } else {
            // drop left part    
            return findKthLargestElement(nums1, nums2, start1, end1, mid2 - 1, end2, k - (mid2 - start2 + 1));
       }
 
   }

}

int main(){
    vector<int> nums1 {1, 2, 3};
    vector<int> nums2 {-4, -3, -2, 4, 5};
    cout << MediansOfTwoSortedArrays().findMedianSortedArrays(nums1, nums2) << endl;
    // check corner case: 
    // both have only 1 element
}
