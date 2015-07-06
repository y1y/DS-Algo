#include <vector>
#include <cassert>
#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

class LargestRec {
public:
    int largestRectangleArea(vector<int>& height) {
        return largestRectangleAreaHelper(0, height.size() - 1, height);        
    }  
private:
    int largestRectangleAreaHelper(int left, int right, vector<int>& height);
    int findCrossArea(int left, int right, int mid,  vector<int>& height);
};

int LargestRec::largestRectangleAreaHelper(int left, int right, vector<int>& height){    
    if(left > right){
        return 0;
    }
    if(left == right){
        return height[left];    
    }
    int mid = left + (right - left) / 2;
    int leftArea = largestRectangleAreaHelper(left, mid, height);
    int rightArea = largestRectangleAreaHelper(mid + 1, right, height);
    int crossArea = findCrossArea(left, right, mid, height);
    return max(max(leftArea, rightArea), crossArea);
}

int LargestRec::findCrossArea(int left, int right, int mid, vector<int>& height){
    // greedy algorithm
    int i = mid;
    int j = mid + 1;
    int h = min(height[i--], height[j++]);
    int maxArea = h * 2;
    while(i >= left || j <= right){
        if(i < left){
            h = min(h, height[j]);
            maxArea = max(maxArea, h * (j - i));
            ++j;
        } else if (j > right) {
            h = min(h, height[i]);
            cout << "h:" << h << endl;
            maxArea = max(maxArea, h * (j - i));
            --i;    
        } else {
            if(height[i] > height[j]){
                 h = min(h, height[i]);
                 maxArea = max(maxArea, h * (j - i));
                 --i;     
            } else {
                 h = min(h, height[j]);
                 maxArea = max(maxArea, h * (j - i));
                 ++j;
            }    
        }
    }
    return maxArea;
}

int main(){
    vector<int> nums1 {2, 1, 2};
    cout << LargestRec().largestRectangleArea(nums1) << endl;
}
