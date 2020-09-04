#include <bits/stdc++.h>

using namespace std;

int v[1000];
int n;
int main(){
    while(scanf("%d",&n) != EOF){
        int total = 0;
        for (int i = 0; i < n; ++i)
            scanf("%d", v + i);
        for (int i = 0; i < n; ++i){
            v[i + n] = v[i];
            total += v[i];
        }
        int ans = 1e9;

        for (int i = 0; i < n; ++i){
            for (int j = i; j < n; ++j){
                int cur = 0;
                for (int k = i; k <= j; ++k){
                    cur += v[k];
                }
                int p = abs(cur - total);
                ans = min(ans,abs(p - cur));
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}

