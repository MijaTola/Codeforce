#include <bits/stdc++.h>

using namespace std;

int n,k;
int v[200010];

int main() {
    memset(v, 0,sizeof v);
    scanf("%d%d", &n, &k);
    int mn = 1e9;
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        v[x]++;
        mn = min(mn,x);
    }

    for (int i = 200003; i >= 1; i--) 
        v[i] += v[i + 1];
    
    long long ans = 0;
    long long cnt = 0;
    for (int i = 200004;i > mn; --i) {
        cnt += v[i];
        if(cnt > k) {
            ans++;
            cnt = v[i];
        }
    }
    if(cnt) ans++;
    printf("%lld\n",ans);
    return 0;
}

