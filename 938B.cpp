#include <bits/stdc++.h>

using namespace std;

int v[100010];
int f[100010];
int s[100010];
int main(){
    
    int n; cin >> n;

    for (int i = 0; i < n; ++i) 
        cin >> v[i];
    
    int last = 1;

    for (int i = 0; i < n; ++i) {
        int dif = v[i] - last;
        f[i] = dif;
        if(i) f[i] += f[i - 1];
        last = v[i];
    }
    last = 1000000;
    for (int i = n - 1; i >= 0; --i) {
        int dif = abs(v[i] - last);
        s[i] = dif;
        if(i < n - 1) s[i] += s[i + 1];
        last = v[i];
    }       
    long long ans = LLONG_MAX;

    for (int i = 0; i < n; ++i) {
        long long first = f[i];
        long long second = s[i + 1];
        long long cur = max(first,second);
        ans = min(ans,cur);
    }
    ans = min(ans,(long long)min(s[0],f[n - 1]));
    cout << ans << "\n";
    return 0;
}

