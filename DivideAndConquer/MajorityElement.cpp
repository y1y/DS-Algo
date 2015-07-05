#include <vector>
#include <cassert>
#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

class MajorityElement{
public:
    int majorityElement(vector<int> &num);
private:
    int majorityElement(int start, int end, vector<int> &num);
};

int MajorityElement::majorityElement(vector<int> &num){
    return majorityElement(0, num.size(), num);
}
int MajorityElement::majorityElement(int start, int end, vector<int> &num){
    if(start >= end){
        return INT_MIN;    
    }
    if(end - start == 1){
        return num[start];    
    }
    
    int mid = start + (end - start) / 2;
    int leftMajority = majorityElement(start, mid, num);
    int rightMajority = majorityElement(mid, end, num);
    if(leftMajority == rightMajority){
        return leftMajority;
    } else {
        if(leftMajority == INT_MIN){
            return rightMajority;
        }
        if(rightMajority == INT_MIN){
            return leftMajority;    
        }
        //int leftCount = count(advance(num.begin(), start), advance(num.begin(), mid), leftMajority);
        //int rightCount = count(advance(num.begin(), mid), advance(num.begin(), end), rightMajority);
        
        int leftCount = count(num.begin(), num.end(), leftMajority);
        int rightCount = count(num.begin(), num.end(), rightMajority);

        if(leftCount > rightCount){
            return leftMajority;    
        } else if (leftCount < rightCount){
            return rightMajority;    
        } else {
            return INT_MIN;
        }
    }
}

int main(){
    vector<int> nums1 {1, 2, 1};
}
