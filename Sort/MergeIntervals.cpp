#include <vector>
#include <iostream>
#include <cassert>
#include <algorithm>
using namespace std;

struct Interval{
    int start;
    int end;
    Interval(): start(0), end(0) {}
    Interval(int s, int e): start(s), end(e) {}
};

struct compareIntervals{
    bool operator()(Interval &l, Interval &r){
	if(l.start == r.start){
            return l.end < r.end;
        } else {
            return l.start < r.start;    
        }
    }
};

class MergeIntervals{
public:
    vector<Interval> merge(vector<Interval> & intervals);
};


vector<Interval> MergeIntervals::merge(vector<Interval> & intervals){
    sort(intervals.begin(), intervals.end(), compareIntervals());
    vector<Interval> result;
    for(auto & interval: intervals){
        if(result.empty() || result.back().end < interval.start){
            result.push_back(interval);
        } else {
            result.back().end = max(result.back().end, interval.end);
        }
    }
    return result;
}

int main(){
    MergeIntervals solver;
    vector<Interval> test1{Interval(1,4), Interval(2, 3)};
    vector<Interval> result1 = solver.merge(test1);
    for(auto & t: result1){
        cout << t.start << "," << t.end << endl;
    }
    vector<Interval> test2{Interval(1,5), Interval(1,2), Interval(0,3)};
    vector<Interval> result2 = solver.merge(test2);
    for(auto & t: result2){
        cout << t.start << "," << t.end << endl; 
    }
}
