#include <vector>
#include <iostream>
using namespace std;

class SortColor{
public:
    void sortColorsCountingSort(vector<int> & nums);
    void sortColorCountingSortInPlace(vector<int> & nums);
    void sortColorThreeWayPartition(vector<int> & nums);
    void sortColorFastThreeWayPartition(vector<int> & nums);
};

void SortColor::sortColorsCountingSort(vector<int> & nums){
     vector<int> colorCount(3);
     for(auto &num : nums){
         colorCount[num]++;
     }
     vector<int> start(3);
     for(int i = 1; i < 3; ++i){
        start[i] = start[i-1] + colorCount[i-1];
     }

     vector<int> colors(nums.size());
     for(auto & num: nums){
         colors[(start[num])++] = num;
     }
     nums = colors;
}

void SortColor::sortColorCountingSortInPlace(vector<int> & nums){
        vector<int> countArray(3);
        for(auto & num: nums){
            ++countArray[num]; 
        }
        int current = 0;
        for(int i = 0; i <= 2; ++i){
            for(int j = 0; j < countArray[i]; ++j){
                nums[current++] = i;
            }
        }
}

void SortColor::sortColorThreeWayPartition(vector<int> & nums){
     int low = -1;
     int i = 0;
     int j = nums.size() - 1;
     while(i <= j){
         if(nums[i] == 1){
            ++i;
         } else if (nums[i] > 1) {
	     swap(nums[j--], nums[i]);
         } else {
             swap(nums[i++], nums[++low]);
         }
     }    
}

void SortColor::sortColorFastThreeWayPartition(vector<int> & nums){
    int p = -1;
    int i = -1;
    int j = nums.size();
    int q = nums.size();
    int end = j - 1;
    while(true){
        while(i < end && nums[++i] == 0){
        }
        while(j > 0 && nums[--j] == 2){
        }
        if(i == j && nums[i] == 1){
	    swap(nums[i], nums[++p]);
        }
        if(i >= j){
            break;
        }
        swap(nums[i], nums[j]);
        if(nums[i] == 1){
            swap(nums[i], nums[++p]);
        }
        if(nums[j] == 1){
            swap(nums[j], nums[--q]);
        }
    }
    i = j + 1;
    for(int k = 0; k <= p; ++k){
        swap(nums[k], nums[j--]);
    }
    for(int k = end; k >= q; --k){
        swap(nums[k], nums[i++]);
    }

}



int main(){
    SortColor solver;
    vector<int> test {1,0 ,2, 1, 1, 1, 1,2 , 0, 0, 2};
    solver.sortColorFastThreeWayPartition(test);
    for(auto t: test){
        cout << t << ",";
    }
    cout << endl;
}

