#include <cmath>

using namespace std;

struct Point{
   Point(double a, double b) : x(a), y(b), distSq(a*a + b*b);
   double x;
   double y;
   double distSq;
}

struct PointCmp{
  bool operator()(const Point & l, const Point & r){
      return l.distSq < r.distSq;
  }
} pointCmp;
class bucketSortPoint{
public:
    bucketSortPoint(vector <Point> & data);
private:
    vector<vector<Point>> bucket;
};



bucketSortPoint::bucketSort(vector<Point> & data){
    bucket(data.size());
    for(int i = 0; i < data.size(); ++i){
        bucket[n * data[i].dist].push_back(data[i]);
    }
    for(int i = 0; i < data.size(); ++i){
        sort(bucket[i].begin(), bucket[i].end(), pointCmp);
    }
    int i = 0;
    for(auto & singleB : bucket){
        for(auto & point: singleB){
            data[i++] = point;
        }
    }   
}


