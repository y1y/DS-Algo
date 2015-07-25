#include <vector>
#include <stack>

using namespace std;

class LargestRec{
public:
    int largestRectangleArea(vector<int> & height);
};

int LargestRec::largestRectangleArea(vector<int> & height){
    stack<int> left_mins;
    int i = 0;
    int max_area = 0;
    height.push_back(-1);
    while(i < height.size()){
        if(left_mins.empty() || height[i] >= height[left_mins.top()]){
            left_mins.push(i++);
        } else {
            // cur height is smaller than the one in stack
            // cur height is right min
            int right_min = height[i];
            int cur_h = height[left_mins.top()];
            while(right_min < cur_h){
                left_mins.pop();
                int left_min = left_mins.empty()? -1: left_mins.top();
                max_area = max(cur_h * (i - left_min -1), max_area);
                if(left_mins.empty()){
                    break;
                }
                cur_h = height[left_mins.top()];
            }
        }
    }
    return max_area;

}
