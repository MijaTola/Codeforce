#include <bits/stdc++.h>

using namespace std;

int a[1010];
int b[1010];
int n,m;

bool ver(long double fuel) {
    
    long double r = m;

    for (int i = 0; i < n; ++i) {
        // take off
        long double total = r + fuel;
        long double toff = a[i];
        long double tones = total / toff;
        fuel -= tones;
        total = r + fuel;
        toff = b[(i + 1) % n];
        tones = total / toff;
        fuel -= tones;
    }
    return fuel >= 0;
}
int main(){
    
    cin >> n >> m;
    
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    for (int i = 0; i < n; ++i)
        cin >> b[i];

    
    long double a = -1;
    long double b = INT_MAX;
    

    for (int i = 0; i < 100; ++i) {
        long double mid = (a + b) / 2.0;
        if(ver(mid)) b = mid;
        else a = mid;
    }
    if(b == INT_MAX) return cout << "-1\n",0;
    cout.precision(10);
    cout << fixed << b << "\n";
    return 0;
}

