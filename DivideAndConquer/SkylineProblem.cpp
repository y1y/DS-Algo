#include <vector>
#include <utility>
#include <cassert>
#include <iostream>
using namespace std;

/* 1. Divide the building to left part and right part
 * 2. Conquer 
 *      Base case: single building skyline
 *      [Li, Ri, Hi] -> [Li, Hi] , [Ri, 0]
 * 3. Merge the skylines together
 *      [a, b], [c, d]
 *       - left: min(a, c)
 *       - height: max height in current range
 *       - corner case: 
 *          a = = b
 *          
 * 
 * Time Complexity: O(nlogn)
 * Space Complexity: O(n)
 *
 */


class SkylineProblem {
private:
   vector<pair<int, int>> getSkylineHelper(int start, int end, vector<vector<int>> & buildings);
   vector<pair<int, int>> getSkylineForSingleBuilding(int idx, vector<vector<int>> & buildings);
   vector<pair<int, int>> mergeSkylines(vector<pair<int, int>> & leftSkyline, vector<pair<int, int>> &rightSkyline);
public:
   vector<pair<int, int>> getSkyline(vector<vector<int>> & buildings){
       return getSkylineHelper(0, buildings.size(), buildings);        
   }

  
};

vector<pair<int, int>> SkylineProblem::getSkylineHelper(int start, int end, vector<vector<int>> & buildings){
    // base case
    if(end - start == 1){
        return getSkylineForSingleBuilding(start, buildings);    
    }
    // Don't forget to handle corner case: start == mid!
    vector<pair<int, int>> result;
    if(start < end){ 
        int mid = start + (end - start) / 2; 
        vector<pair<int, int>> leftSkyline = getSkylineHelper(start, mid, buildings);
        vector<pair<int, int>> rightSkyline = getSkylineHelper(mid, end, buildings);
        result = mergeSkylines(leftSkyline, rightSkyline); 
    }
    return result;
} 

vector<pair<int, int>> SkylineProblem::getSkylineForSingleBuilding(int idx, vector<vector<int>> & buildings) {
    vector<pair<int, int>> result;
    result.push_back(make_pair(buildings[idx][0], buildings[idx][2]));
    result.push_back(make_pair(buildings[idx][1], 0));    
    return result;
}

vector<pair<int, int>> SkylineProblem::mergeSkylines(vector<pair<int, int>> & leftSkyline, vector<pair<int, int>> &rightSkyline){
    vector<pair<int, int>> result;
    int leftHeight = 0;
    int rightHeight = 0;
    int leftIdx = 0;
    int rightIdx = 0;
    
    while(leftIdx < leftSkyline.size() && rightIdx < rightSkyline.size()){
        int leftHorizontalCoordinate = leftSkyline[leftIdx].first ;
        int rightHorizontalCoordinate = rightSkyline[rightIdx].first;
        int newHorizontalCoordinate = 0;
        if(leftHorizontalCoordinate < rightHorizontalCoordinate){
            leftHeight = leftSkyline[leftIdx].second;
            newHorizontalCoordinate = leftHorizontalCoordinate;    
            ++leftIdx;
        } else if(leftHorizontalCoordinate > rightHorizontalCoordinate){
            rightHeight = rightSkyline[rightIdx].second;
            newHorizontalCoordinate = rightHorizontalCoordinate;
            ++rightIdx;
        } else {
            leftHeight = leftSkyline[leftIdx].second; 
            rightHeight = rightSkyline[rightIdx].second;
            newHorizontalCoordinate = leftHorizontalCoordinate;
            ++leftIdx;
            ++rightIdx;
        }
        
        // check duplicate
        
        int newHeight = max(leftHeight, rightHeight);
        // It is the same height that makes duplicate, not the same coordinate
        if(result.empty() || result.back().second != newHeight){
            result.push_back(make_pair(newHorizontalCoordinate, newHeight));    
        }
    }   
    
    // Don't forget to remove the remaining elements to the result;
    // Previouse already end
    while(leftIdx < leftSkyline.size()){
       // scope!
       // Don't forget to advance idx
       //int newHeight = leftSkyline[leftIdx].second;
       //int newHorizontalCoordinate = leftSkyline[leftIdx].first;
       
       if(result.empty() || result.back().second != leftSkyline[leftIdx].second){
          //result.push_back(make_pair(newHorizontalCoordinate, newHeight));    
          result.push_back(leftSkyline[leftIdx]);
       }
       ++leftIdx;
    }
    
    while(rightIdx < rightSkyline.size()){
       //int newHeight = rightSkyline[rightIdx].second;
       //int newHorizontalCoordinate = rightSkyline[rightIdx].first;
       //if(result.empty() || result.back().second != newHeight){
       //   result.push_back(make_pair(newHorizontalCoordinate, newHeight));    
       //}
       if(result.empty() || result.back().second != rightSkyline[leftIdx].second){
          result.push_back(rightSkyline[rightIdx]);
       }
       ++rightIdx;
    }
 
     
    return result; 
};


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
