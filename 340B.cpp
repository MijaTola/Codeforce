#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <climits>
#include <map>
#include <set>
#include <cassert>
#include <cstdio>
#include <cstring>

using namespace std;

typedef long long ll;

struct Point{
    double x,y;
    Point(){}
    Point(double _x, double _y){ x = _x, y = _y;}
};
Point operator - (const Point &A, const Point &B){ return Point(A.x-B.x,A.y-B.y);}
bool  operator < (const Point &A,const Point &B){return pair<double,double>(A.x,A.y) < pair<double,double>(B.x,B.y);}
double cross(Point A, Point B){return A.x*B.y-A.y*B.x;}
double area(const Point &A, const Point &B, const Point &C) { return cross(B - A, C - A); }

double area(const vector <Point> &P){
    int n = P.size();
    double A = 0;
    for(int i=1; i<=n-2; i++)
        A += area(P[0], P[i], P[i+1]);
    return abs(A/2);
}
vector <Point> convexhull(vector <Point> P){
    sort(P.begin(),P.end());
    int n = P.size(),k = 0;
    Point H[2*n];
    
    for(int i=0;i<n;++i){
        while(k>=2 && area(H[k-2],H[k-1],P[i]) <= 0) --k;
        H[k++] = P[i];
    }
    
    for(int i=n-2,t=k;i>=0;--i){
        while(k>t && area(H[k-2],H[k-1],P[i]) <= 0) --k;
        H[k++] = P[i];
    }
    
    return vector <Point> (H,H+k-1);
}
vector<Point> p,pol;
double f(int pos){
    if(pos > (int)pol.size()) return 0;
    if(p.size() == 4) return area(p);
    double ans = -1;
    p.push_back(Point(pol[pos].x,pol[pos].y));
    ans = max(ans,f(pos+1));
    p.pop_back();
    ans = max(ans,f(pos+1));
    return ans;
}
int main(){
    int n; cin >> n;
    while(n--){
        int x,y; cin >> x >>  y;
        pol.push_back(Point(x,y));
    }
    vector<Point> p = pol;
    pol = convexhull(pol);
    double ans;
    if((int)pol.size() <= 4) ans = area(p);
	cout.precision(6);
	cout << fixed << max(ans,f(0)) << "\n";
    return 0;
}
