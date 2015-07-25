#include <vector>

class MaxRec{
public:
    int maximalRectangle(vector<vector<char>> & matrix);
    int maximalRectangle2(vector<vector<char>> & matrix);
private:
    int largestRec(const vector<int> & height);
};

int MaxRec::maximalRectanlge(vector<vector<char>> & matrix){
    
    int area = 0;
    if(matrix.empty()){
        return area;
    }
    int n = matrix[0].size();
    vector<int> height (n);
    vector<int> left (n);
    vector<int> right (n, n);

    for(int i = 0; i < matrix.size(); ++i){
        int cur_left = 0;
        int cur_right = n;

        for(int j = 0; j < n; ++j){
            if(matrix[i][j] == '1'){
                height[j] += 1;
                left[j] = max(left[j], cur_left);
            } else {
                height[j] = 0;
                left[j] = 0;
                cur_left = j + 1;
            }
        }
        // left: prev to start
        // right: exact end
        for(int j = n - 1; j >= 0; --j){
            if(matrix[i][j] == '1'){
                right[j] = min(right[j], cur_right);
            } else {
                right[j] = n;
                cur_right = j;
            }
        }
        for(int j = 0; j < n; ++j){
            area = max(area, (right[j] - left[j]) * height[j]);           
        }
    }
    return area;
}

int MaxRec::maximalRectangle2(vector<vector<char>> & matrix){
    if(matrix.empty()){
        return 0;
    }
    int area = 0;
    int n = matrix[0].size();
    vector<int> height(n + 2);
    
    for(int i = 0; i < matrix.size(); ++i){
        for(int j = 0; j < n; ++j){
            if(matrix[i][j] == '0'){
                height[j + 1] = 0;
            } else {
                ++height[j + 1];
            }
        }
        area = max(area, largestRec(height));
    }
}

int MaxRec::largestRec(const vector<int> & height){
    stack<int> leftMins;
    int i = 0;
    int area = 0;
    while(i < height.size()){
        if(leftMins.empty() || height[i] >= height[leftMins.top()]){
            leftMins.push(i++); 
        } else {
            int right_min = height[i];
            while(height[leftMins.top()] > right_min){
                int h = height[leftMins.top()];
                leftMins.pop();
                int w = i - leftMins.top() - 1;
                area = max(area, w * h);
            }
        }
    }
    return area;
}
