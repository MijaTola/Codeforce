#include <bits/stdc++.h>

using namespace std;

int v[100010];
int b[100010];
int first[100010];
int cnt[100010];
int main(){
    memset(first, -1, sizeof first);
    int n; cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        cnt[v[i]]++;
        if(first[v[i]] == -1) first[v[i]] = i;
    }
        
    set<int> s;

    for (int i = n - 1; i >= 0; i--) {
        s.insert(v[i]);
        b[i] = s.size();
    }

    
    long long ans = 0;
    for (int i = 1; i < 100010; ++i) {
        if(first[i] == -1) continue;
        long long next = b[first[i]];
        if(cnt[i] > 1) ans++;
        ans += (next - 1);
    }

    cout << ans << "\n";
    return 0;
}

