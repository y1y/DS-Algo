#include <iostream>
using namespace std;
// low = 1
int mySqrt(int x){
    long long low = 0;
    long long high = x;
    while(low < high){
        long long mid = low + (high - low + 1) / 2;
        if(mid * mid > x){
            high = mid - 1; 
        } else {
            low = mid;
        }
    }
    return low;
}

int main(){
    mySqrt(214783647);
}
