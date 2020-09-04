#include <bits/stdc++.h>

using namespace std;

#define PP double
struct Point {
    double x,y;
    Point() {}
    Point(int _, int __) {
        x = _;
        y = __;
    }
};
Point operator + (const Point &A,const Point &B){return Point(A.x+B.x,A.y+B.y);}
Point operator - (const Point &A,const Point &B){return Point(A.x-B.x,A.y-B.y);}
Point operator * (const Point &A,const Point &B){return Point(A.x*B.x,A.y*B.y);}
Point operator / (const Point &A,double k){return Point(A.x/k,A.y/k);}
Point operator * (const Point &A,double k){return Point(A.x*k,A.y*k);}
bool  operator < (const Point &A,const Point &B){return pair<PP,PP>(A.x,A.y) < pair<PP,PP>(B.x,B.y);}

const double EPS = 0.0;
double cross(Point A,Point B){return A.x*B.y - A.y*B.x;}
bool pointInBox(Point P,Point A,Point B){//Point P inside box A,B
   return P.x >= min(A.x,B.x) and P.x <= max(A.x,B.x) and
          P.y >= min(A.y,B.y) and P.y <= max(A.y,B.y);
}

double area2(Point A,Point B,Point C){return cross(B-A,C-A);}//For the triangle A,B,C  using A->B, A->C
bool pointOverSegment(Point P,Point A,Point B){//p over AB
   return fabs(area2(A,B,P)) <= EPS and pointInBox(P,A,B);
}


bool pointInPoly(vector<Point> pol,Point p){
   int cont=0,len=pol.size();
   Point act,sig;

   for(int i=0;i<len;i++){
      if (pointOverSegment(p,pol[i],pol[(i+1)%len]))return true; // to include point overSegment uncomment it
      act = pol[i] - p;
      sig = pol[(i+1)%len] - p;//focus on this :v
      if (act.y>sig.y)
         swap(act,sig);
      if (act.y<0 and sig.y>=0 and cross(sig,act)>=0)
         cont++;
   }
   return cont%2==1;
}

bool segmentsIntersect(Point A,Point B,Point C,Point D){//AB, CD
   double A1 = area2(C, D, A);
   double A2 = area2(C, D, B);
   double A3 = area2(A, B, C);
   double A4 = area2(A, B, D);

   if( ((A1 > 0 and A2 < 0) or (A1 < 0 and A2 > 0)) and
       ((A3 > 0 and A4 < 0) or (A3 < 0 and A4 > 0)))
           return true;

   else if(A1 == 0 and pointOverSegment(A, C, D)) return true;
   else if(A2 == 0 and pointOverSegment(B, C, D)) return true;
   else if(A3 == 0 and pointOverSegment(C, A, B)) return true;
   else if(A4 == 0 and pointOverSegment(D, A, B)) return true;
   else return false;
}
vector<Point> a;
vector<Point> b;
int main(){
    
    for (int i = 0; i < 4; ++i) {
        int x,y; cin >> x >> y;
        a.push_back(Point(x,y));
    }
    
    for (int i = 0; i < 4; ++i) {
        int x,y; cin >> x >> y;
        b.push_back(Point(x,y));
    }
    

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            Point pa = a[i];
            Point pb = a[(i + 1) % 4];
            Point pc = b[j];
            Point pd = b[(j + 1) % 4];
            if(segmentsIntersect(pa,pb,pc,pd)) 
                return cout << "YES\n",0;
        }
    }
    
    bool in = true;
    for (int i = 0; i < 4; ++i) {
        if(!pointInPoly(a,b[i])) {
            in = false;
            break;
        }
    }
    if(in) return cout << "YES\n",0;
    in = true;
    for (int i = 0; i < 4; ++i) {
        if(!pointInPoly(b,a[i])) {
            in = false;
            break;
        }
    }
    
    if(in) return cout << "YES\n",0;
    cout << "NO\n";
    return 0;
}

