#include <bits/stdc++.h>

using namespace std;

long long n,m,k;

bool ver(long long high) {
    high--;
    long long total = ((high - 1) * high) / 2;
    long long l = max(0ll,(high - 1) - (k - 1)); 
    long long r = max(0ll,(high - 1) - (n - k));
    l = (l * (l + 1)) / 2;
    r = (r * (r + 1)) / 2;
    long long left = total - l;
    long long right = total - r;
    return left + right + high <= m;
}

int main(){
    cin >> n >> m >> k;
    if(n == 1) return cout << m << "\n",0;
    m -= n;
    int a = 1, b = m + 1;
    while(b - a > 1) {
        int mid = (a + b) / 2;
        if(ver(mid)) a = mid;
        else b = mid;
    }
    cout << a << "\n";
    return 0;
}

