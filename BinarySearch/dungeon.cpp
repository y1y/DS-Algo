#include <vector>
#include <iostream>
#include <climits>
using namespace std;

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int lo = 0;
        int hi = 1;
        int hp = 1;
        int i = 0;
        for(; i < dungeon.size(); ++i){
            hp += dungeon[i][0];
            if(hp < 1){
                hi += 1 - hp;
                hp = 1;
            }
        }
        i = i - 1;
        for(int j = 1; j < dungeon[0].size(); ++j){
            hp += dungeon[i][j];
            if(hp < 1){
                hi += 1 - hp;
                hp = 1;
            }
        }
        while(lo < hi){
            int mid  = lo + (hi - lo) / 2;
            vector<vector<int>> cur_health(dungeon.size() + 1, vector<int>(dungeon[0].size() + 1, INT_MIN));
            cur_health[0][1] = cur_health[1][0] = mid;

            for(int i = 1; i <= dungeon.size(); ++i){
                for(int j = 1; j <= dungeon[0].size(); ++j){
                    int hp = max(cur_health[i-1][j], cur_health[i][j-1]); 
                    cur_health[i][j] = (hp == INT_MIN)? INT_MIN : hp + dungeon[i-1][j-1];
                    if(cur_health[i][j] < 1){
                        cur_health[i][j] = INT_MIN;
                    }
                }
            }
            if(cur_health.back().back() < 1){
                lo = mid + 1;
            } else {
                hi = mid;
            }
            
        }
        return lo;
    }

};

int main(){
    Solution solver;
    vector<vector<int>> test{{0, -40, 100}, {-30, -30, 1}, {30, 30, 0}};
    cout << solver.calculateMinimumHP(test) << endl;

} 
