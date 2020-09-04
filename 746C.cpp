#include <bits/stdc++.h>

using namespace std;

int s,x1,x2,t1,t2,p,d;
int main() {
    cin >> s >> x1 >> x2 >> t1 >> t2 >> p >> d;
    swap(t1,t2);
    
    if(x1 < x2) {
        if(p <= x1 and d == 1) 
            return cout << min(abs(x1 - x2) * t1,abs(p - x2) * t2) << "\n",0;
        if(d == -1) 
            return cout << min(abs(p + x2) * t2, abs(x1 - x2) * t1) << "\n",0;
        if(p > x1 and d == 1) 
            return cout << min(abs((s - p + s + x2)) * t2, abs(x1 - x2) * t1) << "\n",0;
    } else {
        if(p >= x1 and d == -1) 
            return cout << min(abs(x1 - x2) * t1,abs(p - x2) * t2) << "\n",0;
        if(d == 1) 
            return cout << min(abs((s - p) + abs(s - x2)) * t2, abs(x1 - x2) * t1) << "\n",0;
        if(p < x1 and d == -1) 
            return cout << min(abs(p + s + (s - x2)) * t2, abs(x1 - x2) * t1) << "\n",0;
    }
    return 0;
}
