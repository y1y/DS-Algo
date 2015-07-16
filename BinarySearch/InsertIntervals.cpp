#include <vector>
#include <iostream>
using namespace std;
struct Interval{
    int start;
    int end;
    Interval(): start(0), end(0){}
    Interval(int s, int e) : start(s), end(e) {}
};


class InsertIntervals{
public:
    vector<Interval> insert(vector<Interval> & intervals, Interval newInterval);
private:
    int findFirstStart(vector<Interval> & data, int target);
    int findFirstEnd(vector<Interval> & data, int target);
};


int InsertIntervals::findFirstStart(vector<Interval> & data, int target){
    int low = 0;
    int high = data.size() - 1;
    while(low < high){
        int mid = low + (high - low) / 2;
        if(data[mid].end < target){
	    low = mid + 1;
        } else {
	    high = mid;
        }
    }
    if(data.empty() || data[high].end < target){
        return data.size();
    }
    return high;
}


int InsertIntervals::findFirstEnd(vector<Interval> & data, int target){
    int low = 0;
    int high = data.size() - 1;
    while(low < high){
        int mid = low + (high - low) / 2;
        if(data[mid].end <= target){
	    low = mid + 1;
        } else {
	    high = mid;
        }
    }
    if(data.empty() || data[high].end < target){
        return data.size();
    }
    return high;


}
vector<Interval> InsertIntervals::insert(vector<Interval> & intervals, Interval newInterval){
    int firstStart = findFirstStart(intervals, newInterval.start);
    int firstEnd = findFirstEnd(intervals, newInterval.end);
    auto it = intervals.begin();
    advance(it, firstStart);
    if(firstEnd == firstStart){
        intervals.insert(it, newInterval);
    } else {
        ++it;
        intervals[firstStart].start = min(newInterval.start, intervals[firstStart].start);
        auto jt = intervals.begin();
        int newEnd = intervals[firstEnd - 1].end; 
        advance(jt, firstEnd);
        intervals.erase(it, jt);
        intervals[firstStart].end = max(newInterval.end, newEnd);
    }
    return intervals;
}

int main(){
    InsertIntervals solver;
    vector<Interval> test {Interval{1, 5}};
    vector<Interval> result = solver.insert(test, Interval{0, 0});
    for(auto &t : result){
        cout << t.start << "->" << t.end << endl;
    }
}
