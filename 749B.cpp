#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

#define Vector Point

const double EPS = 0.00000000001;
struct Point
{
    double x, y;
    Point(){}
    Point(double a, double b) { x = a; y = b; }
    double mod2() { return x*x + y*y; }
    double mod()  { return sqrt(x*x + y*y); }
    double arg()  { return atan2(y, x); }
    Point ort()   { return Point(-y, x); }
    Point unit()  { double k = mod(); return Point(x/k, y/k); }
};

Point operator +(const Point &a, const Point &b) { return Point(a.x + b.x, a.y + b.y); }
Point operator -(const Point &a, const Point &b) { return Point(a.x - b.x, a.y - b.y); }
Point operator /(const Point &a, double k) { return Point(a.x/k, a.y/k); }
Point operator *(const Point &a, double k) { return Point(a.x*k, a.y*k); }

double dist(const Point &A, const Point &B)    { return hypot(A.x - B.x, A.y - B.y); }
double cross(const Vector &A, const Vector &B) { return A.x * B.y - A.y * B.x; }
double dot(const Vector &A, const Vector &B)   { return A.x * B.x + A.y * B.y; }
double area(const Point &A, const Point &B, const Point &C) { return cross(B - A, C - A); }

vector<Point> ans;
int main(){
	ios::sync_with_stdio(false); cin.tie(0);
	Point A,B,C;
	cin >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y;
	Point X = A - B;
	Point Y = C - B;
	Point Z = B+Y+X;
	if(cross(X,Y) > 0.0 or cross(Y,X) > 0.0) ans.push_back(Z);
	X = B-A;
	Y = C-A;
	Z = A+ Y+X;
	if(cross(X,Y) > 0.0 or cross(Y,X) > 0.0) ans.push_back(Z);
	X = A-C;
	Y = B-C;
	Z = C+X+Y;
	if(cross(X,Y) > 0.0 or cross(Y,X) > 0.0) ans.push_back(Z);
	cout <<ans.size() << "\n";
	for (int i = 0; i < (int)ans.size(); ++i) cout << ans[i].x << " " << ans[i].y << "\n";
	return 0;
}
