#include <vector>
#include <utility>
#include <cassert>
#include <iostream>
#include <queue>
using namespace std;


class SkylineProblem {
public:
   vector<pair<int, int>> getSkyline(vector<vector<int>> & buildings);
};

vector<pair<int, int>> SkylineProblem::getSkyline(vector<vector<int>> & buildings){
    int cur = 0, curX = 0, curH = 0;
    priority_queue<pair<int, int>> activeBuildings;
    vector<pair<int, int>> ret;
    while(cur < buildings.size() || !activeBuildings.empty()){
        if(activeBuildings.empty() || cur < buildings.size() && buildings[cur][0] <= activeBuildings.top().second){
            curX = buildings[cur][0];
            while(cur < buildings.size() && buildings[cur][0] == curX){
                activeBuildings.push(make_pair(buildings[cur][2], buildings[cur][1]));
                ++cur;    
            }      
        } else {
            curX = activeBuildings.top().second;
            while(!activeBuildings.empty() && activeBuildings.top().second <= curX){
                activeBuildings.pop();    
            }    
        }
        curH = activeBuildings.empty()? 0: activeBuildings.top().first;
        if(ret.empty() || ret.back().second  != curH){
            ret.push_back(make_pair(curX, curH));    
        }
    }
    return ret;
}


int main(){
    SkylineProblem skylineSolver;
    vector<vector<int>> buildings1 {{0, 3, 1}, {2, 4, 2}};
    vector<vector<int>> buildings2 {{0, 1, 1}, {0, 2, 2}};
    vector<vector<int>> buildings3 {{0, 3, 1}, {4, 6, 2}};
    vector<pair<int, int>> result1 = skylineSolver.getSkyline(buildings1);
    vector<pair<int, int>> result2 = skylineSolver.getSkyline(buildings2);
    vector<pair<int, int>> result3 = skylineSolver.getSkyline(buildings3);
    vector<pair<int, int>> expect1 {{0, 1}, {2, 2}, {4,0}};
    vector<pair<int, int>> expect2 {{0, 2}, {2, 0}};

    assert(result1 == expect1);
    assert(result2 == expect2);
}
