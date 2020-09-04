#include <bits/stdc++.h>

using namespace std;
#define PP double

struct Point{
   PP x,y;
   Point(){}
   Point(PP xx,PP yy){x = xx;y = yy;}
   Point orto(){return Point(-y,x);}
   void p(){cout << "::> " << x << " " << y << endl;}
};


Point operator + (const Point &A,const Point &B){return Point(A.x+B.x,A.y+B.y);}
Point operator - (const Point &A,const Point &B){return Point(A.x-B.x,A.y-B.y);}
Point operator * (const Point &A,const Point &B){return Point(A.x*B.x,A.y*B.y);}
Point operator / (const Point &A,double k){return Point(A.x/k,A.y/k);}
Point operator * (const Point &A,double k){return Point(A.x*k,A.y*k);}
bool  operator < (const Point &A,const Point &B){return pair<PP,PP>(A.x,A.y) < pair<PP,PP>(B.x,B.y);}

const double EPS = 0.0;

double cross(Point A,Point B){return A.x*B.y - A.y*B.x;}
double dot(Point A,Point B){return A.x*B.x + A.y*B.y;}
double area2(Point A,Point B,Point C){return cross(B-A,C-A);}//For the triangle A,B,C  using A->B, A->C

bool pointInBox(Point P,Point A,Point B){//Point P inside box A,B
   return P.x >= min(A.x,B.x) and P.x <= max(A.x,B.x) and
          P.y >= min(A.y,B.y) and P.y <= max(A.y,B.y);
}

bool pointOverSegment(Point P,Point A,Point B){//p over AB
   return fabs(area2(A,B,P)) <= EPS and pointInBox(P,A,B);
}

bool pointInPoly(vector<Point> pol,Point p){
   int cont=0,len=pol.size();
   Point act,sig;

   for(int i=0;i<len;i++){
      if (pointOverSegment(p,pol[i],pol[(i+1)%len])) {
          return true; // to include point overSegment uncomment it
      }
      act = pol[i] - p;
      sig = pol[(i+1)%len] - p;//focus on this :v
      if (act.y>sig.y)
         swap(act,sig);
      if (act.y<0 and sig.y>=0 and cross(sig,act)>=0)
         cont++;
   }
   return cont%2==1;
}

vector<Point> v;
int main() {
    int n,d; cin >> n >> d;
    v.push_back(Point(0,d));
    v.push_back(Point(n - d,n));
    v.push_back(Point(n,n - d));
    v.push_back(Point(d,0));
    int q; cin >> q;
    while(q--) {
        int x,y; cin >> x >> y;
        if(pointInPoly(v,Point(x,y)))
            cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}

