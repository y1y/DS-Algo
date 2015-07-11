#include <algorithm>
#include <iostream>
#include <climits>
#include <cassert>

using namespace std;

class YoungT{
public:
    YoungT();
    YoungT(int m, int n);
    ~YoungT(){}
    bool isFull();
    bool find(int val);
    void insert(int val);
    int extractMin();
    void sort(vector<int> & nums);
    //ostream & operator<<(YoungT & yongT, ostream & os);
private:
    vector<vector<int>> data;
    void YoungTify(int i, int j);
    void initialize(int m, int n);
};


void YoungT::initialize(int m, int n){
    data = vector<vector<int>> (m, vector<int>(n, INT_MAX));
}
YoungT::YoungT(){
    initialize(1,1);
}

YoungT::YoungT(int m, int n){
    initialize(m,n);
}

bool YoungT::isFull(){
    return data.back().back() != INT_MAX;
}
bool YoungT::find(int val){
    int i = data.size() - 1;
    int j = 0;

    while(i >= 0 && j < data[0].size()){
        if(data[i][j] < val){
            ++j;
        } else if (data[i][j] > val){
            --i;
        } else {
            return true;    
        }    
    }
    return false;
}

void YoungT::insert(int val){
    if(isFull()){
        for(auto &row: data){
            row.resize(row.size() * 2, INT_MAX);    
        }
        data.resize(data.size() * 2, vector<int>(data[0].size(), INT_MAX));
    }
    assert(!isFull()); 
    data.back().back() = val;
    
    int i = data.size() - 1;
    int j = data[0].size() - 1;

    while(i >= 0 && j >=0){
        int curMax = val;
        bool rowMove = false;
        if((i - 1) >= 0 && data[i-1][j] > val){
            curMax = data[i-1][j];
            rowMove = true;
        }        
        if((j - 1) >= 0 && data[i][j-1] > curMax){
            curMax = data[i][j-1];
            rowMove = false;
        }
        
        data[i][j] = curMax;
        if(curMax == val){
            break;    
        } else if(rowMove){
            i = i - 1;     
        } else {
            j = j - 1;
        }
    }

}

int YoungT::extractMin(){
    int min = data[0][0];
    data[0][0] = INT_MAX;
    YoungTify(0, 0); 
    return min;
}

void YoungT::sort(vector<int> & nums){
    initialize(sqrt(nums.size()), sqrt(nums.size()));
    for(auto & num: nums){
        insert(num);
    }
    for(int i = 0; i < nums.size(); ++i){
        nums[i] = extractMin();    
    }
}



void YoungT::YoungTify(int i, int j){
    int val = data[i][j];
    while(i < data.size() && j < data[0].size()){
        int curMin = val;
        bool rowMove = false;
        if((i + 1) < data.size() && data[i+1][j] < curMin){
            curMin = data[i+1][j];
            rowMove = true;
        }
        if((j + 1) < data[0].size() && data[i][j+1] < curMin){
            curMin = data[i][j+1];
            rowMove = false;
        }

        data[i][j] = curMin;
        if(curMin == val){
            break;
        } else if(rowMove){
            i = i + 1;
        } else {
            j = j + 1;
        }          
    }    
}

int main(){
    vector<int> test{3, 4, 2, -1, -2, -3, 7, -4, 9};
    YoungT youngt;
    youngt.sort(test);
    for(auto & t: test){
        cout << t << ",";    
        youngt.insert(t);
    }
    cout << endl;
    cout << youngt.find(2) << endl;
    cout << youngt.find(0) << endl;
}
