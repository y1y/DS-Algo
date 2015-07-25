#include <iterator>
#include <algorithm>
#include <iostream>
#include <stack>

using namespace std;

class TrappingRainWater{
public:
    int trap(const vector<int> & height);
    int trap2(const vector<int> & height);
    int trap3(const vector<int> & height);

};


int TrappingRainWater::trap(const vector<int> & height){
    if(height.size() <= 2){
        return 0;
    }
    int max_idx = distance(height.begin(), max_element(height.begin(), height.end()));
    int left = height[0];
    int sum = 0;
    for(int i = 1; i < max_idx; ++i){
        if(height[i] >= left){
            left = height[i];
        } else {
            sum += left - height[i];
        }
    }
    int right = height.back();
    
    for(int i = height.size() - 2; i > max_idx; --i){
        if(height[i] >= right){
            right = height[i];
        } else {
            sum += right - height[i];
        }
    }
    return sum;

}
int TrappingRainWater::trap2(const vector<int> & height){
    if(height.size() <= 2){
        return 0;
    }
    int leftMax = height[0];
    int rightMax = height.back();
    
    int left = 1;
    int right = height.size() - 2;
    int sum = 0;
    while(left <= right){
        if(height[left] < height[right]){
            leftMax = max(leftMax, height[left]);
            sum += leftMax - height[left];
            ++left;
        } else {
            rightMax = max(rightMax, height[right]);
            sum += rightMax - height[right];
            --right;
        }
    }
    return sum;
}


int TrappingRainWater::trap3(const vector<int> & height){
    stack<int> tracker;
    int sum = 0;
    // store height idx, rather than height!
    for(int i = 0; i < height.size();){
        if(tracker.empty() || height[i] <= height[tracker.top()]){
            tracker.push(i++);
        } else {
            int bottom = height[tracker.top()];
            tracker.pop();
            sum += tracker.empty()? 0: ((min(height[tracker.top()], height[i]) - bottom) * (i - tracker.top() -1));
            //++i;, to be considered as a new barrier        
        }
    }
    return sum;
}




int main(){
    TrappingRainWater trapper;
    vector<int> test {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << trapper.trap2(test) << endl;
}
