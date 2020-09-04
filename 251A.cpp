#include <bits/stdc++.h>

using namespace std;

int v[100010];
int n,k;

int main(){
    scanf("%d %d", &n, &k);

    for (int i = 0; i < n; ++i)
        scanf("%d", v + i);
    
    long long ans = 0LL;
    int cur = 0;
    for (int i = 0; i < n; ++i){
        while(v[cur] - v[i] < k and cur < n - 1) cur++;
        if(v[cur] - v[i] > k) cur--;
        long long C = cur - i;
        C = (C * (C - 1)) / 2;
        ans += C;
    }
    printf("%lld\n",ans);
    return 0;
}

