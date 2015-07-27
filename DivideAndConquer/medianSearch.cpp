#include <algorithm>
#include <iostream>
#include <vector>
#include <climits>

using namespace std;


class MedianSearch{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int>& nums2);
};

double MedianSearch::findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2){
    int n1 = nums1.size();
    int n2 = nums2.size();
    if(n2 < n1){
        swap(nums1, nums2);
        swap(n1, n2);
    }
    int k = (n1 + n2) / 2 + 1;
    int left = max(0, k - n2);
    int right = min(n1, k);
    int ret1 = 0;

    while(left < right){
        int mid = left + (right - left) / 2;
        int L2 = mid < n1? nums1[mid] : INT_MAX;
        int L1 = mid > 0? nums1[mid - 1]: INT_MIN;
        int R2 = (k - mid < n2)? nums2[k - mid]: INT_MAX;
        int R1 = (k - mid > 0)? nums2[k - mid - 1]: INT_MIN;
    
        if(L2 >= R1 && R2 >= L1){
            left = mid;
            break;
        } else if(L2 < R1) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    int L1 = left<=0? INT_MIN: nums1[left - 1];
    int R1 = k - left - 1 < 0? INT_MIN: nums2[k - left - 1];
    ret1 = max(L1, R1);
    if((n1 + n2) % 2){
        return ret1;
    } 
    int L2 = (left - 2 ) < 0? INT_MIN: nums1[left - 2];
    int R2 = (k - left - 2) < 0? INT_MIN: nums2[k - left - 2];
    int ret2 = max(max(min(L1, R1), L2), R2);
    return (ret1 + ret2) / 2.0;
}

int main(){
    vector<int> nums1 {1};
    vector<int> nums2 {2, 3, 4};
    cout << MedianSearch().findMedianSortedArrays(nums1, nums2) << endl;


}
