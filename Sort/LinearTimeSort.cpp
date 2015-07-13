#include <iostream>
#include <vector>
using namespace std;

class LinearTimeSort{
public:
    void countingSort(int k, vector<int> & data);
    void radixSortLSDSameLength(vector<string> & data);
    void bucketSort(vector<int> &data);
};

void LinearTimeSort::countingSort(int k, vector<int> & data){
    vector<int> count(k + 1);
    for(auto & ele: data){
        ++count[ele];
    }
    
    for(int i = 1; i <= k; ++i){
        count[i] += count[i-1];
    }
    vector<int> sortedData(data.size());
    for(int j = data.size() - 1; j >= 0; --j){
       sortedData[--count[data[j]]] = data[j]; 
    } 
    data = sortedData;
}

// Pre: Same-length String in Capital letters;
// Non-empty
void LinearTimeSort::radixSortLSDSameLength(vector<string> & data){
}

void LinearTimeSort::bucketSort(vector<int> & data){}


int main(){
    vector<int> test {2, 5, 3, 0, 2, 3, 0, 3};
    LinearTimeSort solver;
    solver.countingSort(5, test);

    for(auto & t: test){
        cout << t << ",";
    }
    cout << endl;
}
