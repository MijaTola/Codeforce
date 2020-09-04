#include <bits/stdc++.h>

using namespace std;

struct Point {
    double x,y,cx,cy;
    Point(){}
    Point(double _, double __, double ___, double ____){
        x = _, y = __, cx = ___, cy = ____;
    }
};

Point operator -(const Point &a, const Point &b) {
    return Point(a.x - b.x, a.y - b.y,0,0);
}

double cross(const Point &a, const Point &b) {
    return a.x * b.y - a.y * b.x;
}

long long distance(Point &a, Point &b) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}
bool check(Point b, Point a, Point c) {
    long long ab = distance(a,b);
    long long cb = distance(c,b);
    long long ac = distance(a,c);
    return ac == (ab + cb) and ab == cb;
}

bool ver(vector<Point> &pol) {
    set<pair<int,int> > s;
    for (int i = 0; i < 4; ++i) {
        s.insert({pol[i].x, pol[i].y});
        bool flag = 0;
        for (int j = 0; j < 4; ++j) {
            if(i == j) continue;
            for (int k = 0; k < 4; ++k) {
                if(i == k or j == k) continue;
                flag |= check(pol[i], pol[j], pol[k]);   
            }
        }
        if(!flag) return 0;
    }
    if(s.size() != 4) return 0;
    return 1;
}

void print(Point &x) { cout << x.x << " " << x.y << "\n";}

Point rotate(const Point &z) { 
    Point centered = Point(z.x - z.cx, z.y - z.cy, z.cx, z.cy);
    Point rotated = Point(-centered.y, centered.x, centered.cx, centered.cy);
    Point original = Point(rotated.x + rotated.cx, 
            rotated.y + rotated.cy, rotated.cx, rotated.cy);
    return original;
}

Point moves(int n, Point P) {
    for (int i = 0; i < n; ++i) 
        P = rotate(P);
    return P;
}

int main() {
    
    int t;
    scanf("%d", &t);
    while(t--) {
        vector<Point> pol;
        for (int i = 0; i < 4; ++i) {
            int x,y,cx,cy;
            scanf("%d%d%d%d", &x, &y, &cx, &cy);
            pol.push_back(Point(x,y,cx,cy));
        }        
        int ans = 1e9;
        for (int i = 0; i < 4; ++i) 
            for (int j = 0; j < 4; ++j) 
                for (int k = 0; k < 4; ++k) 
                    for (int l = 0; l < 4; ++l) {
                        Point a = moves(i + 1, pol[0]);
                        Point b = moves(j + 1, pol[1]);
                        Point c = moves(k + 1, pol[2]);
                        Point d = moves(l + 1, pol[3]);
                        vector<Point> v;
                        v.push_back(a); v.push_back(b); v.push_back(c); 
                        v.push_back(d);
                        if(ver(v)) {
                            ans = min(ans,(i + 1) % 4 + (j + 1) % 4 + (k + 1) % 4 + (l + 1) % 4);
                        }
                    }

        printf("%d\n", (ans != 1e9) ? ans : -1);
    }
    return 0;
}

