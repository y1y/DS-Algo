#include <vector>
#include <cassert>
#include <iostream>
#include <climits>
#include <algorithm>
#include <queue>
using namespace std;

class KthLargestEle{
public:

    int findKthLargest(vector<int>& nums, int k);
};

int KthLargestEle::findKthLargest(vector<int>& nums, int k){
    priority_queue<int, vector<int>, greater<int>> pq;
    for(auto & num: nums){

        pq.push(num);

        if(pq.size() > k){

            pq.pop();

        }

    }

    return pq.top();
}    



int main(){
    vector<int> nums1 {1, 3, 2};
    cout << KthLargestEle().findKthLargest(nums1, 2) << endl;
}
