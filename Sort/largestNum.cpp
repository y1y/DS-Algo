#include <string>
#include <algorithm>
#include <vector>
using namespace std;
struct cmp{
  bool operator()(string &l, string & r){
      return (l + r) > (r + l);
  }  
};

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> numString;
        for(auto & num: nums){
            numString.push_back(to_string(num));
        }
        sort(numString.begin(), numString.end(), cmp());
        string result = "";
        for(auto & numStr: numString){
            for(auto & digit: numStr){
                result += digit;
            }
        }
        if(!result.empty() && result[0]=='0'){


        }
        return result;
    }

};

int main(){

}
