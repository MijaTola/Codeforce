#include <bits/stdc++.h>

using namespace std;

long double distance(long double x,long double y, long double a,
        long double b) {
    return sqrt((x - a) * (x - a) + (y - b) * (y - b));
}

long double r,xf,yf,xl,yl;
bool ver(long double x, long double t) {
    return  x + t <= r and -r <= x - t;
}
int main(){
    cin >> r >> xf >> yf >> xl >> yl;

    long double dia = 2 * r;

    long double d = distance(xf,yf,xl,yl);
    xl = 1;
    if(xl < xf) xl = -1;
    long double x = xl;
    long double y = yl;
    long double xx = xf;
    long double yy = yf;
    xf = 0;
    yf = 0;
    yl = 0;
    xl *= d;
    long double db = 0;
    long double ratio = 0;
    if(d > r) {
        db = d - r;
        goto calculated;
    }
    if(xl < 0) {
        long double a = -r;
        long double b = r;
        for (int i = 0; i < 100; ++i) {
            long double mid = (a + b) / 2;
            long double d1 = distance(xf,yf,mid,0);//f
            long double d2 = distance(xl,yl,mid,0); //l
            if(ver(mid,d1) and ver(mid,d2)) a = mid;
            else b = mid;
        }
        db = a;
    }else {
        long double a = -r;
        long double b = r;
        for (int i = 0; i < 100; ++i) {
            long double mid = (a + b) / 2;
            long double d1 = distance(xf,yf,mid,0);//f
            long double d2 = distance(xl,yl,mid,0); //l
            if(ver(mid,d1) and ver(mid,d2)) b = mid;
            else a = mid;
        }
        db = b;
    }
    
    calculated:
    ratio = distance(xl,yl,db,0);
    long double test = distance(xf,yf,db,0);
    long double ttt= abs(ratio - test);
    cout << ttt << " " <<ratio << "\n";
    cout.precision(18);
    cout<<fixed << xx +ttt<< " " << yy + ttt << " " <<   ratio << "\n";
    return 0;
}

