#include <vector>
#include <cassert>
#include <iostream>
#include <climits>
#include <algorithm>
#include <cmath>

using namespace std;

class PowX{
public:
    double myPow(double x, int n);    
};

double PowX::myPow(double x, int n){
    int k = abs(n);
    //int result = 1;
    double result = 1;
      
    while(k > 0){
        if(k % 2){
            result *= x;    
        }
        x *= x;
        k = k / 2;
    }
    if(n < 0){
        return 1 / result;
    }
    return result;
}
int main(){
    cout << PowX().myPow(2, 5) << endl;
}
