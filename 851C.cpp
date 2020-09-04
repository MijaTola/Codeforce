#include <bits/stdc++.h>

#define EPS 1e-8
const double pi = acos(-1.0);
#define Vector Point

using namespace std;
struct Point {
    vector<double> p;
    Point(){}
    Point(vector<double> P) { p = P; }
};

Point operator -(const Point &a, const Point &b) { 
    vector<double> np;
    for (int i = 0; i < 5; ++i)
        np.push_back(a.p[i] - b.p[i]);
    return Point(np); 
}

double scalar(const Point &a, const Point &b) { 
    double res = 0;

    for (int i = 0; i < 5; ++i) {
        res += a.p[i] * b.p[i];
    }
    return res;
}

double length(const Point &a) { 
    return sqrt(scalar(a, a));
}
double angle(const Point &a, const Point &b) { 
    double A = acos(scalar(a,b) / (length(a) * length(b)));
    return 180 * A / pi;
}

vector<Point> points;
int main() {

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        vector<double> v;
        for (int i = 0; i < 5; ++i) {
            int x;
            cin >> x;
            v.push_back(x);
        }
        points.push_back(Point(v));
    }
    
    vector<int> a;
    for (int i = 0; i < n; ++i) {
        bool flag = 0;
        for (int j = 0; j < n; ++j) {
            for (int k = j + 1; k < n; ++k) {
                if(k == i or k == j or i == j) continue;
                //cout << angle(points[i] - points[j], points[i] - points[k])  << "\n";
                flag |= (angle(points[i] - points[j], points[i] - points[k]) < 90.);
                if(flag) break;
            }
            if(flag) break;
        }

        if(!flag)a.push_back(i);
    }

    cout << a.size() << "\n";
    for (auto x: a)
        cout << x + 1 << "\n";
    return 0;
}

