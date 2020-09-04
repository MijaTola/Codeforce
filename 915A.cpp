#include <bits/stdc++.h>

using namespace std;

int n,k;
int main(){
    
    scanf("%d %d", &n, &k);
    
    int ans = 1e9;
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d",&x);
        if(k % x == 0) {
            ans = min(ans,k / x);
        }
    }
    printf("%d\n",ans);
    return 0;
}

