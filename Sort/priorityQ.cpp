#include <algorithm>
#include <iostream>
#include <climits>

using namespace std;

template<typename T>
class priorityQ{
public:
    priorityQ(){
        length = 0;
        data = vector<int> {INT_MIN};
    }
    ~priorityQ(){}
    void add(T value);
    T min();
    T extractMin();
    void decreaseKey(int idx, int key);
private:  
    int length;
    vector<T> data; 
    //void buildHeap();
    void minHeapify(int idx);
};

/*
template<typename T>
void HeapSort<T>::heapSort(vector<T> & array){
    data = vector<T>(1);
    for(auto & ele: array){
        data.push_back(ele); 
    }
    length = array.size();
    
    buildHeap();
    for(int i = length; i >= 2; --i){
        swap(data[1], data[i]);
        --length;
        maxHeapify(1);    
    }

    for(int i = 1; i <= array.size(); ++i){
        array[i-1] = data[i];    
    }
}
*/
/*
template<typename T>
void HeapSort<T>::buildHeap(){
    for(int i = length / 2; i >= 1; --i){
        maxHeapify(i);    
    }
}
*/
template<typename T>
void priorityQ<T>::minHeapify(int i){
    int smallest = 0;
    while(i != smallest){
        smallest = i;
        int left = smallest * 2;
        int right = smallest * 2 + 1;
        if(left <= length && data[left] < data[smallest]){
            smallest = left;    
        }
        if(right <= length && data[right] < data[smallest]){
            smallest = right;    
        }
        swap(data[smallest], data[i]);
    } 
}

template<typename T>
void priorityQ<T>::add(T value){
    data.push_back(INT_MAX);
    ++length;
    decreaseKey(length, value);
}

template<typename T>
T priorityQ<T>::min(){
    if(length < 1){
        exit(1);    
    }
    return data[1];
}

template<typename T>
T priorityQ<T>::extractMin(){
    if(length < 1){
        exit(1);
    }

    int min = data[1];    
    swap(data.back(), data[1]);
    data.pop_back();
    --length;
    minHeapify(1);
    return min; 
}
template<typename T>
void priorityQ<T>::decreaseKey(int idx, int value){
    if(idx <=0 || idx > length || value >= data[idx]){
        exit(1);
    }
    //data[idx] = value;
    //int temp = value;
    int parent = idx / 2;
    while(parent >= 1 && data[parent] > value){
        //swap(data[parent], data[idx]);
        data[idx] = data[parent];
        idx = parent;
        parent = idx / 2;
    }
    data[idx] = value;
}

int main(){
    vector<int> test{3, 4, 2, -1, -2};
    //HeapSort<int>().heapSort(test);
    
    priorityQ<int> Q;
    for(auto & t: test){
       Q.add(t); 
    }   

    for(int i = 0; i < test.size(); ++i){
        cout << Q.extractMin() << endl;    
    }
    cout << endl;

}
