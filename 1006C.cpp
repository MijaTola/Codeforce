#include <bits/stdc++.h>

using namespace std;

int n; 
long long v[200010];

bool ver(long long x, int id) {
    int a = id;
    int b = n;
    while(b - a > 1) {
        int mid = (a + b) / 2;
        long long sum = v[n - 1] - v[mid - 1];
        if(sum >= x) a = mid;
        else b = mid;
    }
    return v[n - 1] - v[a - 1] == x;
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    memset(v,0,sizeof v);
    cin >> n;
    for (int i = 0; i < n; ++i) 
        cin >> v[i];
    
    for (int i = 1; i < n; ++i)
        v[i] += v[i - 1];

    long long ans = 0;
    for (int i = 0; i < n; ++i) 
        if(ver(v[i], i + 1)) ans = v[i];
    
    cout << ans << "\n";
    return 0;
}

