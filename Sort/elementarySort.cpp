#include <vector>
#include <iostream>

using namespace std;

class ElementarySort{
public:
    void insertionSort(vector<int> & data);
    void optimizedInsertionSort(vector<int> & data);
    void selectionSort(vector<int> & data);
    void shellSort(vector<int> & data); 
    int getLowerBound(int low, int high, vector<int> & data, int target);
};

void ElementarySort::insertionSort(vector<int> & data){
    for(int i = 1; i < data.size(); ++i){
        for(int k = i-1; k >= 0; --k){
            if(data[k] > data[i]){
                 swap(data[k], data[i]);
            } else {
                 break;
            }
        }
    } 
}

void ElementarySort::optimizedInsertionSort(vector<int> & data){
    for(int i = 1; i < data.size(); ++i){
        int temp = data[i];
        int l = getLowerBound(0, i - 1, data, temp);
        for(int j = i; (j > l + 1) && j >= 1; --j){
            data[j] = data[j-1];
        }
        data[l + 1] = temp;
    } 
}

void ElementarySort::selectionSort(vector<int> & data){
     for(int i = 0; i < data.size() - 1; ++i){
	int minValue = data[i];
        int minIdx = i;
        for(int j = i + 1; j < data.size(); ++j){
            if(data[j] < minValue){
                minValue = data[j];
                minIdx = j;
            }
        }
        swap(data[minIdx], data[i]);
     } 
}


int ElementarySort::getLowerBound(int low, int high, vector<int> & data, int target){
   while(low <= high){
       int mid = low + (high - low) / 2;
       if(data[mid] <= target){
          low = mid + 1;
       } else if(data[mid] > target){
          high = mid - 1;
       } 
    } 
    return high;
}

//TODO:
void ElementarySort::shellSort(vector<int> & data){


}

int main(){
    ElementarySort solver;
    vector<int> data{2, -1, 3, 4, 1, 5};
    solver.optimizedInsertionSort(data);
    for(auto &a: data){
        cout << a << ",";
    }
    cout << endl;
}
