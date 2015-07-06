#include <vector>
#include <cassert>
#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

class CountInversions {
public:
    int countInversions(vector<int>& nums);
private:
    int countInversionsHelper(int left, int right, vector<int>& nums);
    int countInvert(int left, int right, int mid, vector<int> & nums);
};

int CountInversions::countInversions(vector<int>& nums){
    return countInversionsHelper(0, nums.size() - 1, nums);
}

int CountInversions::countInversionsHelper(int left, int right, vector<int>& nums){
    int inversion = 0;
    if(left < right){
        int mid = left + (right - left) / 2;
        int leftCount = countInversionsHelper(left, mid, nums);
        int rightCount = countInversionsHelper(mid + 1, right, nums);
        int inversionCount = countInvert(left, right, mid, nums);
        inversion = leftCount + rightCount + inversionCount;
    }    
    return inversion;
}

int CountInversions::countInvert(int left, int right, int mid, vector<int>& nums){
    vector<int> leftVec;
    vector<int> rightVec;
    int i = left;
    while(i <= mid){
        leftVec.push_back(nums[i++]);    
    }
    while(i <= right){
        rightVec.push_back(nums[i++]);    
    }
    i = left;
    int m = 0, n = 0;
    int result = 0;
    while(m < leftVec.size() && n < rightVec.size()){
        if(leftVec[m] <= rightVec[n]){
            nums[i++] = leftVec[m++];
        } else {
            result += leftVec.size() - m;
            nums[i++] = rightVec[n++];    
        }
    }
    
    while(m < leftVec.size()){
        nums[i++] = leftVec[m++];    
    }
    while(n < rightVec.size()){
        nums[i++] = rightVec[n++];    
    }
    return result;

}


int main(){
    vector<int> nums1 {1, 3, 2};
    cout << CountInversions().countInversions(nums1) << endl;
}
