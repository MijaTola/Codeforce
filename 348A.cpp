#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; cin >> n;
    long long ans = 0;
    long long mx = 0;
    for (int i = 0; i < n; ++i){
        long long x; cin >> x;
        ans += x;
        mx = max(mx,x);
    }
    cout << max(mx,(long long)(ans + n - 2)/ (n - 1)) << "\n";
    return 0;
}

