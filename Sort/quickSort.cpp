#include <vector>
#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <time.h>
#include <utility>
#include <cassert>

using namespace std;

class QuickSort{
public:
    void qsort(vector<int> &data);
    bool isSorted(int start, int end, vector<int> & data);
private:
    void sortHelper(int start, int end, vector<int> & data);
    void threeSortHelper(int start, int end, vector<int> & data);
    int partition(int start, int end, vector<int> & data);
    int randomPartition(int start, int end, vector<int> & data);
    int medianPartition(int start, int end, vector<int> & data);
    int getRandom(int start, int end);
    int hoarePartition(int start, int end, vector<int> & data);
    pair<int, int> threeWayPartition(int start, int end, vector<int> & data);
    pair<int, int> fastThreePartition(int start, int end, vector<int> & data);
    void shuffle(vector<int> & data);
};

void QuickSort::qsort(vector<int> & data){
    threeSortHelper(0, data.size() - 1, data);
}

void QuickSort::sortHelper(int start, int end, vector<int> & data){
    if(start >= end){
        return;
    }
    int pivot = hoarePartition(start, end, data);
    sortHelper(start, pivot - 1, data);
    sortHelper(pivot + 1, end, data);
}

int QuickSort::partition(int start, int end, vector<int> & data){
    int pivot = data[end];
    int i = start;
    int j = start;
    while(j < end){
        if(data[j] <= pivot){
            swap(data[i++], data[j]);
        }
        ++j;
    }
    swap(data[i], data[end]);
    return i;    
}

int QuickSort::getRandom(int start, int end){
    srand(time(NULL));
    return rand() % (end - start + 1) + start;
}

int QuickSort::randomPartition(int start, int end, vector<int> & data){
    int randomPivot = getRandom(start, end);
    swap(data[end], data[randomPivot]);
    return partition(start, end, data);
}
int QuickSort::medianPartition(int start, int end, vector<int> & data){
    int random1 = getRandom(start, end);
    int random2 = getRandom(start, end);
    int random3 = getRandom(start, end);
     
    vector<int> pivotArray{data[random1], data[random2], data[random3]};
    sort(pivotArray.begin(), pivotArray.end());
    swap(data[end], data[pivotArray[1]]);
    partition(start, end, data);
}

int QuickSort::hoarePartition(int start, int end, vector<int> & data){
    int pivot = data[start];
    int i = start;
    int j = end + 1;
    while(true){
        do{
            ++i;
        } while( i <= end && data[i] < pivot);
        
        do{
            --j; 
        } while (data[j] > pivot);    
        
        if(i > j){
            break;
        }
        swap(data[i], data[j]);
    } 
    swap(data[start], data[j]);
    return j;
}

pair<int, int> QuickSort::threeWayPartition(int start, int end, vector<int> & data){
    int pivot = data[start];
    int low = start;
    int high = end;
    int i = low + 1;
 
    while(i <= high){
        if(data[i] < pivot){
            swap(data[i++], data[low++]);
        } else if (data[i] > pivot){
            swap(data[i], data[high--]);
        } else {
            ++i;
        }
    }
    return make_pair(low, high); 
}

pair<int, int> QuickSort::fastThreePartition(int start, int end, vector<int> & data){
	int i = start, j = end + 1;
        int p = start, q = end + 1;
        int v = data[start];
        while(true){
            while(data[++i] < v){
	        if(i == end){
                     break;
                }
            }
	    while(data[--j] > v){
                if(j == start){
                     break;
                }
            }
            if(i == j && data[i] == v){
                swap(data[++p], data[i]);
            }
            if(i >= j) break;
            swap(data[i], data[j]);
            if(data[i] == v){
                swap(data[++p], data[i]);
            }
            if(data[j] == v){
                swap(data[--q], data[j]);
            }
        }

        i = j + 1;
        for(int k = start; k <= p; ++k){
	    swap(data[k], data[j--]);
        }
        for(int k = end; k>= q; --k){
            swap(data[k], data[i++]);
        }
        return make_pair(j + 1, i - 1);
}
void QuickSort::threeSortHelper(int start, int end, vector<int> & data){
    if(start >= end){
       return;
    }
    auto bound = fastThreePartition(start, end, data); 
    threeSortHelper(start,bound.first - 1, data);
    threeSortHelper(bound.second + 1, end, data);  
}

bool QuickSort::isSorted(int start, int end, vector<int> & data){
    for(int i = start + 1; i <= end; ++i){
        if(data[i] < data[i-1]){
            return false;
        }
    }
    return true;

}

void QuickSort::shuffle(vector<int> & data){
    for(int i = 0; i < data.size(); ++i){
       srand(time(NULL));
       int r = rand() % (i + 1);
       swap(data[i], data[r]);
    }

}
int main(){
    vector<int> test1 {0};
    vector<int> test2 {-1, 3, 2, 4,-10, 100};
    QuickSort solver;
    solver.qsort(test1);
    solver.qsort(test2);
    assert(solver.isSorted(0, test1.size()-1, test1));
    assert(solver.isSorted(0, test2.size()-1, test2));
    for(auto & t: test1){
        cout << t << ",";
    }
    cout << endl; 
    for(auto & t: test2){
        cout << t << "," << endl;
    }
}
