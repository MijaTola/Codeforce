#include <bits/stdc++.h>

using namespace std;

int main(){
    
    double hh,mm;
    cin>> hh >> mm;
    
    double totalmin = hh * 3600 + mm * 60;
    double dis = 20 * 3600;
    double h,d,c,n; cin >> h >> d >> c >> n;
    
    double dif = max(0.0, dis - totalmin);
    dif /= 60;
    double nh = h + d * dif;
    
    double a1 = nh / n;
    if(a1 > (int)a1) a1 = (int)a1 + 1;
    double a2 = h / n;
    if(a2 > (int)a2) a2 = (int)a2 + 1;
    double ans1 = (double)(a1* (c - (c * 0.20)));
    double ans2 = (double) a2 * c;
    cout.precision(6);
    cout<< fixed << min(ans1,ans2) << "\n";
    return 0;
}

