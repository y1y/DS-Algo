#include <vector>
#include <iostream>
#include <cassert>
using namespace std;

class BinarySearch{
public:
    int search(vector<int> & data, int target);
    int lowerBoundGreaterEqual(vector<int> & data, int target);
    int lowerBoundLessEqual(vector<int> & data, int target);
    int upperBoundGreaterThan(vector<int> & data, int target);
};

int BinarySearch::search(vector<int> & data, int target){
    int low = 0;
    int high = data.size() - 1;
    while(low <= high){
        int mid = low + (high - low) / 2;
        if(data[mid] < target){
            low = mid + 1;
        } else if (data[mid] > target) {
            high = mid - 1;
        } else {
            return mid;
        }
    }
    return -1;
}


// return the first idx greater or equal to target
// target: 1
// low = 0, high = 1, mid = 0
// [-1, 1]
int BinarySearch::lowerBoundGreaterEqual(vector<int> & data, int target){
    int low = 0;
    int high = data.size() - 1;
    while(low < high){
        int mid = low + (high - low) / 2;
        if(data[mid] < target){
            low = mid + 1;
        } else {
            high = mid;
        }
    }
    if(data[low] < target){
        return -1;
    }
    return low;
}

// The largest idx less than or equal to target
// low = 0, high = 1, mid = 0
// [-1, 1]
int BinarySearch::lowerBoundLessEqual(vector<int> & data, int target){
    int low = 0;
    int high = data.size() - 1;
    while(low < high){
        int mid = low + (high - low + 1) / 2;
        if(data[mid] <= target) {
            low = mid;
        } else {
            high = mid - 1;
        }
    }
    if(data[low] > target){
        return -1;
    } 
    return low;
}

// The first element greater than target
// [0, 1] -1
// low = 0, high = 1, mid = 0
int BinarySearch::upperBoundGreaterThan(vector<int> & data, int target){
    int low = 0;
    int high = data.size() - 1;
    while(low < high){
        int mid = low + (high - low) / 2;
        if(data[mid] > target){
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    if(data[low] <= target){
        return -1;
    }
    return low;
}



int main(){
    BinarySearch bs;
    vector<int> test {1, 3};
    assert(bs.search(test,1) == 0);
    assert(bs.search(test,3) == 1);
    assert(bs.search(test,-1) == -1);
    assert(bs.lowerBoundGreaterEqual(test, 1) == 0);
    assert(bs.lowerBoundGreaterEqual(test,2) == 1);
    assert(bs.lowerBoundGreaterEqual(test,4) == -1);
    assert(bs.lowerBoundLessEqual(test, 1) == 0);
    assert(bs.lowerBoundLessEqual(test, 2) == 0);
    assert(bs.lowerBoundLessEqual(test, -1) == -1);
    assert(bs.upperBoundGreaterThan(test, 1) == 1);
    assert(bs.upperBoundGreaterThan(test, 2) == 1);
    assert(bs.upperBoundGreaterThan(test, 4) == -1);
}
