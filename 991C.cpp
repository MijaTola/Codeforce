#include <bits/stdc++.h>

using namespace std;

int main(){
    
    long long n; cin >> n;
    
    long long a = 0;
    long long b = n;

    while(b - a > 1) {
        long long mid = (a + b) / 2;
        long long x = n;
        long long cur = 0;
        while(x >= mid) {
            x -= mid;
            cur += mid;
            x -= x / 10;
        }
        if(cur + x >= (double)n / 2)  b = mid;
        else a = mid;
    }
    cout << b << "\n";
    return 0;
}

