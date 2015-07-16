#include <vector>
#include <iostream>
using namespace std;

class CountingSortInPlace{
public:
    void sort(vector<int> & data, int k);
    void sortWithSwap(vector<int> & data, int k);
};

void CountingSortInPlace::sort(vector<int> & data, int k){
    vector<int> countArray(k + 1);
    for(auto & num: data){
        ++countArray[num]; 
    }
    for(auto & cnt: countArray){
        cout << cnt << " ";
    }
    cout << endl;
    // [3, 3, 4]
    int current = 0;
    for(int i = 0; i <= k; ++i){
        for(int j = 0; j < countArray[i]; ++j){
            cout << "current:" << current << endl;
	    cout << "j:" << j << "-k:" << i << endl; 
            data[current++] = i;
            
        }
    }
}


void CountingSortInPlace::sortWithSwap(vector<int> & data, int k){
    vector<int> countArray(k + 1);
    for(auto & num: data){
        ++countArray[num]; 
    }
    for(int i = 1; i <= k; ++i){
        countArray[i] += countArray[i-1];
    } 
    for(int i = 0; i < data.size(); ++i){
        int val = data[i];
        int j = countArray[val];
        if(j > i) {
            do {
                --countArray[val];
		swap(val, data[j-1]);
                j = countArray[val];
            } while (j > i);
            data[i] = val;
        }
    }
}


int main(){
    CountingSortInPlace solver;
    vector<int> data {1, 2, 2, 2, 2, 0, 0, 0, 1, 1};
    solver.sortWithSwap(data, 2);
    for(auto & ele: data){
        cout << ele << " ";
    }
    cout << endl;
}
