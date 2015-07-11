#include <iostream>
#include <queue>
#include <algorithm>
#include <iterator>
using namespace std;

int main(){
   int num;
   int m = 5;
   priority_queue<int> q;
   while(cin >> num){
       q.push(num);
       if(q.size() > 5){
           q.pop();    
       }
   } 
   
   vector<int> outVec;
   while(!q.empty()){
       outVec.push_back(q.top());   
       q.pop();
   }
    for(auto &num : outVec){
        cout << num << ",";    
    }
    cout << endl;
}
