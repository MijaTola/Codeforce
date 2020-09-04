#include <bits/stdc++.h>

using namespace std;

long long v[2100010];
int main(){
    int n,k;
    cin >> n >> k;
    int weeks = n-k+1;
    for (int i = 1; i <= n; ++i){
        cin >> v[i];
        v[i] += v[i-1];
    }
    
    long long ans = 0;
    for (int i = 1; i <= n-k+1; ++i){
        ans += v[i+k-1]-v[i-1];
    }
    cout.precision(10);
    cout << fixed << (long double)ans/weeks << "\n";
    return 0;
}
