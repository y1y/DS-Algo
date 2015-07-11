#include <algorithm>
#include <iostream>
using namespace std;

template<typename T>
class HeapSort{
public:
    HeapSort(){}
    ~HeapSort(){}
    void heapSort(vector<T> & array);
private:  
    int length;
    vector<T> data; 
    void buildHeap();
    void maxHeapify(int idx);
};

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

template<typename T>
void HeapSort<T>::buildHeap(){
    for(int i = length / 2; i >= 1; --i){
        maxHeapify(i);    
    }
}

template<typename T>
void HeapSort<T>::maxHeapify(int i){
    int largest = 0;
    while(i != largest){
        largest = i;
        int left = largest * 2;
        int right = largest * 2 + 1;
        if(left <= length && data[left] > data[largest]){
            largest = left;    
        }
        if(right <= length && data[right] > data[largest]){
            largest = right;    
        }
        swap(data[largest], data[i]);
    } 
}

int main(){
    vector<int> test{3, 4, 2, -1, -2};
    HeapSort<int>().heapSort(test);
    for(auto & t: test){
        cout << t << ",";    
    }   
    cout << endl;

}
