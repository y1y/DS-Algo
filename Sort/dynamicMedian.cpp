#include <queue>
#include <vector>
#include <iostream>
using namespace std;

class DynamicMedian{
public:
   double findMedian();
   void add(int val);
private:
   priority_queue<int> lowQ;
   priority_queue<int, vector<int>, greater<int>> highQ;
};

double DynamicMedian::findMedian(){
   if(lowQ.size() == highQ.size()){
        return (lowQ.top() + highQ.top()) / 2.0;
   } else if(lowQ.size() > highQ.size()){
	return lowQ.top();
   } else {
        return highQ.top();
   }
}

void DynamicMedian::add(int val){
   if(lowQ.empty() || val < lowQ.top()){
       lowQ.push(val);
   } else { 
       highQ.push(val);
   }

   if(lowQ.size() > highQ.size() + 1){
       highQ.push(lowQ.top());
       lowQ.pop();
   } else if (highQ.size() > lowQ.size() + 1){
       lowQ.push(highQ.top());
       highQ.pop();
   } 
}

int main(){
   DynamicMedian solver;
   vector<int> nums{1, 2, 3, 4, -1, -2, -3};
   for(auto &num: nums){
       solver.add(num);
       cout << solver.findMedian() << endl;
   } 
}
