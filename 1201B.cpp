#include <bits/stdc++.h>
 
using namespace std;
 
int v[100010];
int main() {
    int n;
    cin >> n;
    

    long long sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        sum += v[i];
    }
    
    if(sum & 1) return cout << "NO\n",0;
    sort(v, v + n);
    long long cur = 0;
    for (int i = 0; i < n - 1; ++i) 
        cur += v[i];
    if(cur < v[n - 1]) return cout << "NO\n",0;
    cout << "YES\n";
    return 0;
}
