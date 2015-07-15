#include <vector>
#include <iostream>

using namespace std;

class MergeSort{
public:
    void mergeSort(vector<int> & data);
    void optimizedMergeSort(vector<int> & data);
    void bottomUpMergeSort(vector<int> & data);
private:
    void mergeSortHelper(vector<int> & data, vector<int> & auxData, int low, int high);
    void optimizedMergeSortHelper(vector<int> & src, vector<int> & dst, int low, int high);
    void merge(vector<int> & data, vector<int> & auxData, int low, int mid, int high);
    void optimizedMerge(vector<int> & src, vector<int> & dst, int low, int mid, int high);
};

void MergeSort::mergeSort(vector<int> & data){ 
    vector<int> auxData(data.size());
    mergeSortHelper(data, auxData, 0, data.size() - 1);
}

void MergeSort::optimizedMergeSort(vector<int> & data){
    vector<int> auxData(data.begin(), data.end());
    optimizedMergeSortHelper(auxData, data, 0, data.size() - 1);
}

void MergeSort::mergeSortHelper(vector<int> & data, vector<int> & auxData, int low, int high){
    if(low < high){
        int mid = low + (high - low) / 2;
        mergeSortHelper(data, auxData, low, mid);
        mergeSortHelper(data, auxData, mid + 1, high);
        merge(data, auxData, low, mid, high);     
    }
}

void MergeSort::merge(vector<int> & data, vector<int> & auxData, int low, int mid, int high) {
    for(int k = low; k <= high; ++k){
         auxData[k] = data[k];
    }
    int i = low;
    int j = mid + 1;
    int k = low;
    while(i <= mid && j <= high){
        // stability note: take equal one from left
        if(auxData[i] <= auxData[j]){
           data[k++] = auxData[i++];
        } else {
           data[k++] = auxData[j++];
        }
    } 
    while(i <= mid){
        data[k++] = auxData[i++];
    }
    while(j <= high){
        data[k++] = auxData[j++];
    }
}


void MergeSort::optimizedMergeSortHelper(vector<int> & src, vector<int> & dst, int low, int high){
    // use insertion sort for small subarrays
    if(low < high){
        int mid = low + (high - low) / 2;
        optimizedMergeSortHelper(dst, src, low, mid);
        optimizedMergeSortHelper(dst, src, mid + 1, high);
        if(src[mid] <= src[mid + 1]){
            for(int k = low; k <= high; ++k){
                dst[k] = src[k];
            }
            return;
        }
        optimizedMerge(src, dst, low, mid, high);     
    }

}
void MergeSort::optimizedMerge(vector<int> & src, vector<int> & dst, int low, int mid, int high){
    int i = low;
    int j = mid + 1;
    int k = low;
    while(i <= mid && j <= high){
        // stability note: take equal one from left
        if(src[i] <= src[j]){
           dst[k++] = src[i++];
        } else {
           dst[k++] = src[j++];
        }
    } 
    while(i <= mid){
        dst[k++] = src[i++];
    }
    while(j <= high){
        dst[k++] = src[j++];
    }

}

void MergeSort::bottomUpMergeSort(vector<int> & data){
    int n = data.size();
    vector<int> auxData (data.size());
    for(int i = 1; i < n; i *= 2){
        for(int j = 0; j < n - i; j += 2 * i){
           int lo = j;
           int m = j + i - 1;
           int hi = min(j + 2 * i - 1, n - 1);
           merge(data, auxData, lo, m, hi);
        } 
    }
}


int main(){
    vector<int> test1{2, 1};
    vector<int> test2{2, 1, 3};
    MergeSort solver;
    solver.bottomUpMergeSort(test2);
    for(auto & t: test2){
        cout << t << ",";
    }
    cout << endl;
}
