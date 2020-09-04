#include <bits/stdc++.h>

using namespace std;

long long s,n,k;

int main(){
    cin >> n >> k >> s;

    long long total = (n - 1) * k;
    if(total < s) return cout << "NO\n",0;
    
    long long a = 0, b = k + 1;

    while(b - a > 1) {
        long long mid = (a + b) / 2;
        long long left = k - mid;
        long long cur = mid * (n - 1);
        if(s - cur >= left) a = mid;
        else b = mid;
    }
    return 0;
}

